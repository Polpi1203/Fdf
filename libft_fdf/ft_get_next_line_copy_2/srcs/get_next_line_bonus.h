/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <afaucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 09:36:43 by afaucher          #+#    #+#             */
/*   Updated: 2022/11/29 09:40:47 by afaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
# endif

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>

int			ft_strlen(const char *str);
char		*ft_strchr(char *str, int c);
char		*ft_strjoin(char const *s1, char const *s2);
char		*get_next_line_bonus(int fd);
char		*ft_fill_stash(int fd, char *stash);
char		*ft_extract_line(char *stash);
char		*ft_new_stash(char *stash);

# endif