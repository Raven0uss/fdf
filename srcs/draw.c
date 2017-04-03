/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 12:12:31 by sbelazou          #+#    #+#             */
/*   Updated: 2017/04/03 14:15:55 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	img_pixel_put(t_axes *axes, int x, int y, t_map *map)
{
	int	pos;

	if ((x < axes->map_x && y < axes->map_y && x >= 0 && y >= 0))
	{
		pos = (x * axes->img.bpp / 8) + (y * axes->img.sl);
		axes->img.img[pos] = map->color_b;
		axes->img.img[pos + 1] = map->color_g;
		axes->img.img[pos + 2] = map->color_r;
	}
}

void	ft_drawline(t_axes *axes, t_data *data, t_map *map)
{
	data->dh = axes->x_b - axes->x_a;
	data->dl = axes->y_b - axes->y_a;
	data->c = -1;
	data->m = abs(data->dh) > abs(data->dl) ? abs(data->dh) : abs(data->dl);
	while (++data->c < data->m)
		img_pixel_put(axes, axes->x_a + data->c * data->dh / data->m,
				axes->y_a + data->c * data->dl / data->m, map);
}

void	commands(t_axes *axes)
{
	mlx_string_put(axes->mlx, axes->win, 10, 10, 0xFFFFFF,
				   "[-][COMMANDS - [FdF42 - sbelazou]][-]");
	mlx_string_put(axes->mlx, axes->win, 10, 30, 0xFFFFFF,
			"[9 6] : Zoom avant, Zoom arriere");
	mlx_string_put(axes->mlx, axes->win, 10, 50, 0xFFFFFF,
			"[+ -] : Plus haut, Moins haut");
	mlx_string_put(axes->mlx, axes->win, 10, 70, 0xFFFFFF,
			"[Up Down] : Aller vers le haut, Aller vers le bas");
	mlx_string_put(axes->mlx, axes->win, 10, 90, 0xFFFFFF,
			"[Left Right] : Aller vers la gauche, Aller vers la droite");
}
