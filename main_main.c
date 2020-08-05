/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jregenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 17:42:40 by jregenia          #+#    #+#             */
/*   Updated: 2020/08/05 20:38:48 by jregenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	print_err(char *str)
{
	while (*str)
		write(2, str++, 1);
}

int		quit_with_error(void)
{
	print_err("map error\n");
	return (1);
}

int		main(int argc, char **argv)
{
	int	i;

	if (argc == 1)
	{
		if (!print_square_from_stdin())
			return (quit_with_error());
	}
	i = 1;
	while (i < argc)
	{
		if(!print_square(argv[i]))
			return (quit_with_error());
		i++;
		ft_putchar('\n');
	}
	return (0);
}
