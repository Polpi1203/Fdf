/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <afaucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 09:28:19 by polpi             #+#    #+#             */
/*   Updated: 2023/02/23 15:16:50 by afaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft_fdf/srcs/libft.h"
# include "../libft_fdf/gnl/srcs/get_next_line.h"
# include "../libft_fdf/ft_printf/srcs/ft_printf.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_mapf {
	float	x;
	float	y;
}	t_mapf;

typedef struct s_size_map {
	int	w;
	int	h;
}	t_size_map;


typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_env {
	t_size_map	size_map;
	t_mapf		*mapf;
	t_data		img;
	int			**map;
	char		*line;
	char		**map_char;
	int			angle;
	void		*mlx;
	void		*mlx_win;
}	t_env;

/*Define Struct*/
void	define_struct(t_env *env);

/*Parse*/
void	get_map(char **av, t_env *env);
void	get_mapsize(char **map, t_env *env);
void	create_int_map(t_env *env);
void	add_number_in_map(t_env *env, char **av);

/*int_to_float*/
void	convert_int_to_float(t_env *env);

/*dispay_and_error*/
void	check_error(char *msg);

/*Draw*/
void	init_img_and_window(t_env *env);
void	my_mlx_pixel_put(t_env *env, int x, int y, int color);

#endif