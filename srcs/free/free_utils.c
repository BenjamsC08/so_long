/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 00:17:25 by benjamsc          #+#    #+#             */
/*   Updated: 2025/01/11 23:01:29 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	try_to_free_player(t_data *data)
{
	if (data->perso.down_ptr)
		free(data->perso.down_ptr);
	if (data->perso.down_data)
		free(data->perso.down_data);
	if (data->perso.up_ptr)
		free(data->perso.up_ptr);
	if (data->perso.up_data)
		free(data->perso.up_data);
	if (data->perso.right_ptr)
		free(data->perso.right_ptr);
	if (data->perso.right_data)
		free(data->perso.right_data);
	if (data->perso.left_ptr)
		free(data->perso.left_ptr);
	if (data->perso.left_data)
		free(data->perso.left_data);
}

void	try_to_free_enemy(t_data *data)
{
	if (data->enemy.ptr)
		free(data->enemy.ptr);
	if (data->enemy.data)
		free(data->enemy.data);
}

void	try_to_free_overlay(t_data *data)
{
	if (data->map.asset_ptr)
		free(data->map.asset_ptr);
	if (data->map.asset_data)
		free(data->map.asset_data);
}
