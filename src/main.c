/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyacoub- <cyacoub-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:28:08 by cyacoub-          #+#    #+#             */
/*   Updated: 2023/03/12 18:38:09 by cyacoub-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**find_path(t_var var)
{
	char	*full_path_variable;
	char	**path_options;
	int		i;

	i = 0;
	while (var.envp[i] != NULL)
	{
		if (ft_strnstr(var.envp[i], "PATH=", 5))
			break ;
		i++;
	}
	if (var.envp[i] == NULL)
		return (NULL);
	full_path_variable = ft_substr(var.envp[i], 5, ft_strlen(var.envp[i]) - 5);
	path_options = ft_split(full_path_variable, ':');
	free(full_path_variable);
	i = 0;
	while (path_options[i] != NULL)
	{
		path_options[i] = ft_strlastchr(path_options[i], '/');
		i++;
	}
	return (path_options);
}

int	main(int argc, char **argv, char **envp)
{
	t_var	var;

	if (argc < 5)
	{
		ft_putstr_fd(RED, STDERR_FILENO);
		ft_putendl_fd("Error: invalid number of arguments", STDERR_FILENO);
		ft_putstr_fd(RESET, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	var.argc = argc;
	var.last_command = argc - 2;
	var.envp = envp;
	var.fd_heredoc = -1;
	var.path_options = find_path(var);
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
		var.fd_heredoc = manage_heredoc(var, argv);
	var.inputfile_error = manage_inputfile(var, argv);
	manage_outputfile(var, argv);
	pipex(var, argv);
	return (0);
}