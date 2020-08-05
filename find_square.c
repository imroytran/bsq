/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jregenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 14:24:54 by jregenia          #+#    #+#             */
/*   Updated: 2020/08/05 19:41:15 by jregenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int		check_square(unsigned int *id, unsigned int count,
		char empty, char **map2d)
{
	unsigned int movi;
	unsigned int movj;

	movi = 0;
	while (movi < count)
	{
		movj = 0;
		while (movj < count)
		{
			if (map2d[id[0] + movi][id[1] + movj] != empty)
				return (0);
			movj++;
		}
		movi++;
	}
	return (1);
}

int		find_coor(unsigned int count, char **map2d,
		t_param *param, unsigned int *inds)
{
	unsigned int id[2];

	while (count > 0)
	{
		id[0] = 0;
		while (id[0] + count <= param->lines)
		{
			id[1] = 0;
			while (id[1] + count <= ft_strlen(map2d[0]))
			{
				if (check_square(id, count, param->c_empty, map2d))
				{
					inds[0] = id[0];
					inds[1] = id[1];
					inds[2] = count;
					return (1);
				}
				id[1]++;
			}
			id[0]++;
		}
		count--;
	}
	return (0);
}

int		check_print(unsigned int indx, unsigned int indy,
		unsigned int *result)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	while (i < result[2])
	{
		j = 0;
		while (j < result[2])
		{
			if (indx == result[0] + i && indy == result[1] + j)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	print_result(char **map2d, unsigned int *result,
		t_param *param)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	while (i < param->lines)
	{
		j = 0;
		while (j < ft_strlen(map2d[0]))
		{
			if (check_print(i, j, result))
				ft_putchar(param->c_full);
			else
				ft_putchar(map2d[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int		print_square(char *filename)
{
	char			**map2d;
	char			*map;
	t_param			*param;
	unsigned int	result[3];
	unsigned int	count;
	
	map = load_map(filename, &param);
	if (!map)
		return (0);
	count = ft_strlen(map) / param->lines;
	map2d = arr1d_2d(map, param, count);
	free(map);
	count = ft_strlen(map2d[0]);
	if (count > param->lines)
		count = param->lines;
	if (!find_coor(count, map2d, param, result))
	{
		free(map2d);
		return (0);
	}
	print_result(map2d, result, param);
	free(map2d);
	return (1);
}
