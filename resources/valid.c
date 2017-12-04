/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhovnuv <ozhovnuv@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 15:14:06 by ozhovnuv          #+#    #+#             */
/*   Updated: 2017/03/20 17:52:00 by ozhovnuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	count_cof(t_fractal *fr)
{
	fr->aa = fr->a * fr->a - fr->b * fr->b;
	if (fr->fract_name == 'S')
		fr->bb = 2 * fabs(fr->a * fr->b);
	else
		fr->bb = 2 * fr->a * fr->b;
	fr->a = fr->aa + fr->ca;
	fr->b = fr->bb + fr->cb;
}

void	ft_putstr(char const *s)
{
	int i;

	i = 0;
	if (s != NULL)
		while (s[i])
			write(1, &s[i++], 1);
}

void	ft_error(int error_msg)
{
	if (error_msg == 10)
	{
		ft_putstr("fractol usage : \n\tM : Mandelbrot\n");
		ft_putstr("\tJ : Julia\n\tS : Ship\n\tT : Tree\n");
	}
	exit(0);
}

int		ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

void	choose_fractal(t_inf *all, char **av, int i)
{
	if (ft_strcmp(av[i], "M") == 0 || ft_strcmp(av[i], "Mandelbrot") == 0)
		build_mandelbrot(all);
	else if (ft_strcmp(av[i], "J") == 0 || ft_strcmp(av[i], "Julia") == 0)
		build_julia(all);
	else if (ft_strcmp(av[i], "T") == 0 || ft_strcmp(av[i], "Tree") == 0)
		build_tree(all);
	else if (ft_strcmp(av[i], "S") == 0 || ft_strcmp(av[i], "Ship") == 0)
		build_ship(all);
	else
		ft_error(ERROR_CORRECT_INPUT);
}
