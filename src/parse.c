/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polpi <polpi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 19:49:35 by polpi             #+#    #+#             */
/*   Updated: 2023/02/20 07:19:52 by polpi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../libft_fdf/gnl/srcs/get_next_line.h"

/*Forget size x and y*/

int get_mapsize(char **map)
{
    int fd;
    char    *line;

    fd = open(map[1], O_RDONLY);
    // Boucle while pour lire le fichier tant que c'est pas fini
    // split pour separer
    // atoi pour transformer
    line = get_next_line(fd);
    printf("Line -> %s\n", line);
    
    return (1);
}
