/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limits.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <afaucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 10:07:35 by afaucher          #+#    #+#             */
/*   Updated: 2023/02/25 13:37:26 by afaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	define_limits(t_env *env)
{
	int	i;

	i = 0;
	env->i_y = 0;
	while (++env->i_y <= env->size_map.w)
	{
		env->i_x = 0;
		while (++env->i_x <= env->size_map.h)
		{
			check_limits(env, i);
			i++;
		}
	}
}

void	check_limits(t_env *env, int i)
{
	if (env->i_x < env->size_map.h && env->i_y < env->size_map.w)
	{
		ft_draw_line(env, (t_mapf){env->mapf[i].x, env->mapf[i].y}, \
			(t_mapf){env->mapf[i + 1].x, env->mapf[i + 1].y}, RED);
		ft_draw_line(env, (t_mapf){env->mapf[i].x, env->mapf[i].y}, \
			(t_mapf){env->mapf[i + env->size_map.h].x, \
				env->mapf[i + env->size_map.h].y}, RED);
	}
	else if (env->i_x == env->size_map.h && env->i_y < env->size_map.w)
		ft_draw_line(env, (t_mapf){env->mapf[i].x, env->mapf[i].y}, \
			(t_mapf){env->mapf[i + env->size_map.h].x, \
				env->mapf[i + env->size_map.h].y}, RED);
	else if (env->i_x < env->size_map.h && env->i_y == env->size_map.w)
		ft_draw_line(env, (t_mapf){env->mapf[i].x, env->mapf[i].y}, \
			(t_mapf){env->mapf[i + 1].x, env->mapf[i + 1].y}, RED);
}
