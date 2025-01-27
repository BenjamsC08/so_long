/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_solong.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:15:57 by benjamsc          #+#    #+#             */
/*   Updated: 2025/01/17 04:19:17 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_SOLONG_H
# define STRUCT_SOLONG_H

typedef unsigned char	t_byte;

typedef struct s_tiles
{
	int					size;
	void				*wall_ptr;
	int					*wall_data;
	void				**ground_ptr;
	int					**ground_data;
	void				*door_ptr[2];
	int					*door_data[2];
	void				*coll_ptr;
	int					*coll_data;
}						t_tiles;

typedef struct s_perso
{
	char				dir;
	int					step;
	int					moove_count;
	int					nb_collectible;
	void				**down_ptr;
	int					**down_data;
	void				**up_ptr;
	int					**up_data;
	void				**right_ptr;
	int					**right_data;
	void				**left_ptr;
	int					**left_data;
	int					y;
	int					x;
}						t_perso;

typedef struct s_map
{
	char				**win;
	char				**bp;
	int					resize;
	void				*img_ptr;
	int					*img_data;
	void				**asset_ptr;
	int					**asset_data;
	int					bpp;
	int					endian;
	int					line_len;
	int					x_max;
	int					y_max;
}						t_map;

typedef struct s_enemy
{
	int					is_on;
	void				**ptr;
	int					**data;
	int					y;
	int					x;
	char				dir;
	int					step;
	int					idling;
}						t_enemy;

typedef struct s_data
{
	void				*mlx;
	void				*win;
	int					width_win;
	int					height_win;
	char				*path;
	int					collectibles;
	int					type_resize;
	t_map				map;
	t_tiles				tiles;
	t_perso				perso;
	t_enemy				enemy;
}						t_data;

#endif
