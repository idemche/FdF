/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_from_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 14:24:02 by idemchen          #+#    #+#             */
/*   Updated: 2017/03/31 02:46:12 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_coordinate_init(t_basis *fdf)
{
	char ***split;
	char *line;

	split = (char***)malloc(sizeof(char**) * (fdf->y[0] + 1));
	COORD = (t_coord***)malloc(sizeof(t_coord**) * (fdf->y[0] + 1));
	while ((J = -1) && (get_next_line(fdf->fd, &line))
		&& (split[I] = ft_strsplit(line, ' ')))
	{
		COORD[I] = (t_coord**)malloc(sizeof(t_coord*) * (fdf->x[0] + 1));
		while (split[I][++J])
		{
			COORD[I][J] = (t_coord*)malloc(sizeof(t_coord));
			COORD[I][J]->x = (t_d)(J * fdf->scale_x_y_z_all[0]
			* fdf->scale_x_y_z_all[3]);
			COORD[I][J]->y = (t_d)(I * fdf->scale_x_y_z_all[1]
				* fdf->scale_x_y_z_all[3]);
			COORD[I][J]->z = (t_d)-ft_atoi(split[I][J])
			* (int)fdf->scale_x_y_z_all[2] * fdf->scale_x_y_z_all[3];
			COORD[I][J]->rgb = (STRCHR(split[I][J], 'x')) ?
			ft_atoi_base(STRCHR(split[I][J], 'x') + 1, 16) : 0x00FFFFFF;
		}
		I++;
		ft_strdel(&line);
	}
	free(split);
}

void		ft_scale_init(t_basis *fdf)
{
	fdf->scale_x_y_z_all[0] = WINDOW_SIZE_X / 2 / fdf->x[0];
	fdf->scale_x_y_z_all[1] = WINDOW_SIZE_X / 2 / fdf->y[0];
	fdf->scale_x_y_z_all[2] = ((int)fdf->scale_x_y_z_all[0]
		+ (int)fdf->scale_x_y_z_all[1]) / (int)fdf->scale_x_y_z_all[1] * 5;
	fdf->scale_x_y_z_all[3] = 1;
	(fdf->x[0] == 500) ? fdf->scale_x_y_z_all[0] = 2 : 0;
	(fdf->y[0] == 500) ? fdf->scale_x_y_z_all[1] = 2 : 0;
	(fdf->x[0] == 500 && fdf->y[0] == 500) ? fdf->scale_x_y_z_all[2] = 1 : 0;
}

void		ft_read_from_file(t_basis *fdf)
{
	char	*line;
	char	**split;
	int		x_tmp[2];

	I =
	(x_tmp[0] = 0);
	J =
	(x_tmp[1] = 0);
	if ((fdf->fd = open(fdf->argv[1], O_RDONLY)) < 0)
		exit(write(2, "Cannot open file\n", 17));
	while (get_next_line(fdf->fd, &line) && (split = ft_strsplit(line, ' ')))
	{
		while (split[x_tmp[0]] && ++x_tmp[1])
			free(split[x_tmp[0]++]);
		if (((t_d)x_tmp[0]) != ((t_d)x_tmp[1] / (fdf->y[0] + 1)))
			exit(write(2, "Wrong X\n", 8));
		fdf->x[0] = x_tmp[0];
		(x_tmp[0] = 0) || (++fdf->y[0]);
		ft_strdel(&line);
		free(split);
	}
}

void		ft_add_coordinate(t_basis *fdf)
{
	ft_read_from_file(fdf);
	close(fdf->fd);
	fdf->fd = open(fdf->argv[1], O_RDONLY);
	ft_scale_init(fdf);
	ft_coordinate_init(fdf);
}
