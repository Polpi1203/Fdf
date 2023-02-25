/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polpi <polpi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 19:49:35 by polpi             #+#    #+#             */
/*   Updated: 2023/02/25 09:26:45 by polpi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*Forget size x and y*/

void	get_mapsize(char **av, t_env *env)
{
	int	fd;
	int	i;

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
	free (env->line);
	close (fd);
}

void	create_int_map(t_env *env)
{
	int	index;
	int	i;

	i = -1;
	index = env->size_map.w;
	env->map = malloc(sizeof(int *) * env->size_map.w);
	while (++i < index)
		env->map[i] = malloc(sizeof(int) * env->size_map.h);
	if (env->map == NULL && env->map[0] == NULL)
		check_error("Malloc error");
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
		if (env->map_char == NULL)
			check_error("Malloc error with Split");
		j = -1;
		while (env->map_char[++j])
			env->map[i][j] = ft_atoi(env->map_char[j]);
		i++;
		env->line = get_next_line(fd);
	}
	free (env->line);
	free (env->map_char);
	close (fd);
}

void	get_map(char **av, t_env *env)
{
	get_mapsize(av, env);
	create_int_map(env);
	add_number_in_map(env, av);
}

/*
int	i;
int	j;
	i = -1;
while (++i < env->size_map.w)
{
	j = -1;
	while (++j < env->size_map.h)
		printf("%d-", env->map[i][j]);
	printf("\n");
}
*/