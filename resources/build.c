/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhovnuv <ozhovnuv@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 14:48:12 by ozhovnuv          #+#    #+#             */
/*   Updated: 2017/03/20 16:47:33 by ozhovnuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	build_mandelbrot(t_inf *all)
{
	all->fr = (t_fractal*)malloc(sizeof(t_fractal));
	all->fr->iteration = 55;
	all->fr->infin_n = 4;
	all->fr->im_h_st = -2.5;
	all->fr->im_h_end = 1.5;
	all->fr->im_w_st = -2;
	all->fr->im_w_end = 2;
	all->fr->change = -1;
	all->fr->fract_name = 'M';
	all->fr->color_st = SWEET_ORANGE;
	all->fr->color_end = LIGHT_AQUA;
	ft_mandelbrot(all->wi->im, all->fr);
}

void	build_ship(t_inf *all)
{
	all->fr = (t_fractal*)malloc(sizeof(t_fractal));
	all->fr->iteration = 55;
	all->fr->infin_n = 4;
	all->fr->im_h_st = -2.5;
	all->fr->im_h_end = 1.5;
	all->fr->im_w_st = -2;
	all->fr->im_w_end = 1.5;
	all->fr->change = -1;
	all->fr->fract_name = 'S';
	all->fr->color_st = SWEET_ORANGE;
	all->fr->color_end = LIGHT_AQUA;
	ft_ship(all->wi->im, all->fr);
}

void	build_tree(t_inf *all)
{
	all->p = (t_points*)malloc(sizeof(t_points));
	all->p->alpha = 4;
	all->p->beta = 4;
	all->fr = (t_fractal*)malloc(sizeof(t_fractal));
	all->fr->iteration = 250;
	all->fr->infin_n = 1;
	all->fr->change = -1;
	all->fr->fract_name = 'T';
	all->fr->color_st = SWEET_ORANGE;
	all->fr->color_end = LIGHT_AQUA;
	all->p->col = all->fr->color_st;
	all->fr->ca = M_PI / 2;
	background_fill(all->wi->im, all->fr->color_end);
	all->p->x = all->wi->im->w / 2;
	all->p->y = all->wi->im->h;
	ft_tree(all, *all->p, all->fr->iteration, all->fr->ca);
}

void	build_julia(t_inf *all)
{
	all->fr = (t_fractal*)malloc(sizeof(t_fractal));
	all->fr->iteration = 55;
	all->fr->infin_n = 4;
	all->fr->im_h_st = -2.5;
	all->fr->im_h_end = 2.5;
	all->fr->im_w_st = -2;
	all->fr->im_w_end = 2;
	all->fr->change = 1;
	all->fr->fract_name = 'J';
	all->fr->color_st = SWEET_ORANGE;
	all->fr->color_end = LIGHT_AQUA;
	all->fr->ca = -0.4;
	all->fr->cb = 0.6;
	ft_julia(all->wi->im, all->fr);
}
