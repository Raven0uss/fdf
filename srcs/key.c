/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 12:13:52 by sbelazou          #+#    #+#             */
/*   Updated: 2017/04/03 14:19:20 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			ft_key(int k, t_axes *axes)
{
	t_data	*data;

	data = axes->data;
	data->h = k == 69 ? data->h + 1 : data->h + 0;
	data->h = k == 78 ? data->h - 1 : data->h - 0;
	data->scale = k == 88 ? data->scale + 1 : data->scale + 0;
	data->scale = k == 92 && data->scale > 1 ?
		data->scale - 1 : data->scale - 0;
	data->origine_y = k == 123 ? data->origine_y + 20 : data->origine_y + 0;
	data->origine_y = k == 124 ? data->origine_y - 20 : data->origine_y - 0;
	data->origine_y = k == 125 ? data->origine_y + 20 : data->origine_y + 0;
	data->origine_x = k == 125 ? data->origine_x + 20 : data->origine_x + 0;
	data->origine_y = k == 126 ? data->origine_y - 20 : data->origine_y - 0;
	data->origine_x = k == 126 ? data->origine_x - 20 : data->origine_x + 0;
	mlx_clear_window(axes->mlx, axes->win);
	mlx_destroy_image(axes->mlx, axes->img.adr);
	img_init(axes);
	execute(axes);
	mlx_put_image_to_window(axes->mlx, axes->win, axes->img.adr, 0, 0);
	commands(axes);
	if (k == 53)
		exit(0);
	return (0);
}
