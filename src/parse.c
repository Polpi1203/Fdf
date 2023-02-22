/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <afaucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 19:49:35 by polpi             #+#    #+#             */
/*   Updated: 2023/02/22 14:33:47 by afaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*Forget size x and y*/

void get_mapsize(char **av, t_env *env)
{
	int fd;
	int i;

	fd = open(av[1], O_RDONLY);
	i = -1;
	env->line = get_next_line(fd);
	env->size_map.h++;
	while (env->line[++i])
	{
		if (env->line[i] == ' ')
		env->size_map.w++;
	}
	env->size_map.w++;
	while (env->line)
	{
		env->line = get_next_line(fd);
		env->size_map.h++;
	}
	printf("Line -> %s\n", env->line);
	printf("sizeW -> %d\n", env->size_map.w);
	printf("sizeH -> %d\n", env->size_map.h);
	close (fd);
}

void	create_int_map(t_env *env)
{
	int	index;

	index = env->size_map.h;
	env->map = malloc(sizeof(int) * env->size_map.w);
	while (index != '\0')
	{
		env->map[index] = malloc(sizeof(int) * env->size_map.h);
		index--;
	}
}

void	add_number_in_map(t_env *env, char **av)
{
	int	fd;
	int	index;
	int	j;
	int	i;

	index = 0;
	fd = open(av[1], O_RDONLY);
	env->line = get_next_line(fd);
	i = 0;
	while (env->line)
	{
		env->map_char = ft_split(env->line, ' ');
		j = -1;
		while (env->map_char[0][++j])
		{
			env->map[i][j] = ft_atoi(env->map_char[0]);
			i++;
		}
		env->line = get_next_line(fd);
	}
	printf("env_map[0][0] -> %d\n", env->map[0][0]);
}

void	get_map(char **av, t_env *env)
{
	get_mapsize(av, env);
	create_int_map(env);
	add_number_in_map(env, av);
}