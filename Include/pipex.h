/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakin <anakin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 23:19:46 by anakin            #+#    #+#             */
/*   Updated: 2024/11/20 18:57:04 by anakin           ###   ########.fr       */
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
# include "../Libft/libft.h"

#define READ 0
#define WRITE 1

void	error(void);
void    wp_free(char ***str);
void    error_exit(char *msg);
char	*make_path(char *cmd, char **envp);
char	*find_path(char **path_arr, char *cmd);
void	execute(char *argv, char **envp);

#endif