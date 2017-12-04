/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhovnuv <ozhovnuv@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 12:37:10 by ozhovnuv          #+#    #+#             */
/*   Updated: 2017/03/20 17:39:27 by ozhovnuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	background_fill(t_image *im, unsigned char color)
{
	int x;
	int y;

	y = 0;
	while (y < im->h)
	{
		x = 0;
		while (x < im->w)
		{
			draw_point(im, x, y, color);
			x++;
		}
		y++;
	}
}

void	ft_pix_to_im(t_points p, t_image *im, int x, int y)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	if (im->w > x && im->h > y && x >= 0 && y >= 0)
	{
		r = (p.col & 0xFF);
		g = ((p.col & 0xFF00) >> 8);
		b = ((p.col & 0xFF0000) >> 16);
		im->data[y * im->sizeline + x * 4] = r;
		im->data[y * im->sizeline + x * 4 + 1] = g;
		im->data[y * im->sizeline + x * 4 + 2] = b;
	}
}

void	ft_line(t_image *im, t_points p)
{
	p.dx = abs(p.x - p.x0);
	p.dy = abs(p.y - p.y0);
	p.sx = p.x >= p.x0 ? 1 : -1;
	p.sy = p.y >= p.y0 ? 1 : -1;
	if (p.dy <= p.dx)
		ft_paint_by_x(im, p);
	else
		ft_paint_by_y(im, p);
}

void	ft_paint_by_x(t_image *im, t_points p)
{
	int i;
	int x;
	int y;

	x = p.x0;
	y = p.y0;
	p.d = (p.dy * 2) - p.dx;
	p.d1 = p.dy * 2;
	p.d2 = (p.dy - p.dx) * 2;
	ft_pix_to_im(p, im, x, y);
	x += p.sx;
	i = 1;
	while (i <= p.dx)
	{
		if (p.d > 0)
		{
			p.d += p.d2;
			y += p.sy;
		}
		else
			p.d += p.d1;
		ft_pix_to_im(p, im, x, y);
		i++;
		x += p.sx;
	}
}

void	ft_paint_by_y(t_image *im, t_points p)
{
	int i;
	int x;
	int y;

	x = p.x0;
	y = p.y0;
	p.d = (p.dx * 2) - p.dy;
	p.d1 = p.dx * 2;
	p.d2 = (p.dx - p.dy) * 2;
	ft_pix_to_im(p, im, x, y);
	y += p.sy;
	i = 1;
	while (i <= p.dy)
	{
		if (p.d > 0)
		{
			p.d += p.d2;
			x += p.sx;
		}
		else
			p.d += p.d1;
		ft_pix_to_im(p, im, x, y);
		i++;
		y += p.sy;
	}
}
