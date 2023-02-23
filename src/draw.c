/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <afaucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:55:22 by afaucher          #+#    #+#             */
/*   Updated: 2023/02/23 15:26:20 by afaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_env *env, int x, int y, int color)
{
	char	*pxl;

	pxl = env->img.addr + (y * env->img.line_length + x * (env->img.bits_per_pixel / 8));
	*(unsigned int*)pxl = color;
}

void	init_img_and_window(t_env *env)
{
	env->mlx = mlx_init();
	env->mlx_win = mlx_new_window(env->mlx, 1920, 1080, "FDF");
	env->img.img = mlx_new_image(env->mlx, 1920, 1080);
	env->img.addr = mlx_get_data_addr(env->img.img, &env->img.bits_per_pixel, &env->img.line_length, &env->img.endian);
	my_mlx_pixel_put(env, 1920/2, 1080/2, 0x00FF0000);
	mlx_put_image_to_window(env->mlx, env->mlx_win, env->img.img, 0, 0);
	mlx_loop(env->mlx);
}