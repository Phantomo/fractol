/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redraw.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhovnuv <ozhovnuv@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 14:10:47 by ozhovnuv          #+#    #+#             */
/*   Updated: 2017/03/20 17:42:46 by ozhovnuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	move_fractal(t_inf *all, int button)
{
	if (button == 124)
	{
		all->fr->im_h_st += 0.05;
		all->fr->im_h_end += 0.05;
	}
	else if (button == 123)
	{
		all->fr->im_h_st -= 0.05;
		all->fr->im_h_end -= 0.05;
	}
	else if (button == 125)
	{
		all->fr->im_w_st += 0.05;
		all->fr->im_w_end += 0.05;
	}
	else if (button == 126)
	{
		all->fr->im_w_st -= 0.05;
		all->fr->im_w_end -= 0.05;
	}
	reboot_fractal(all, button);
}

void	original_rebuild(t_inf *all)
{
	mlx_destroy_image(all->wi->mlx, all->wi->im->ini);
	mlx_im_create(all->wi);
	if (all->fr->fract_name == 'M')
		build_mandelbrot(all);
	else if (all->fr->fract_name == 'J')
		build_julia(all);
	else if (all->fr->fract_name == 'T')
		build_tree(all);
	else if (all->fr->fract_name == 'S')
		build_ship(all);
	mlx_put_image_to_window(all->wi->mlx, all->wi->win, all->wi->im->ini, 0, 0);
}

void	change_color(t_inf *all, int button)
{
	if (button == 18)
		all->fr->color_st = GOLD;
	else if (button == 19)
		all->fr->color_st = SPRUCE;
	else if (button == 20)
		all->fr->color_st = LIME;
	else if (button == 21)
		all->fr->color_st = BORDO;
	else if (button == 22)
		all->fr->color_st = VIOLET;
	else if (button == 23)
		all->fr->color_st = YELLOW_BLICK;
	reboot_fractal(all, 0);
}

void	reboot_fractal(t_inf *all, int button)
{
	mlx_destroy_image(all->wi->mlx, all->wi->im->ini);
	mlx_im_create(all->wi);
	if (all->fr->fract_name == 'M')
		ft_mandelbrot(all->wi->im, all->fr);
	else if (all->fr->fract_name == 'J')
		ft_julia(all->wi->im, all->fr);
	else if (all->fr->fract_name == 'S')
		ft_ship(all->wi->im, all->fr);
	else if (all->fr->fract_name == 'T')
	{
		if (button == 126)
			all->p->y -= 10;
		else if (button == 125)
			all->p->y += 10;
		else if (button == 124)
			all->p->x += 10;
		else if (button == 123)
			all->p->x -= 10;
		all->p->col = all->fr->color_st;
		background_fill(all->wi->im, all->fr->color_end);
		ft_tree(all, *all->p, all->fr->iteration, all->fr->ca);
	}
	mlx_put_image_to_window(all->wi->mlx, all->wi->win, all->wi->im->ini, 0, 0);
}

int		mouse_pos(int x, int y, t_inf *all)
{
	if (y <= all->wi->h && x <= all->wi->w &&
		x >= 0 && y >= 0 && all->fr->change != -1)
	{
		if (all->fr->fract_name == 'N' || all->fr->fract_name == 'J')
		{
			all->fr->cb = map(y, all->wi->w, all->fr->im_w_st,
				all->fr->im_w_end);
			all->fr->ca = map(x, all->wi->h, all->fr->im_h_st,
				all->fr->im_h_end);
		}
		else if (all->fr->fract_name == 'T')
		{
			all->p->alpha = map(x, all->wi->w, 1, 10);
			all->p->beta = map(y, all->wi->h, 1, 10);
		}
		reboot_fractal(all, 0);
	}
	return (0);
}
