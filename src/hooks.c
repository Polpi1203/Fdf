/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polpi <polpi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 10:33:31 by polpi             #+#    #+#             */
/*   Updated: 2023/03/02 11:05:41 by polpi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_hooks(t_env *env)
{
	mlx_loop_hook(env->mlx, &handle_no_event, env);
	mlx_key_hook(env->mlx_win, &handle_input, env);
}

void	destroy(t_env *env)
{
	mlx_destroy_window(env->mlx, env->mlx_win);
	mlx_destroy_image(env->mlx, env->img.img);
	free (env->mlx);
}

int	handle_no_event(t_env *env)
{
	(void)env;
	return (0);
}

int handle_input(int keysym, t_env *env)
{
	if (keysym == 53)
		destroy(env);
	return (0);
}