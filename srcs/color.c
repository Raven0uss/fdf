/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 12:10:04 by sbelazou          #+#    #+#             */
/*   Updated: 2017/04/01 12:49:41 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	rgb(t_map *map, int r, int g, int b)
{
	map->color_r = r;
	map->color_g = g;
	map->color_b = b;
}

void	color(t_data *data)
{
	t_map *map;

	map = data->first;
	while (1)
	{
		map->z < 0 ? rgb(map, 30, 30, 123) : 0;
		map->z == 0 ? rgb(map, 83, 197, 83) : 0;
		map->z > 0 && map->z < 3 ? rgb(map, 64, 191, 64) : 0;
		map->z >= 3 && map->z < 5 ? rgb(map, 58, 172, 58) : 0;
		map->z >= 5 && map->z < 7 ? rgb(map, 51, 153, 51) : 0;
		map->z >= 7 && map->z < 10 ? rgb(map, 45, 134, 45) : 0;
		map->z >= 10 && map->z < 17 ? rgb(map, 38, 115, 38) : 0;
		map->z >= 17 && map->z < 20 ? rgb(map, 102, 102, 51) : 0;
		map->z >= 20 && map->z < 25 ? rgb(map, 119, 119, 60) : 0;
		map->z >= 25 && map->z < 30 ? rgb(map, 198, 141, 82) : 0;
		map->z >= 30 && map->z < 35 ? rgb(map, 192, 129, 63) : 0;
		map->z >= 35 && map->z < 49 ? rgb(map, 173, 116, 57) : 0;
		map->z >= 49 && map->z < 56 ? rgb(map, 134, 90, 45) : 0;
		map->z >= 56 && map->z < 65 ? rgb(map, 115, 77, 38) : 0;
		map->z >= 65 && map->z < 75 ? rgb(map, 96, 64, 32) : 0;
		map->z >= 75 ? rgb(map, 255, 255, 255) : 0;
		if (map->next == NULL)
			break ;
		map = map->next;
	}
}
