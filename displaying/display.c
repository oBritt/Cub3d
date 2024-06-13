/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:33:19 by obrittne          #+#    #+#             */
/*   Updated: 2024/06/13 18:46:14 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	draw_floor_ceiling(t_data *data)
{
	int	swapper;
	int	i;
	int	e;

	i = 0;
	swapper = data->image->height / 2;
	while (i < (int)data->image->height)
	{
		e = 0;
		while (e < (int)data->image->width)
		{
			if (i < swapper)
				mlx_put_pixel(data->image, e, i, data->ceiling);
			else
				mlx_put_pixel(data->image, e, i, data->floor);
			e++;
		}
		i++;
	}
}

void	test(void *param)
{
	t_data	*data;
	t_ray	ray[(int)AMOUNT_OF_RAYS];

	data = (t_data *)param;
	draw_floor_ceiling(data);
	draw_mini_map(data, ray);
}

void	ft_cpy_map_to_data(t_data *data, t_map *parsing)
{
	data->so = mlx_load_png(parsing->so);
	data->we = mlx_load_png(parsing->we);
	data->ea = mlx_load_png(parsing->ea);
	data->no = mlx_load_png(parsing->no);
	if (!data->so || !data->we || !data->no || !data->we)
		return (freeing_textures(data), free_t_map(parsing), exit(1));
	data->map = parsing->map;
	data->player->x = parsing->y;
	data->player->y = parsing->x;
	data->floor = parsing->floor;
	data->map_height = len_2d_array(data->map);
	data->map_width = ft_str_len(data->map[0]);
	data->player->angle_turn_horizontal = 3.0 * M_PI / 2.0;
	if (parsing->dire == 0)
		data->player->angle_turn_horizontal = 0.0;
	else if (parsing->dire == 1)
		data->player->angle_turn_horizontal = M_PI / 2.0;
	else if (parsing->dire == 2)
		data->player->angle_turn_horizontal = M_PI;
	data->ceiling = parsing->ceiling;
	free_t_map_0_map(parsing);
}

void	init_data(t_data *data)
{
	data->mlx = mlx_init(WIDTH, HEIGHT, "Best Game", false);
	if (!data->mlx)
		exit(EXIT_FAILURE);
	data->image = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->image)
		return (mlx_close_window(data->mlx), free_data_pre_init(data), \
		exit(EXIT_FAILURE));
	data->minimap = mlx_new_image(data->mlx, 288, 288);
	if (!data->minimap)
		return (mlx_delete_image(data->mlx, data->image), \
		mlx_close_window(data->mlx), free_data_pre_init(data), \
		exit(EXIT_FAILURE));
	if (mlx_image_to_window(data->mlx, data->image, 0, 0) == -1 || \
	mlx_image_to_window(data->mlx, data->minimap, 0, \
	data->image->height - data->minimap->height) == -1)
		return (mlx_delete_image(data->mlx, data->image), \
		mlx_delete_image(data->mlx, data->minimap), \
		mlx_close_window(data->mlx),free_data_pre_init(data), \
		exit(EXIT_FAILURE));
}

int	display(t_data *data, t_map *parsing)
{
	ft_cpy_map_to_data(data, parsing);
	init_data(data);
	mlx_loop_hook(data->mlx, test, data);
	mlx_loop_hook(data->mlx, move, data);
	mlx_key_hook(data->mlx, exiting, data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
	free_data_pre_init(data);
	return (1);
}
