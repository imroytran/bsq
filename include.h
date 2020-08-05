/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jregenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 13:36:49 by jregenia          #+#    #+#             */
/*   Updated: 2020/08/05 20:46:08 by jregenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct			s_param
{
	unsigned int	lines;
	char			c_empty;
	char			c_obst;
	char			c_full;
}						t_param;

char					*ft_strcpy(char *dest, char *src);
char					*ft_strdup(char *src);
unsigned int			ft_strlen(char *str);
char					*ft_strcat(char *dest, char *src);
void					ft_putchar(char c);
char					*load_map(char *filename, t_param **param);
char					**arr1d_2d(char *map, t_param *param,
						unsigned int col);
int						find_coor(unsigned int count, char **map2d,
						t_param *param, unsigned int *inds);
void					print_result(char **map2d, unsigned int *results,
						t_param *param);
int						print_square(char *filename);
int						print_square_from_stdin(void);
unsigned int			check_parameter(char *str, t_param **param,
						unsigned int *i);
int						realloc_str(int i, char **str, char c);
int						realloc_map(unsigned int i, unsigned int *j,
						char **map, char **str);

#endif
