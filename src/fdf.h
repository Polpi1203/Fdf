/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <afaucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 09:28:19 by polpi             #+#    #+#             */
/*   Updated: 2023/02/22 14:31:59 by afaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "../libft_fdf/srcs/libft.h"
#include "../libft_fdf/gnl/srcs/get_next_line.h"
#include "../libft_fdf/ft_printf/srcs/ft_printf.h"
#include "../minilibx_macos/mlx.h"
#include <stdlib.h>
#include <stdio.h>




typedef struct s_vector {
    int size_x;
    int size_y;
}   t_vector;

typedef struct s_size_map {
    int w;
    int h;
} t_size_map;

typedef struct s_env{
    t_size_map size_map;
    int **map;
    char    *line;
    char    **map_char;
    
} t_env;

void	get_map(char **av, t_env *env);
void    get_mapsize(char **map, t_env *env);
void    create_int_map(t_env *env);
void	add_number_in_map(t_env *env, char **av);

#endif