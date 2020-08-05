/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jregenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 11:50:48 by jregenia          #+#    #+#             */
/*   Updated: 2020/08/05 15:08:10 by jregenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int		check_parameter(char *str, t_param **param, unsigned int *i,
		unsigned int *j, unsigned int *lines)
{
	int				count;
	t_param			*temp;

	*lines = 0;
	count = 0;
	temp = malloc(sizeof(t_param));
	while (*str && (*str == ' ' || *str =='\t'))
		str++;
	while (*str && *str >= '0' && *str <= '9')
		*lines = *lines * 10 + (*str++ - '0');
	temp->lines = *lines;
	while (str[count] != '\0' && str[count] >= 32 && str[count] < 127)
		count++;
	if (count != 3)
		return (0);
	temp->c_empty = str[ft_strlen(str) - 3];
	temp->c_obst = str[ft_strlen(str) - 2];
	temp->c_full = str[ft_strlen(str) - 1];
	if (temp->c_full == temp->c_obst || temp->c_full == temp->c_empty ||
		temp->c_obst == temp->c_empty)
		return (0);
	*param = temp;
	*i = 1;
	*j = 0;
	return (1);
}

int		realloc_str(int i, char **str, char c)
{
	char *tmp;

	tmp = malloc(sizeof(char) * i + 1);
	if (!tmp)
		return (0);
	ft_strcpy(tmp, *str);
	tmp[i] = c;
	tmp[i + 1] = '\0';
	*str = tmp;
	return (1);
}

int		realloc_map(unsigned int i, unsigned int *j,
		char **map, char **str)
{
	char	*temp;

	if (*map)
		if(ft_strlen(*str) * (i - 1) != ft_strlen(*map))
			return (0);
	temp = malloc(sizeof(char) * i * (*j) + 1);
	if (temp == NULL)
		return (0);
	ft_strcpy(temp, *map);
	ft_strcat(temp, *str);
	free(*map);
	free(*str);
	*str = NULL;
	*map = temp;
	*j = 0;
	return (1);
}

char	*str_to_map(int fd, char *map, t_param **param)
{
	char			*str;
	char			c;
	unsigned int	i;
	unsigned int	j;
	unsigned int	lines;

	i = 0;
	j = 0;
	str = NULL;
	while (read(fd, &c, 1))
		if (i == 0 && (c == '\n' || c == '\r'))
		{
			if(!check_parameter(str, param, &i, &j, &lines))
					return (NULL);
		}
		else if (i != 0 && (c == '\n' || c == '\r'))
		{
			if(str)
				if (!realloc_map(i++, &j, &map, &str))
					return (NULL);
		}
		else if (!realloc_str(j++, &str, c))
			return (NULL);
	if (lines != i - 1)
		return (NULL);
	return (map);
}

char	*load_map(char *filename, t_param **param)
{
	int		fd;
	char 	*map;

	map = NULL;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	else
		map = str_to_map(fd, map, param);
	return (map);
}
