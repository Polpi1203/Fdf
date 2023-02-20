/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polpi <polpi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 09:28:19 by polpi             #+#    #+#             */
/*   Updated: 2023/02/20 07:15:43 by polpi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "../libft_fdf/gnl/srcs/get_next_line.h"
#include "../libft_fdf/ft_printf/srcs/ft_printf.h"
#include "../minilibx_macos/mlx.h"
#include <stdlib.h>
#include <stdio.h>


int get_mapsize(char **map);

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
    
} t_env;

#endif