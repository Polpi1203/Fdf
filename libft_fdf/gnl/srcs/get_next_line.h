/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <afaucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:42:38 by polpi             #+#    #+#             */
/*   Updated: 2023/02/22 14:29:20 by afaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
# endif

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>

int			ft_strlen_gnl(const char *str);
char		*ft_strchr_gnl(char *str, int c);
char		*ft_strjoin_gnl(char const *s1, char const *s2);
char		*get_next_line(int fd);
char		*ft_fill_stash(int fd, char *stash);
char		*ft_extract_line(char *stash);
char		*ft_new_stash(char *stash);

# endif