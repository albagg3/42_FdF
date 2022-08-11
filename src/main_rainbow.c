/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 13:27:23 by albagarc          #+#    #+#             */
/*   Updated: 2022/07/28 12:27:15 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minilibx_macos/mlx.h"



typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{

	
	const int colors[7] = {0xff0000, 0xff8c00, 0xffff00, 0xff00, 0xffff, 0xff1493, 0x551a8b};
	void	*mlx;
	void	*mlx_win;
	t_data img;
	int i;
	int j;
	int x;
	int color;
	int k;
	
//	int pixel;
//	pixel = 0;
	i = 0;
	j = 0;
	x = 0;
	k = 274;
	color = 0;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,&img.endian);
	
/*	while(i < 1080 || j < 1920)
	{
		i = 0;
		color = 0;
		while (i < 1080)
		{
			x = 0;
			while (x < 274 )
			{
				my_mlx_pixel_put(&img, x, i, 0xff0000 + (i/5));
				x++;
			}
			while(x >= 274  && x < 548)
			{
				my_mlx_pixel_put(&img,x , i, (i/5) +  0xff8c00);
				x++;
			}
			while(x >= 548 && x < 822)
			{
				my_mlx_pixel_put(&img,x , i, 0xffff00 + (i/5));
				x++; 
			}
			while(x >= 822 && x < 1096)
			{
				my_mlx_pixel_put(&img,x , i, 0xff00 + (i/5));
				x++;
			}
			while(x >= 1096 && x < 1370)
			{
				my_mlx_pixel_put(&img,x , i, 0xffff + (i/15));
				x++;
			}
			while(x >= 1370 && x < 1644)
			{
				my_mlx_pixel_put(&img,x , i, 0xff1493 + (i/15));
				x++;
			}
			while(x >= 1644 && x < 1920)
			{
				my_mlx_pixel_put(&img,x , i, 0x551a8b + (i/15));
				x++;
			}
			i++;
		}
	//	my_mlx_pixel_put(&img,j, 200, 0xcd66 + (j /5));
	//	color++;
		x++;
		j++;
	}
	*/
	while(color < 7)
	{	
		while (j < 1080 )
		i = 0;
		{
			while (i < 274)
			{
				my_mlx_pixel_put(&img,i ,j , colors[color]);
				i++;
			}
			j++;
			
		}
		color++;
	}


	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	
	return(0);
}
