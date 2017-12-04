/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhovnuv <ozhovnuv@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 17:50:28 by ozhovnuv          #+#    #+#             */
/*   Updated: 2017/03/20 17:41:15 by ozhovnuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	calculate(t_fractal *fr, t_image *im, int x, int y)
{
	fr->b = map(y, im->w, fr->im_w_st, fr->im_w_end);
	fr->a = map(x, im->h, fr->im_h_st, fr->im_h_end);
	fr->n_iteration = 0;
	if (fr->fract_name == 'M' || fr->fract_name == 'S')
	{
		fr->ca = fr->a;
		fr->cb = fr->b;
	}
}

void	ft_mandelbrot(t_image *im, t_fractal *fr)
{
	int y;
	int x;

	y = 0;
	while (y < im->w)
	{
		x = 0;
		while (x < im->h)
		{
			calculate(fr, im, x, y);
			while (fr->n_iteration < fr->iteration)
			{
				count_cof(fr);
				if (fr->a * fr->a + fr->b * fr->b > fr->infin_n)
					break ;
				fr->n_iteration++;
			}
			if (fr->n_iteration != fr->iteration)
				pix_to_im(fr, y, x, im);
			x++;
		}
		y++;
	}
}

void	ft_julia(t_image *im, t_fractal *fr)
{
	int y;
	int x;

	y = 0;
	while (y < im->w)
	{
		x = 0;
		while (x < im->h)
		{
			calculate(fr, im, x, y);
			while (fr->n_iteration < fr->iteration)
			{
				count_cof(fr);
				if (fr->a * fr->a + fr->b * fr->b > fr->infin_n)
					break ;
				fr->n_iteration++;
			}
			if (fr->n_iteration != fr->iteration)
				pix_to_im(fr, y, x, im);
			x++;
		}
		y++;
	}
}

void	ft_tree(t_inf *all, t_points p, double length, double angel)
{
	if (length > all->fr->infin_n)
	{
		length *= 0.7;
		p.x0 = p.x;
		p.y0 = p.y;
		p.x = (int)(p.x + length * cos(angel));
		p.y = (int)(p.y - length * sin(angel));
		ft_line(all->wi->im, p);
		ft_tree(all, p, length, angel + M_PI / p.alpha);
		ft_tree(all, p, length, angel - M_PI / p.beta);
	}
}

void	ft_ship(t_image *im, t_fractal *fr)
{
	int y;
	int x;

	y = 0;
	while (y < im->w)
	{
		x = 0;
		while (x < im->h)
		{
			calculate(fr, im, x, y);
			while (fr->n_iteration < fr->iteration)
			{
				count_cof(fr);
				if (fr->a * fr->a + fr->b * fr->b > fr->infin_n)
					break ;
				fr->n_iteration++;
			}
			if (fr->n_iteration != fr->iteration)
				pix_to_im(fr, y, x, im);
			x++;
		}
		y++;
	}
}
