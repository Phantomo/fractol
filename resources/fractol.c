/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhovnuv <ozhovnuv@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 21:02:59 by ozhovnuv          #+#    #+#             */
/*   Updated: 2017/03/20 17:40:47 by ozhovnuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void				draw_point(t_image *im, int x, int y, unsigned char color)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	r = (color & 0xFF);
	g = ((color & 0xFF00) >> 8);
	b = ((color & 0xFF0000) >> 16);
	im->data[y * im->sizeline + x * 4] = r;
	im->data[y * im->sizeline + x * 4 + 1] = g;
	im->data[y * im->sizeline + x * 4 + 2] = b;
}

void				mlx_im_create(t_ses_win *wi)
{
	wi->im = (t_image*)malloc(sizeof(t_image));
	wi->im->w = wi->h;
	wi->im->h = wi->h;
	wi->im->bpp = 32;
	wi->im->sizeline = wi->im->w * 4;
	wi->im->en = 0;
	wi->im->ini = mlx_new_image(wi->mlx, wi->im->w, wi->im->h);
	wi->im->data = mlx_get_data_addr(wi->im->ini, &(wi->im->bpp),
	&(wi->im->sizeline), &(wi->im->en));
}

static t_ses_win	*mlx_win_im_create(void)
{
	t_ses_win *wi;

	wi = (t_ses_win*)malloc(sizeof(t_ses_win));
	wi->h = 800;
	wi->w = 800;
	wi->mlx = mlx_init();
	wi->win = mlx_new_window(wi->mlx, wi->h, wi->w, "FRACTOL");
	mlx_im_create(wi);
	return (wi);
}

int					main(int ac, char **av)
{
	t_inf	*all;
	int		i;

	i = 1;
	while (ac - i >= 2)
	{
		if (fork() == 0)
			break ;
		i++;
	}
	if (ac > 1)
	{
		all = (t_inf*)malloc(sizeof(t_inf));
		all->wi = mlx_win_im_create();
		choose_fractal(all, av, i);
		mlx_put_image_to_window(all->wi->mlx, all->wi->win,
			all->wi->im->ini, 0, 0);
		mlx_hook(all->wi->win, 2, 5, key_action, all);
		mlx_mouse_hook(all->wi->win, mouse_action, all);
		mlx_loop(all->wi->mlx);
	}
	ft_error(ERROR_CORRECT_INPUT);
}
