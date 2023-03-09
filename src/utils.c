/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyacoub- <cyacoub-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:48:42 by cyacoub-          #+#    #+#             */
/*   Updated: 2023/03/09 17:50:17 by cyacoub-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * Toma un comando y un entorno, y devuelve la ruta al comando si existe, o 0 si no
 * existe.
 * 
 * @param cmd el comando a ejecutar
 * @param envp Las variables de entorno.
 * 
 * @return El camino al comando.
 */
char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	int		i;
	char	*part_path;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
	return (0);
}

/**
 * Imprime un mensaje de error y sale del programa.
 */
void	error(void)
{
	perror("\033[31mError");
	exit(EXIT_FAILURE);
}

/**
 * Toma un comando y un entorno, encuentra la ruta al comando y lo ejecuta
 * 
 * @param argv los argumentos de la línea de comando
 * @param envp las variables de entorno
 */
void	execute(char *argv, char **envp)
{
	char	**cmd;
	int 	i;
	char	*path;
	
	i = -1;
	cmd = ft_split(argv, ' ');
	path = find_path(cmd[0], envp);
	if (!path)	
	{
		while (cmd[++i])
			free(cmd[i]);
		free(cmd);
		error();
	}
	if (execve(path, cmd, envp) == -1)
		error();
}

/**
 * Lee desde la entrada estándar, un carácter a la vez, hasta que llega a un
 * carácter de nueva línea o al final de la entrada, y luego devuelve la línea
 * leída como una cadena.
 * 
 * @param line Esta es la dirección de un puntero a un carácter que se usará para
 * guardar la línea leída del descriptor de archivo.
 * 
 * @return El número de caracteres leídos.
 */
int	get_next_line(char **line)
{
	char	*buffer;
	int		i;
	int		r;
	char	c;

	i = 0;
	r = 0;
	buffer = (char *)malloc(10000);
	if (!buffer)
		return (-1);
	r = read(0, &c, 1);
	while (r && c != '\n' && c != '\0')
	{
		if (c != '\n' && c != '\0')
			buffer[i] = c;
		i++;
		r = read(0, &c, 1);
	}
	buffer[i] = '\n';
	buffer[++i] = '\0';
	*line = buffer;
	free(buffer);
	return (r);
}
