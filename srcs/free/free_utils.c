/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 00:17:25 by benjamsc          #+#    #+#             */
/*   Updated: 2025/01/08 11:21:25 by benjamsc         ###   ########.fr       */
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
	if (data->enemy.down_ptr)
		free(data->enemy.down_ptr);
	if (data->enemy.down_data)
		free(data->enemy.down_data);
	if (data->enemy.up_ptr)
		free(data->enemy.up_ptr);
	if (data->enemy.up_data)
		free(data->enemy.up_data);
	if (data->enemy.right_ptr)
		free(data->enemy.right_ptr);
	if (data->enemy.right_data)
		free(data->enemy.right_data);
	if (data->enemy.left_ptr)
		free(data->enemy.left_ptr);
	if (data->enemy.left_data)
		free(data->enemy.left_data);
}
