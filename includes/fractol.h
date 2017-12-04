/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhovnuv <ozhovnuv@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 17:48:26 by ozhovnuv          #+#    #+#             */
/*   Updated: 2017/03/20 19:47:09 by ozhovnuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define GOLD 0xFFAD1F
# define LIGHT_AQUA 0x254EFF
# define SWEET_ORANGE 0xE8720C
# define SPRUCE 0x205C55
# define LIME 0x69FF7F
# define BORDO 0xE87555
# define VIOLET 0xC159E8
# define YELLOW_BLICK 0xF1FF51
# define ERROR_CORRECT_INPUT 10
# include <mlx.h>
# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct		s_image
{
	void			*ini;
	int				h;
	int				w;
	char			*data;
	int				bpp;
	int				sizeline;
	int				en;
}					t_image;

typedef struct		s_ses_win
{
	void			*mlx;
	void			*win;
	int				h;
	int				w;
	t_image			*im;
}					t_ses_win;

typedef struct		s_fractal
{
	char			fract_name;
	double			im_h_st;
	double			im_h_end;
	double			im_w_st;
	double			im_w_end;
	int				iteration;
	int				n_iteration;
	int				infin_n;
	int				change;
	double			a;
	double			b;
	double			aa;
	double			bb;
	double			ca;
	double			cb;
	int				color_st;
	int				color_end;
	unsigned char	r1;
	unsigned char	r2;
	unsigned char	g1;
	unsigned char	g2;
	unsigned char	b1;
	unsigned char	b2;
}					t_fractal;

typedef struct		s_points
{
	int				x0;
	int				y0;
	int				x;
	int				y;
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				d;
	int				d1;
	int				d2;
	unsigned int	col;
	int				alpha;
	int				beta;
}					t_points;

typedef struct		s_inf
{
	t_ses_win		*wi;
	t_fractal		*fr;
	t_points		*p;
}					t_inf;

double				map(double point, int size,
						double im_st_coor, double im_end_coor);
void				ft_mandelbrot(t_image *im, t_fractal *fr);
void				ft_julia(t_image *im, t_fractal *fr);
void				ft_tree(t_inf *all, t_points p,
						double length, double angel);
void				ft_ship(t_image *im, t_fractal *fr);
int					mouse_pos(int x, int y, t_inf *all);
void				pix_to_im(t_fractal *fr, int y, int x, t_image *im);
void				count_cof(t_fractal *fr);
void				mlx_im_create(t_ses_win *wi);
int					key_action(int button, t_inf *all);
int					mouse_action(int button, int x, int y, t_inf *all);
void				zoom(t_inf *all, int x, int y, int button);
void				move_fractal(t_inf *all, int button);
void				original_rebuild(t_inf *all);
void				change_color(t_inf *all, int button);
void				build_julia(t_inf *all);
void				build_mandelbrot(t_inf *all);
void				build_tree(t_inf *all);
void				build_ship(t_inf *all);
void				reboot_fractal(t_inf *all, int button);
void				background_fill(t_image *im, unsigned char color);
void				draw_point(t_image *im, int x, int y, unsigned char color);
void				ft_pix_to_im(t_points p, t_image *im, int x, int y);
void				ft_line(t_image *im, t_points p);
void				ft_paint_by_x(t_image *im, t_points p);
void				ft_paint_by_y(t_image *im, t_points p);
void				build_tree(t_inf *all);
void				choose_fractal(t_inf *all, char **av, int i);
void				ft_error(int error_msg);
void				ft_putstr(char const *s);
int					ft_strcmp(const char *s1, const char *s2);

#endif
