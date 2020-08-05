/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jregenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 14:24:54 by jregenia          #+#    #+#             */
/*   Updated: 2020/08/05 14:38:04 by jregenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int		check_square(unsigned int i, unsigned int j,
		unsigned int count, char empty, char **map2d)
{
	unsigned int movi;
	unsigned int movj;

	movi = 0;
	while (movi < count)
	{
		movj = 0;
		while (movj < count)
		{
			if (map2d[i + movi][j + movj] != empty)
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
	unsigned int i;
	unsigned int j;

	while (count > 0)
	{
		i = 0;
		while (i + count <= param->lines)
		{
			j = 0;
			while (j + count <= ft_strlen(map2d[0]))
			{
				if (check_square(i, j, count, param->c_empty, map2d))
				{
					inds[0] = i;
					inds[1] = j;
					inds[2] = count;
					return (1);
				}
				j++;
			}
			i++;
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
