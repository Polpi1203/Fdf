/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <afaucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:55:22 by afaucher          #+#    #+#             */
/*   Updated: 2023/02/24 15:37:21 by afaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_img_and_window(t_env *env)
{
	env->mlx = mlx_init();
	env->mlx_win = mlx_new_window(env->mlx, WINDOW_W, WINDOW_H, "FDF");
	env->img.img = mlx_new_image(env->mlx, WINDOW_W, WINDOW_H);
	env->img.addr = mlx_get_data_addr(env->img.img, &env->img.bits_per_pixel, &env->img.line_length, &env->img.endian);
	define_limits(env);
	mlx_put_image_to_window(env->mlx, env->mlx_win, env->img.img, 0, 0);
	mlx_loop(env->mlx);
}

void	my_mlx_pixel_put(t_env *env, int x, int y, int color)
{
	char	*pxl;

	pxl = env->img.addr + (y * env->img.line_length + x * (env->img.bits_per_pixel / 8));
	*(unsigned int*)pxl = color;
}


void	ft_draw_line(t_env *env, int x1, int y1, int x2, int y2, int color)
{
    float step;
    float x;
    float y;
    int i;
    float delta_x;
    float delta_y;
    
    delta_x = x2 - x1;
    delta_y = y2 - y1;
    if (fabsf(delta_x) >= fabsf(delta_y))
        step = fabsf(delta_x);
    else
        step = fabsf(delta_y);
    delta_x = delta_x / step;
    delta_y = delta_y / step;
    x = x1;
    y = y1;
    i = -1;
    while (++i <= step)
    {
        my_mlx_pixel_put(env, x + WINDOW_W / 2 , y + WINDOW_H / 2, color);
        x += delta_x;
        y += delta_y;
    }
}