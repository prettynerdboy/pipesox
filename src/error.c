/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakin <anakin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 23:54:35 by anakin            #+#    #+#             */
/*   Updated: 2024/11/20 18:41:46 by anakin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void wp_free(char ***str)
{
    int i;

    if (!str || !*str)
        return;
    i = 0;
    while ((*str)[i])
    {
        free((*str)[i]);
        (*str)[i] = NULL;
        i++;
    }
    free(*str);
    *str = NULL;
}

void error_exit(char *msg)
{	
    const char *red = "\033[31m"; 
    const char *reset = "\033[0m"; 
    write(2, red, 5);                
    ft_putendl_fd(msg, 2) ;      
    write(2, reset, 4);
    exit(EXIT_FAILURE);
}