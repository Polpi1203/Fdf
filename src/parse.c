/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <afaucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 19:49:35 by polpi             #+#    #+#             */
/*   Updated: 2023/02/22 15:42:25 by afaucher         ###   ########.fr       */
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
		env->size_map.h++;
	}
	while (env->line)
	{
		env->line = get_next_line(fd);
		env->size_map.w++;
	}
	close (fd);
}

void	create_int_map(t_env *env)
{
	int	index;
	int	i;

	i = 0;
	index = env->size_map.h;
	env->map = malloc(sizeof(int*) * env->size_map.h);
	while (i <= index)
	{
		env->map[i] = malloc(sizeof(int) * env->size_map.w);
		i++;
	}
}

void	add_number_in_map(t_env *env, char **av)
{
	int	fd;
	int	j;
	int	i;

	fd = open(av[1], O_RDONLY);
	env->line = get_next_line(fd);
	i = 0;
	while (env->line)
	{
		env->map_char = ft_split(env->line, ' ');
		j = -1;
		while (env->map_char[++j])
			env->map[i][j] = ft_atoi(env->map_char[j]);
		i++;
		env->line = get_next_line(fd);
	}
	free (env->map_char);
	close (fd);
}

void	get_map(char **av, t_env *env)
{
	int	i;
	int	j;
	get_mapsize(av, env);
	create_int_map(env);
	add_number_in_map(env, av);
	i = -1;
	while (++i < 4)
	{
		printf("---------------------------\n");
		j = -1;
		while (++j < 3)
			printf("env->map[i][j] -> %d\n", env->map[i][j]);
	}
}