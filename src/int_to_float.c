/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_to_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <afaucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:43:11 by polpi             #+#    #+#             */
/*   Updated: 2023/02/25 13:36:56 by afaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	average(t_env *env)
{
	float	average;
	int		i;
	int		j;

	i = -1;
	average = 0;
	while (++i < env->size_map.w)
	{
		j = -1;
		while (++j < env->size_map.h)
			average += env->map[i][j];
	}
	average /= (j * i);
	return (average);
}

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
			env->mapf[i].x = x * cosf(env->angle) + y * cosf (env->angle + 2) \
			+ env->map[y][x] / average(env) * cosf (env->angle - 2);
			env->mapf[i].y = x * sinf(env->angle) + y * sinf(env->angle + 2) \
			+ env->map[y][x] / average(env) * sinf(env->angle - 2);
			env->mapf[i].x *= 20;
			env->mapf[i].y *= 20;
			i++;
		}
	}
}

/*
i = -1;
while (++i < (x * y))
	printf("env->mapf[i].x -> %f | env->mapf[i].y -> %f\n", env->mapf[i].x, env->mapf[i].y);
*/