/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyacoub- <cyacoub-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:37:57 by cyacoub-          #+#    #+#             */
/*   Updated: 2023/03/09 17:47:08 by cyacoub-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * Abre el archivo especificado por el primer argumento, duplica el fd
 * para el extremo de escritura de la tubería en la salida estándar,
 * duplica el descriptor de archivo para el archivo abierto en la entrada estándar,
 * cierra el extremo de lectura de la tubería y ejecuta el comando especificado por
 * el segundo argumento.
 * 
 * @param argv Los argumentos pasados al programa.
 * @param envp Las variables de entorno
 * @param fd La matriz de descriptores de archivos que contiene los dos
 * descriptores de archivos devueltos por pipe().
 */
void	child_process(char **argv, char **envp, int *fd)
{
	int		filein;

	filein = open(argv[1], O_RDONLY, 0777);
	if (filein == -1)
		error();
	dup2(fd[1], STDOUT_FILENO);
	dup2(filein, STDIN_FILENO);
	close(fd[0]);
	execute(argv[2], envp);
}

/**
 * Abre el archivo especificado por el usuario, duplica el extremo de lectura de la
 * tubería a la entrada estándar, duplica el descriptor del archivo a la salida
 * estándar, cierra el extremo de escritura de la tubería y ejecuta el comando
 * especificado por el usuario.
 * 
 * @param argv Los argumentos pasados al programa.
 * @param envp Las variables de entorno.
 * @param fd Esta es la matriz de descriptores de archivos que creamos
 * anteriormente.
 */
void	parent_process(char **argv, char **envp, int *fd)
{
	int		fileout;

	fileout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fileout == -1)
		error();
	dup2(fd[0], STDIN_FILENO);
	dup2(fileout, STDOUT_FILENO);
	close(fd[1]);
	execute(argv[3], envp);
}

/**
 * Se bifurca, el proceso secundario ejecuta el primer comando, el proceso
 * principal ejecuta el segundo comando y los dos procesos se comunican a través de
 * una tubería.
 * 
 * @param argc el número de argumentos pasados al programa
 * @param argv argv[0] = "./pipex", argv[1] = "archivo1", argv[2] = "cmd1", argv[3]
 * = "cmd2", argv[4] = "archivo2"
 * @param envp Las variables de entorno.
 * 
 * @return El valor de retorno del último comando ejecutado.
 */
int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid1;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			error();
		pid1 = fork();
		if (pid1 == -1)
			error();
		if (pid1 == 0)
			child_process(argv, envp, fd);
		waitpid(pid1, NULL, 0);
		parent_process(argv, envp, fd);
	}
	else
	{
		ft_putstr_fd("\033[31mError: Bad arguments\n\e[0m", 2);
		ft_putstr_fd("Ex: ./pipex <file1> <cmd1> <cmd2> <file2>\n", 1);
	}
	return (0);
}
