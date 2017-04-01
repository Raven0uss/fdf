/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 12:23:31 by sbelazou          #+#    #+#             */
/*   Updated: 2017/04/01 12:40:40 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	init(t_map *map, t_axes *axes, t_data *data)
{
	axes->x_a = data->origine_x + (map->x * data->scale) - map->z * data->h;
	axes->y_a = data->origine_y + (map->y * data->scale) - map->z * data->h;
	axes->x_a = axes->x_a - axes->y_a;
	axes->y_a = (axes->x_a + axes->y_a) / 2 + map->y * data->scale;
}

static void	convert(t_map *map, t_axes *axes, t_data *data)
{
	axes->x_b = data->origine_x + (map->next->x * data->scale) -
		map->next->z * data->h;
	axes->y_b = data->origine_y + (map->next->y * data->scale) -
		map->next->z * data->h;
	axes->x_b = axes->x_b - axes->y_b;
	axes->y_b = (axes->x_b + axes->y_b) / 2 + map->y * data->scale;
}

static void	convert_under(t_map *under, t_axes *axes, t_data *data)
{
	axes->x_b = data->origine_x + (under->x * data->scale) -
		under->z * data->h;
	axes->y_b = data->origine_y + (under->y * data->scale) -
		under->z * data->h;
	axes->x_b = axes->x_b - axes->y_b;
	axes->y_b = (axes->x_b + axes->y_b) / 2 + under->y * data->scale;
}

void		convert_to_iso(t_map *under, t_map *map, t_axes *axes, t_data *data)
{
	while (map->next != NULL)
	{
		init(map, axes, data);
		if (map->y == map->next->y)
		{
			convert(map, axes, data, 1);
			ft_drawline(axes, data, map);
		}
		if (under->next != NULL)
		{
			convert_under(under, axes, data, 0);
			ft_drawline(axes, data, map);
			under = under->next;
		}
		map = map->next;
	}
}

void		execute(t_axes *axes)
{
	int		i;
	t_map	*under;
	t_map	*map;
	t_data	*data;

	data = axes->data;
	map = data->first;
	under = map;
	i = data->lenght_line + 1;
	while (--i > 0)
		under = under->next;
	convert_to_iso(under, map, axes, data);
}
