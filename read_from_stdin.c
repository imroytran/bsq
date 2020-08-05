/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_from_stdin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jregenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 17:23:51 by jregenia          #+#    #+#             */
/*   Updated: 2020/08/05 20:46:21 by jregenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

char	*read_from_stdin(char *map, t_param **param)
{
	char			*str;
	char			c;
	unsigned int	i;
	unsigned int	j;
	unsigned int	lines;

	i = 0;
	j = 0;
	str = NULL;
	while (read(0, &c, 1))
		if (i == 0 && (c == '\n' || c == '\r'))
		{
			lines = check_parameter(str, param, &i);
			j = 0;
		}
		else if (i != 0 && (c == '\n' || c == '\r'))
		{
			if (str)
				if (!realloc_map(i++, &j, &map, &str))
					return (NULL);
		}
		else if (!realloc_str(j++, &str, c))
			return (NULL);
	if (lines != i - 1 || lines == 0)
		return (NULL);
	return (map);
}

int		print_square_from_stdin(void)
{
	char			**map2d;
	char			*map;
	t_param			*param;
	unsigned int	result[3];
	unsigned int	count;
	
	map = NULL;	
	map = read_from_stdin(map, &param);
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
