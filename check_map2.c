/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jregenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 13:47:06 by jregenia          #+#    #+#             */
/*   Updated: 2020/08/05 17:07:46 by jregenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int		check_map(char *map, t_param *param)
{
	while (*map)
	{
		if (!(*map == param->c_empty || *map == param->c_obst ||
			*map == param->c_full))
			return (0);
		map++;
	}
	return (1);
}

char	**arr1d_2d(char *map, t_param *param,
		unsigned int col)
{
	unsigned int	i;
	unsigned int	j;
	char			**map2d;

	map2d = malloc(sizeof(char *) * param->lines);
	i = 0;
	while (i < param->lines)
	{
		map2d[i] = malloc(sizeof(char) * col + 1);
		i++;
	}
	i = 0;
	while (i < param->lines)
	{
		j = 0;
		while (j < col)
		{
			map2d[i][j] = map[j + i * col];
			j++;
		}
		map2d[i][j] = '\0';
		i++;
	}
	return (map2d);
}
