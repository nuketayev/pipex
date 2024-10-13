/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anuketay <anuketay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 20:02:49 by anuketay          #+#    #+#             */
/*   Updated: 2024/06/30 16:04:53 by anuketay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "../libft/libft.h"

void	error(void);
char	*path_to_command(char *cmd, char **envp);
int		get_next_line(char **line);
void	execute(char *argv, char **envp);
int		permissions(char *argv, int i);
void	tutorial(void);

#endif
