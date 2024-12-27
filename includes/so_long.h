/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 08:21:02 by benjamsc          #+#    #+#             */
/*   Updated: 2024/12/03 09:23:11 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include "libft.h"

# define TILE_SIZE 32
# define MAX_X_WIN 25	//25 time Tile_size
# define MAX_Y_WIN 17	//17 time TILE_SIZE
# define EXTRA_HEIGHT 2
# define HEIGHT_OVL 64
# define WIDTH_OVL 800
/* e : 101 q:113 shift:65505 ctrl:65507	*/
# define U_ARROW 65362
# define L_ARROW 65361
# define R_ARROW 65363
# define D_ARROW 65364
# define W_KEY 119
# define A_KEY 97
# define D_KEY 100
# define S_KEY 115
# define ESC 65307

typedef unsigned char	t_byte;

typedef struct s_tiles
{
	int		size;
	void	*wall_ptr;
	int		*wall_data;
	void	*ground_ptr;
	int		*ground_data;
	void	*door_o_ptr;
	int		*door_o_data;
	void	*door_c_ptr;
	int		*door_c_data;
	void	*coll_ptr;
	int		*coll_data;
}			t_tiles;

typedef struct s_perso
{
	char	dir;
	int		step;
	int		moove_count;
	int		nb_collectible;
	void	*down_ptr;
	int		*down_data;
	void	*up_ptr;
	int		*up_data;
	void	*right_ptr;
	int		*right_data;
	void	*left_ptr;
	int		*left_data;
	int		y;
	int		x;
}			t_perso;

typedef struct s_map
{
	char	**win;
	char	**bp;
	int		resize;
	void	*img_ptr;
	int		*img_data;
	void	*asset_ptr;
	int		*asset_data;
	int		bpp;
	int		endian;
	int		line_len;
	int		x_max;
	int		y_max;
}			t_map;

typedef struct s_enemy
{
	void	*down_ptr;
	int		*down_data;
	void	*up_ptr;
	int		*up_data;
	void	*right_ptr;
	int		*right_data;
	void	*left_ptr;
	int		*left_data;
	int		y;
	int		x;
	char	dir;
}			t_enemy;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			width_win;
	int			height_win;
	char		*path;
	int			collectibles;
	t_map		map;
	t_tiles		tiles;
	t_perso		perso;
	t_enemy		enemy;
}				t_data;

//
//get_map.c
//
int		count_lines(char *path_map);
char	**get_map(t_data *data, char *path_map, int *len_line, int nb_lines);
//
//check_map.c
//
//
int		check_map(char **strs, char *path_map, int nb_lines, int len_line);
//
//check_map_utils.c
//
int		only_one_in_line(char *str);
int		not_allowed_char(char c);
void	flood_fill(char **strs, int y, int x);
char	**dup_map(char **strs, int nb_lines);
int		*get_player_pos(char **strs);
//
//colors_utils.c
//
int		encode_trgb(t_byte t, t_byte r, t_byte g, t_byte b);
t_byte	get_t(int trgb);
t_byte	get_r(int trgb);
t_byte	get_g(int trgb);
t_byte	get_b(int trgb);
//
//errors.c
//
void	err_management_map(int err_code, char *path_map);
//
//frees.c
//
void	classic_close(t_data *data);
int		close_all(t_data *data);
void	free_tabtab(char **strs);
void	free_aprox_map(char **map, int i);
//
//free_utils.c
//
void	free_img(t_data *data);
//
//get_data.c
//
int		load_data(t_data *data);
//
//map_management.c
//
char	**extract_bp_to_win(t_data *data);
//
//win_management.c
//
int		create_window(char *path_map);
//
//draw_map.c
//
void	draw_map(t_data *data, int *big_pixel, int *small_pixel);
void	draw_strs(t_data *data);
//
//moove.c
//
void	moove(t_data *data, int keycode);
//
//enemy.c
//
void	enemy_data(t_data *data);

#endif
