/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 14:18:56 by idemchen          #+#    #+#             */
/*   Updated: 2017/03/31 03:44:48 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./libft/get_next_line/get_next_line.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "mlx.h"
# include <math.h>
# define STRCHR(x, y)	fdf_ft_strchr(x, y)
# define STRLEN(x)		fdf_ft_strlen(x);
# define STRCMP(x, y)	fdf_ft_strcmp(x, y)
# define WINDOW_SIZE_X	1024
# define WINDOW_SIZE_Y	1024
# define RADIAN			0.0174533
# define COORD 			fdf->coord
# define FDO			fdf->drawer.one
# define FDT			fdf->drawer.two
# define I				fdf->i_j[0]
# define J				fdf->i_j[1]
# define ANG			fdf->angles

typedef double	t_d;
typedef struct	s_coord
{
	int	x;
	int	y;
	int	z;
	int	rgb;
}				t_coord;

typedef struct	s_data
{
	int x[2];
	int y[2];
	int delta_x_y[2];
	int sign_x_y[2];
	int flag_err[2];
}				t_data;

typedef struct	s_angles
{
	double	alpha_beta_gamma[3];
	double	sin_a_b_g[3];
	double	cos_a_b_g[3];
	int		x[2];
	int		y[2];
}				t_angles;

typedef struct	s_drawer
{
	t_data one;
	t_data two;
}				t_drawer;

typedef	struct	s_flag
{
	int	frw;
	int back;
	int right;
	int left;
	int zoomin;
	int down;
	int up;
	int downzoom;
	int zoomout;
}				t_flag;

typedef struct	s_basis
{
	char		**argv;
	void		*mlx;
	void		*window;
	int			fd;
	int			x[3];
	int			y[3];
	int			i_j[2];
	int			x_y_center[2];
	double		scale_x_y_z_all[4];
	t_drawer	drawer;
	t_angles	angles;
	t_flag		flag;
	t_coord		***coord;
}				t_basis;

void			ft_add_coordinate(t_basis *fdf);
void			ft_read_from_file(t_basis *fdf);
void			ft_representation(t_basis *fdf);

/*
**		DRAW LINES AND RECALCULATING COORDINATES
*/

int				ft_algorithm_of_bresenham(t_basis *fdf,
	t_data *draw, int x, int y);
int				ft_calc_coord(t_basis *fdf, char cord, int x, int y);
int				ft_init_rep_first(t_basis *fdf);
int				ft_init_rep(t_basis *fdf);
int				ft_initiialize_representation(t_basis *fdf,
			unsigned char fill_flag);

/*
**		LIBFT_FUNCTIONS
*/

char			*fdf_ft_strchr(const char *s, int c);
int				ft_atoi_base(const char *str, int base);
int				fdf_ft_strcmp(const char *s1, const char *s2);
size_t			fdf_ft_strlen(const char *s);
double			ft_sin_cos(float x, char *inst);
void			ft_sine_cosine(t_basis *fdf);

/*
**		KEY_TOYS AND REDRAW
*/

int				ft_key_events(t_basis *fdf);
int				ft_key_press(int key, t_basis *fdf);
int				ft_key_release(int key, t_basis *fdf);
int				ft_clear_and_draw(t_basis *fdf);
int				ft_check_flag(t_basis *fdf);

#endif
