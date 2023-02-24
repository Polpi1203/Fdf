/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_to_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <afaucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:43:11 by polpi             #+#    #+#             */
/*   Updated: 2023/02/24 15:48:34 by afaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	convert_int_to_float(t_env *env)
{
	int	i;
	int	y;
	int	x;

	i = 0;
	y = -1;
	env->mapf = malloc(sizeof(env->mapf) * (env->size_map.w * env->size_map.h));
	if (env->mapf == NULL)
		check_error ("Maloc error");
	while (++y < env->size_map.w)
	{
		x = -1;
		while (++x < env->size_map.h)
		{
			env->mapf[i].x = x * cosf(env->angle) + x * cosf (env->angle + 2) \
			+ -env->map[y][x] * cosf (env->angle - 2);
			env->mapf[i].y = y * sinf(env->angle) + x * sinf(env->angle + 2) \
			+ -env->map[y][x] * sinf(env->angle - 2);
			env->mapf[i].x *= -20;
			env->mapf[i].y *= 20; 
			i++;
		}
	}
	i = -1;
	while (++i < (x * y))
		printf("env->mapf[i].x -> %f | env->mapf[i].y -> %f\n", env->mapf[i].x, env->mapf[i].y);
}


