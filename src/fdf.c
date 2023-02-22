/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polpi <polpi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 09:28:22 by polpi             #+#    #+#             */
/*   Updated: 2023/02/22 18:57:06 by polpi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int ac, char **av)
{
    (void)ac;
    t_env env;
    get_map(av, &env);
	convert_int_to_float(&env);
	printf("size_map.w -> %d size_map.h -> %d\n", env.size_map.w, env.size_map.h);
    return(1);
}