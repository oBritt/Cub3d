/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:35:48 by qdo               #+#    #+#             */
/*   Updated: 2024/06/14 10:26:22 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

#define WINDOW_HEIGHT 1023
#define WINDOW_WIDTH 1023

unsigned int	get_pixel(mlx_texture_t *texture, int wid, int hei)
{
	int		ret;
	uint8_t	*temp;
	int		i;
// printf("3\n");
	temp = &texture->pixels[(wid * texture->width + hei) * sizeof(u_int32_t)];
	// printf("4\n");
	ret = 0;
	i = -1;
	// printf("6\n");
	while (++i < 4)
	{
		ret = ret << 8;
		ret = ret | *temp;
		temp += 1;
	}
	// printf("5\n");
	return (ret);
}

// void	render_height_more_than_1(mlx_image_t *image, int texture_hei, double rate, int wid_on_texture)
// {

// }

// void	render_height_less_than_1(mlx_image_t *image, int texture_hei, double rate, int wid_on_texture)
// {
// 	int	

// 	mlx_put_pixel(image, wid_on_texture, , 255 << 16 | 10);	
// }
int	raya(int a1, int b)
{
	static int a = 0;

	if (b == 1)
		return (a);
	a = a1;
	return (0);
}


void	render_height(mlx_image_t *image, mlx_texture_t *texture, int texture_hei, double rate, int wid_on_texture, int wid_on_screen)
{
	// return ;
	// return ;
	printf("ray = %d\n", raya(0, 1));
	if (wid_on_screen >= 993) 
		return ;
	int	hei_highest = WINDOW_HEIGHT / 2 + WINDOW_HEIGHT * rate;
	// printf("5\n");
	int	height_cnt = WINDOW_HEIGHT;
	int height_on_texture;

	if (rate <= 1)
	{
		// while (height_cnt > hei_highest)
		// {
		// 	mlx_put_pixel(image, wid_on_screen, height_cnt--, 100<<16 | 255);
		// 	// printf("a\n");
		// }
		// // printf("6\n");
		height_cnt = hei_highest;
		hei_highest = (WINDOW_HEIGHT - rate * WINDOW_HEIGHT) / 2;
		if (hei_highest < 0)
			hei_highest = 0;
		// printf("7\n");
		// printf("1 = %d\n", height_cnt);
		while (height_cnt > hei_highest)
		{
			
			// printf("8\n");
			// printf("%d\n", WINDOW_HEIGHT - 2 * hei_highest);
			height_on_texture = (height_cnt - hei_highest) / (WINDOW_HEIGHT - 2 * hei_highest) * texture_hei;
			// dprintf(1, "4 = %d\n", height_cnt);
			// printf("1 = {%d}, 2 = {%d}\n", wid_on_screen, height_cnt);
			mlx_put_pixel(image, wid_on_screen, height_cnt, get_pixel(texture, wid_on_texture, height_on_texture));
			// dprintf(1, "3 = %d\n", height_cnt);
			height_cnt -= 1;
		}
		// printf("2= %d\n", height_cnt);
		texture_hei = 0;
		rate = 0;
		wid_on_texture = 0;
		wid_on_screen = 0;
		texture = 0;
		image =0 ;
		
		// while (height_cnt > 0)
		// {
		// 	mlx_put_pixel(image, wid_on_screen, height_cnt--, 255 << 8 | 10);
		// 	// printf("a =\n");
		// }
	}
}

// mlx_put_pixel(data.image, i, j, 255 << 16 | 10);