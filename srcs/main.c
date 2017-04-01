*/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 17:48:57 by sbelazou          #+#    #+#             */
/*   Updated: 2017/04/01 12:50:10 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_map			*init_map(void)
{
	t_map	*new;

	if ((new = (t_map *)malloc(sizeof(*new))) == NULL)
		ft_error(-1);
	new->next = NULL;
	return (new);
}

void			img_init(t_axes *axes)
{
	if ((axes->img.adr =
			mlx_new_image(axes->mlx, axes->map_x, axes->map_y)) == NULL)
		ft_error(-1);
	if ((axes->img.img = mlx_get_data_addr(axes->img.adr, &axes->img.bpp,
			&axes->img.sl, &axes->img.endian)) == NULL)
		ft_error(-1);
}

static void		init_data(t_data *data, t_axes *axes)
{
	axes->map_x = 1200;
	axes->map_y = 1000;
	if (data->lenght_line > 50 &&
			data->lenght_line < 90)
	{
		data->scale = 5;
		data->h = 5;
	}
	else if (data->lenght_line >= 0 &&
			data->lenght_line <= 50)
	{
		data->scale = 30;
		data->h = 10;
	}
	else
	{
		data->scale = 2;
		data->h = 1;
	}
	data->origine_x = 300;
	data->origine_y = -250;
}

int				main(int argc, char **argv)
{
	t_axes	axes;
	t_data	data;

	if (argc != 2)
		ft_error(-1);
	parse(argv[1], &data);
	init_data(&data, &axes);
	if ((axes.mlx = mlx_init()) == NULL)
		ft_error(-1);
	if ((axes.win = mlx_new_window(axes.mlx, axes.map_x, axes.map_y,
			"[FdF42 - sbelazou]")) == NULL)
		ft_error(-1);
	img_init(&axes);
	mlx_hook(axes.win, 2, 1, ft_key, &axes);
	axes.data = &data;
	color(&data);
	execute(&axes);
	mlx_put_image_to_window(axes.mlx, axes.win, axes.img.adr, 0, 0);
	commands(&axes);
	mlx_loop(axes.mlx);
}
