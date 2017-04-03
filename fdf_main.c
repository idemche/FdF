/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 14:18:20 by idemchen          #+#    #+#             */
/*   Updated: 2017/03/31 22:24:21 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_basis_initializer(t_basis *fdf, char ***argv)
{
	fdf->y[0] = 0;
	I = 0;
	J = 0;
	fdf->argv = *argv;
	fdf->mlx = mlx_init();
	fdf->window = mlx_new_window(fdf->mlx, WINDOW_SIZE_X,
		WINDOW_SIZE_Y, "FdF by IDEMCHEN");
	ANG.alpha_beta_gamma[0] = RADIAN * 45;
	ANG.alpha_beta_gamma[1] = RADIAN * 45;
	ANG.alpha_beta_gamma[2] = 0;
}

int			main(int argc, char **argv)
{
	t_basis fdf;
	char testchar;
	int fd;

	if (argc != 2)
		return (write(2, "try ./fdf <map_file>", 20));
	else
		fd = open(argv[1], O_RDONLY);
	if (!(read(fd, &testchar, 1)))
		exit(write(2, "Potential Segfault\n", 19));
	close (fd);
	ft_basis_initializer(&fdf, &argv);
	fdf.x_y_center[0] = WINDOW_SIZE_X / 2;
	fdf.x_y_center[1] = WINDOW_SIZE_Y / 2;
	ft_add_coordinate(&fdf);
	ft_sine_cosine(&fdf);
	ft_representation(&fdf);
	mlx_loop_hook(fdf.mlx, ft_key_events, &fdf);
	mlx_loop(fdf.mlx);
	return (0);
}
