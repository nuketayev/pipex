/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anuketay <anuketay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 20:03:40 by anuketay          #+#    #+#             */
/*   Updated: 2024/06/30 16:04:50 by anuketay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	tutorial(void)
{
	ft_putstr_fd("Y0u aRe d0iNg s0methiNg wrOng 0_o\n", 2);
	ft_putstr_fd("Scenario with infile  -> Example:", 1);
	ft_putstr_fd(" ./pipex <file1> <cmd1> <cmd2> <...> <file2>\n", 1);
	ft_putstr_fd("Scenario with Limiter -> Example:", 1);
	ft_putstr_fd(" ./pipex \"here_doc\"<LIMITER> <cmd> <...> <file>\n", 1);
	exit(EXIT_SUCCESS);
}

void	error(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}

int	permissions(char *argv, int s)
{
	int	fl;

	fl = 0;
	if (s == 0)
		fl = open(argv, O_WRONLY | O_CREAT | O_APPEND, 0777);
	else if (s == 1)
		fl = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else if (s == 2)
		fl = open(argv, O_RDONLY, 0777);
	if (fl == -1)
		error();
	return (fl);
}
