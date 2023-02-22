/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_to_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polpi <polpi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:43:11 by polpi             #+#    #+#             */
/*   Updated: 2023/02/22 19:08:55 by polpi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	convert_and_add_number(t_env *env, t_vector *vector)
{

}

void	creat_float_map(t_env *env, t_vector *vector)
{
	int	index;
	int	i;

	i = -1;
	index = env->size_map.w;
	env->map_float = malloc(sizeof(int*) * env->size_map.w);
	while (++i <= index)
		env->map_float[i] = malloc(sizeof(vector) * env->size_map.h);

}

void    convert_int_to_float(t_env *env)
{
	t_vector	vector;
	creat_float_map(env, &vector);
	convert_and_add_number(env, &vector);
}

