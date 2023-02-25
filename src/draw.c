/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <afaucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:55:22 by afaucher          #+#    #+#             */
/*   Updated: 2023/02/25 13:39:53 by afaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_img_and_window(t_env *env)
{
	env->mlx = mlx_init();
	env->mlx_win = mlx_new_window(env->mlx, WINDOW_W, WINDOW_H, "FDF");
	env->img.img = mlx_new_image(env->mlx, WINDOW_W * 2, WINDOW_H * 2);
	env->img.addr = mlx_get_data_addr(env->img.img, &env->img.bits_per_pixel, \
					&env->img.line_length, &env->img.endian);
	define_limits(env);
	mlx_put_image_to_window(env->mlx, env->mlx_win, env->img.img, 0, 0);
	mlx_loop(env->mlx);
}

void	my_mlx_pixel_put(t_env *env, int x, int y, int color)
{
	char	*pxl;
	if (x >= 0 && x < WINDOW_W && y >= 0 && y < WINDOW_H)
	{
		pxl = env->img.addr + (y * env->img.line_length + x * \
				(env->img.bits_per_pixel / 8));
		*(unsigned int *)pxl = color;
	}
}

void	ft_draw_line(t_env *env, t_mapf vector0, t_mapf vector1, int color)
{
	(void)color;
	float	step;
	float	x;
	float	y;
	int		i;

	env->delta_x = vector1.x - vector0.x;
	env->delta_y = vector1.y - vector0.y;
	if (fabsf(env->delta_x) >= fabsf(env->delta_y))
		step = fabsf(env->delta_x);
	else
		step = fabsf(env->delta_y);
	env->delta_x /= step;
	env->delta_y /= step;
	x = vector0.x;
	y = vector0.y;
	i = -1;
	while (++i <= step)
	{
		my_mlx_pixel_put(env, x + WINDOW_W / 2, y + WINDOW_H / 2, 0x0000FF00);
		x += env->delta_x;
		y += env->delta_y;
	}
}
