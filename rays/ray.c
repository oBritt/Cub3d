/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:17:44 by obrittne          #+#    #+#             */
/*   Updated: 2024/06/13 18:52:10 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	draw_rays(t_data *data, t_ray *ray)
{
	int	i;

	i = 0;
	while (i < AMOUNT_OF_RAYS)
	{
		get_cords(data, add_angles(data->player->angle_turn_horizontal, \
		M_PI / 3.0 / AMOUNT_OF_RAYS * ((double) i) - (M_PI / 6.0) ), &ray[i]);
		transform_cordinates(data, &ray[i]);
		DDA(data, &ray[i]);
		i++;
	}
}
