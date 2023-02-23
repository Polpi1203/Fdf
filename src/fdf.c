/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polpi <polpi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 09:28:22 by polpi             #+#    #+#             */
/*   Updated: 2023/02/23 13:47:52 by polpi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	define_struct(t_env *env)
{
	env->angle = 120;
	env->size_map.w = 0;
	env->size_map.h = 0;
}

int	main(int ac, char **av)
{
	t_env	env;

	if (ac != 2)
		return (0);
	define_struct(&env);
	get_map(av, &env);
	printf("value H -> %d | Value W -> %d\n", env.size_map.h, env.size_map.w);
	convert_int_to_float (&env);
	return (1);
}
