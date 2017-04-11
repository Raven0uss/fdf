/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 16:26:25 by sbelazou          #+#    #+#             */
/*   Updated: 2017/04/04 11:06:57 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include <mlx.h>
# include <math.h>
# include <fcntl.h>

typedef struct		s_map
{
	int				x;
	int				y;
	int				z;
	int				color_b;
	int				color_g;
	int				color_r;
	int				z_max;
	struct s_map	*next;
	struct s_map	*previous;
}					t_map;

typedef struct		s_data
{
	struct s_map	*first;
	int				lenght_line;
	int				dh;
	int				dl;
	int				m;
	int				c;
	int				h;
	int				scale;
	int				origine_x;
	int				origine_y;
	int				fd;
	char			*line;
	char			**table;
	int				x;
	int				y;
	int				z_max;
}					t_data;

typedef struct		s_img
{
	void			*adr;
	char			*img;
	int				bpp;
	int				sl;
	int				endian;
}					t_img;

typedef struct		s_axes
{
	void			*mlx;
	void			*win;
	int				map_x;
	int				map_y;
	int				x_a;
	int				y_a;
	int				x_b;
	int				y_b;
	int				j;
	t_img			img;
	struct s_data	*data;
}					t_axes;

void				ft_error(int i);
void				mapping(t_data *data, t_map *map);
int					parse(char *file, t_data *data);
void				execute(t_axes *axes);
int					ft_key(int k, t_axes *axes);
void				img_init(t_axes *axes);
t_map				*init_map(void);
void				ft_drawline(t_axes *axes, t_data *data, t_map *map);
void				color(t_data *data);
void				commands(t_axes *axes);

#endif
