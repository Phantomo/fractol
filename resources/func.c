/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhovnuv <ozhovnuv@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 16:55:40 by ozhovnuv          #+#    #+#             */
/*   Updated: 2017/03/20 17:41:25 by ozhovnuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	pix_to_im(t_fractal *fr, int y, int x, t_image *im)
{
	int r;
	int b;
	int g;

	fr->r1 = (fr->color_st & 0xFF);
	fr->g1 = ((fr->color_st & 0xFF00) >> 8);
	fr->b1 = ((fr->color_st & 0xFF0000) >> 16);
	fr->r2 = (fr->color_end & 0xFF);
	fr->g2 = ((fr->color_end & 0xFF00) >> 8);
	fr->b2 = ((fr->color_end & 0xFF0000) >> 16);
	r = ((double)(fr->r2 - fr->r1) / fr->iteration) * fr->n_iteration;
	b = ((double)(fr->b2 - fr->b1) / fr->iteration) * fr->n_iteration;
	g = ((double)(fr->g2 - fr->g1) / fr->iteration) * fr->n_iteration;
	im->data[y * im->sizeline + x * 4] = (unsigned char)(fr->r1 + r + 2);
	im->data[y * im->sizeline + x * 4 + 1] = (unsigned char)(fr->g1 + g + 2);
	im->data[y * im->sizeline + x * 4 + 2] = (unsigned char)(fr->b1 + b + 2);
}

int		key_action(int button, t_inf *all)
{
	if (button == 69)
	{
		all->fr->iteration += 5;
		reboot_fractal(all, 0);
	}
	else if (button == 78 && all->fr->iteration > 5)
	{
		all->fr->iteration -= 5;
		reboot_fractal(all, 0);
	}
	else if (button > 17 && button < 24)
		change_color(all, button);
	else if (button > 122 && button < 127)
		move_fractal(all, button);
	else if (button == 53)
		exit(0);
	else if (button == 49)
		original_rebuild(all);
	return (0);
}

int		mouse_action(int button, int x, int y, t_inf *all)
{
	if (y <= all->wi->h && x <= all->wi->w && x >= 0 && y >= 0)
	{
		if (button == 1)
		{
			if (all->fr->change == 1)
			{
				mlx_hook(all->wi->win, 6, 0, mouse_pos, all);
				all->fr->change = -1;
			}
			else
				all->fr->change = 1;
		}
		if (button == 4 || button == 5)
			zoom(all, x, y, button);
	}
	return (0);
}

void	zoom(t_inf *all, int x, int y, int button)
{
	double	scale;
	double	x_c;
	double	y_c;

	y_c = map(y, all->wi->im->w, all->fr->im_w_st, all->fr->im_w_end);
	x_c = map(x, all->wi->im->h, all->fr->im_h_st, all->fr->im_h_end);
	scale = button == 4 ? 0.9 : 1.1;
	all->fr->im_w_st = (all->fr->im_w_st * scale) + y_c * (1 - scale);
	all->fr->im_w_end = (all->fr->im_w_end * scale) + y_c * (1 - scale);
	all->fr->im_h_st = (all->fr->im_h_st * scale) + x_c * (1 - scale);
	all->fr->im_h_end = (all->fr->im_h_end * scale) + x_c * (1 - scale);
	reboot_fractal(all, 0);
}

double	map(double point, int size, double im_st_coor, double im_end_coor)
{
	double res;

	res = im_st_coor + ((fabs(im_st_coor - im_end_coor)) / size) * point;
	return (res);
}
