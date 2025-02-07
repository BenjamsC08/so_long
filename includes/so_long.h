/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 08:21:02 by benjamsc          #+#    #+#             */
/*   Updated: 2025/01/17 04:33:15 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "path_textures.h"
# include "struct_solong.h"
# include <mlx.h>
# include <stdlib.h>

# define TILE_SIZE 32
# define MAX_X_WIN 25
# define MAX_Y_WIN 17
# define EXTRA_HEIGHT 2
# define HEIGHT_OVL 64
# define WIDTH_OVL 800
# define U_ARROW 65362
# define L_ARROW 65361
# define R_ARROW 65363
# define D_ARROW 65364
# define W_KEY 119
# define A_KEY 97
# define D_KEY 100
# define S_KEY 115
# define ESC 65307
# define PATH_TEXTURES "./includes/path_textures.h"
# define NB_IMG 27

//
// data/
//		enemy_data.c
int	  enemy_data(t_data *data);
//		get_data.c
int		load_data(t_data *data);
//		map_data.c
int	  map_data(t_data *data);
//		player_data.c
int 	player_data(t_data *data);
//
// draw/
//		colors_utils.c
t_byte	get_t(int trgb);
t_byte	get_r(int trgb);
t_byte	get_g(int trgb);
t_byte	get_b(int trgb);
int		encode_trgb(t_byte t, t_byte r, t_byte g, t_byte b);
//		draw.c
void	draw_map(t_data *data, int *big_pixel, int *small_pixel);
void	draw_strs(t_data *data);
void	draw_overlay(t_data *data);
//		draw_utils.c
int		*get_player_img_data(t_data *data);
int		*get_enemy_img_data(t_data *data, int y, int x);
int		*get_map_img_data(t_data *data, char g);
//
// free/
//		free_img.c
void	free_img(t_data *data);
//		free_utils.c
void	try_to_free_player(t_data *data);
void	try_to_free_enemy(t_data *data);
void	try_to_free_overlay(t_data *data);
//		frees.c
void	classic_close(t_data *data);
int		close_all(t_data *data);
void	free_tabtab(char **strs);
void	free_aprox_map(char **map, int i);
//
// map/
//		check_map.c
int		check_map(char **strs, t_data *data, int len_line);
//		check_map_utils.c
int		only_one_in_line(char *str);
int		not_allowed_char(char c);
void	flood_fill(char **strs, int y, int x);
char	**dup_map(char **strs, int nb_lines);
int		*get_pos(char **strs, char to_find);
//		get_map.c
int		count_lines(char *path_map);
char	**get_map(t_data *data, int *len_line);
//		map_management.c
char	**extract_bp_to_win(t_data *data, int x);
char	**map_diversity(t_data *data, char **strs);
//
// enemy.c
//
void	enemy_moove(t_data *data);
//
// errors.c
//
void	err_management_map(int err_code, char *path_map);
//
// moove.c
//
void	moove(t_data *data, int keycode);

//
// utils.c
//
int		is_ok(t_data *data);
int		ft_nl_strlen(char *str);
void	resize_map(t_data *data, int x);
//
// win_management.c
//
int		create_window(char *path_map);
int		ending(t_data *data, char to, int *pos);

int		checker(void);

void    in_run_free(t_data *data);

#endif
