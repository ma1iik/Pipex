/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misrailo <misrailo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:32:46 by misrailo          #+#    #+#             */
/*   Updated: 2022/04/28 15:36:06 by misrailo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*command(char **paths, char *cmd)
{
	char	*tmp;
	char	*command;

	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		command = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(command, X_OK) == 0)
			return (command);
		free(command);
		paths++;
	}
	return (NULL);
}

void	error_msg(char *message)
{
	perror(message);
	exit(EXIT_FAILURE);
}

void	close_pipe(t_pipex *pipex)
{
	close(pipex->fd[0]);
	close(pipex->fd[1]);
}

void	child_proccess1(t_pipex pipex, char **argv, char **envp)
{
	dup2(pipex.fd[1], 1);
	close(pipex.fd[0]);
	dup2(pipex.infile, 0);
	pipex.cmd_args = ft_split(argv[2], ' ');
	pipex.command = command(pipex.paths, pipex.cmd_args[0]);
	if (!pipex.command)
	{
		error_msg("no command in child1");
		free_child(&pipex);
	}
	execve(pipex.command, pipex.cmd_args, envp);
}

void	child_proccess2(t_pipex pipex, char **argv, char **envp)
{
	dup2(pipex.fd[0], 0);
	close(pipex.fd[1]);
	dup2(pipex.outfile, 1);
	pipex.cmd_args = ft_split(argv[3], ' ');
	pipex.command = command(pipex.paths, pipex.cmd_args[0]);
	if (!pipex.command)
	{
		error_msg("no command in child2");
		free_child(&pipex);
	}
	execve(pipex.command, pipex.cmd_args, envp);
}
