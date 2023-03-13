/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyacoub- <cyacoub-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:26:56 by cyacoub-          #+#    #+#             */
/*   Updated: 2023/03/12 18:06:07 by cyacoub-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	handle_errors(int exitcode)
{
	unlink("heredoc");
	if (errno)
		perror(RED"Error message"RESET);
	exit(exitcode);
}

void	command_not_found(char *invalid_command, char zsh_or_pipex)
{
	unlink("heredoc");
	if (zsh_or_pipex == 'z')
	{
		ft_putstr_fd(RED"zsh: command not found: "RESET, STDERR_FILENO);
		ft_putstr_fd(RED, STDERR_FILENO);
		ft_putendl_fd(invalid_command, STDERR_FILENO);
		ft_putstr_fd(RESET, STDERR_FILENO);
	}
	else if (zsh_or_pipex == 'p')
	{
		ft_putstr_fd(RED, STDERR_FILENO);
		ft_putstr_fd(invalid_command, STDERR_FILENO);
		ft_putstr_fd(RESET, STDERR_FILENO);
		ft_putendl_fd(RED": command not found"RESET, STDERR_FILENO);
	}
	exit (127);
}