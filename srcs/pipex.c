/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anuketay <anuketay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 20:03:22 by anuketay          #+#    #+#             */
/*   Updated: 2024/06/30 16:04:49 by anuketay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	child_process(char *argv, char **envp)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		error();
	pid = fork();
	if (pid == -1)
		error();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		execute(argv, envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

void	limiter(char *limiter, int argc)
{
	pid_t	reader;
	int		fd[2];
	char	*line;

	if (argc < 6)
		tutorial();
	if (pipe(fd) == -1)
		error();
	reader = fork();
	if (reader == 0)
	{
		close(fd[0]);
		while (get_next_line(&line))
		{
			if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
				exit(EXIT_SUCCESS);
			write(fd[1], line, ft_strlen(line));
		}
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		wait(NULL);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	infile;
	int	outfile;
	int	s_arg;

	if (argc < 5)
		tutorial();
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
	{
		s_arg = 3;
		outfile = permissions(argv[argc - 1], 0);
		limiter(argv[2], argc);
	}
	else
	{
		s_arg = 2;
		outfile = permissions(argv[argc - 1], 1);
		infile = permissions(argv[1], 2);
		dup2(infile, STDIN_FILENO);
	}
	while (s_arg < argc - 2)
		child_process(argv[s_arg++], envp);
	dup2(outfile, STDOUT_FILENO);
	execute(argv[argc - 2], envp);
	return (0);
}
