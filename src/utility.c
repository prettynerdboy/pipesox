/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakin <anakin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 23:33:50 by anakin            #+#    #+#             */
/*   Updated: 2024/11/20 19:25:54 by anakin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char **path_arr, char *cmd)
{
	char	*part_path;
	char	*path;
	int		i;

	i = 0;
	while (path_arr[i])
	{
		part_path = ft_strjoin(path_arr[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	return (NULL);
}

char	*make_path(char *cmd, char **envp)
{
	char	**path_arr;
	char	*path;
	int		i;

	i = 0;
	if (!envp || !cmd)
        return (NULL);
	if (cmd[0] == '/')
			return (ft_strdup(cmd));
    while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	if (!envp[i])
			return (NULL);
	path_arr = ft_split(envp[i] + 5, ':');
    path = find_path(path_arr, cmd);
	wp_free(&path_arr);
	return (path);
}


void	error(void)
{
	perror("\033[31mError");
	exit(EXIT_FAILURE);
}

void	execute(char *argv, char **envp)
{
	char	**cmd;
	char	*path;
	
	if (!argv || argv[0] == '\0')
        error_exit("Error: Command not found");
	cmd = ft_split(argv, ' ');
	//nullチェック
	path = make_path(cmd[0], envp);
	if (!path)	
	{
		wp_free(&cmd);
        error_exit("Error: Command not found");
	}
	if (execve(path, cmd, envp) == -1)
	{
    	free(path);
    	wp_free(&cmd);
        error_exit("execve failed");
	}
}
