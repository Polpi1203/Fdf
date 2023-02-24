/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <afaucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 09:28:22 by polpi             #+#    #+#             */
/*   Updated: 2023/02/24 15:52:07 by afaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	define_struct(t_env *env)
{
	env->angle = 20;
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
	init_img_and_window(&env);
	return (1);
}
