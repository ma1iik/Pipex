/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misrailo <misrailo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 15:08:47 by misrailo          #+#    #+#             */
/*   Updated: 2022/04/28 15:30:25 by misrailo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "libft/libft.h"
# include <errno.h>

typedef struct s_pipex
{
	int		fd[2];
	int		infile;
	int		outfile;
	pid_t	pid1;
	pid_t	pid2;
	char	*found_path;
	char	**paths;
	char	**cmd_args;
	char	*command;
}				t_pipex;

char	*find_path(char **envp);
char	*command(char **paths, char *cmd);
void	open_files(t_pipex *pipex, int argc, char **argv);
void	free_child(t_pipex *pipex);
void	free_parent(t_pipex *pipex);
void	error_msg(char *message);
void	close_pipe(t_pipex *pipex);
void	child_proccess1(t_pipex pipex, char **argv, char **envp);
void	child_proccess2(t_pipex pipex, char **argv, char **envp);
int		main(int argc, char **argv, char **envp);

#endif