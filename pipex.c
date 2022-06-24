/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misrailo <misrailo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 15:17:24 by misrailo          #+#    #+#             */
/*   Updated: 2022/04/28 15:31:12 by misrailo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

void	open_files(t_pipex *pipex, int argc, char **argv)
{
	pipex->infile = open(argv[1], O_RDONLY);
	if (pipex->infile == -1)
		error_msg("Infile error:");
	pipex->outfile = open(argv[argc - 1], O_RDWR | O_TRUNC | O_CREAT, 0666);
	if (pipex->outfile == -1)
		error_msg("Outfile error:");
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex		pipex;

	if (argc != 5)
		error_msg("Wrong Arguments number");
	open_files(&pipex, argc, argv);
	if (pipe(pipex.fd) == -1)
		perror("error is:");
	pipex.found_path = find_path(envp);
	pipex.paths = ft_split(pipex.found_path, ':');
	pipex.pid1 = fork();
	if (pipex.pid1 < 0)
		error_msg("Error in fork1");
	if (pipex.pid1 == 0)
		child_proccess1(pipex, argv, envp);
	pipex.pid2 = fork();
	if (pipex.pid2 < 0)
		error_msg("Error in fork2");
	if (pipex.pid2 == 0)
		child_proccess2(pipex, argv, envp);
	close_pipe(&pipex);
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
	free_parent(&pipex);
	return (0);
}
