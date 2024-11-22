/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakin <anakin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 23:23:40 by anakin            #+#    #+#             */
/*   Updated: 2024/11/22 22:05:05 by anakin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//  __attribute__((destructor))
// static void destructor() {
//     system("leaks -q ./pipex");
//  }
 
void	child_process(char **argv, char **envp, int *fd)
{
	int		filein;

	filein = open(argv[1], O_RDONLY);
	if (filein == -1)
		error();
	dup2(fd[WRITE], STDOUT_FILENO);
	dup2(filein, STDIN_FILENO);
	close(fd[READ]); 
	close(fd[WRITE]);
	execute(argv[2], envp);
}

void	child_process2(char **argv, char **envp, int *fd)
{
	int		fileout;

	fileout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fileout == -1)
		error();
	dup2(fd[READ], STDIN_FILENO);
	dup2(fileout, STDOUT_FILENO);
	close(fd[WRITE]);
	close(fd[READ]); 
	execute(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			error();
		pid1 = fork();
		if (pid1 == -1)
			error();
		if (pid1 == 0)
			child_process(argv, envp, fd);
		pid2 = fork();
		if(pid2 == -1)
			error();
		if(pid2 == 0)
			child_process2(argv, envp, fd);
		waitpid(pid1, NULL, 0);
	}
	else
		error_exit("Error: Bad arguments");
	return (0);
}
