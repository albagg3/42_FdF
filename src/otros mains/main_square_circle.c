/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_square_circle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 13:27:23 by albagarc          #+#    #+#             */
/*   Updated: 2022/08/12 16:42:14 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/mlx_linux/mlx.h"
#include <stdio.h>
#include <unistd.h>
#include <math.h>


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
	void	*mlx;
	void	*mlx_win;
	t_data img;
	int i;
	int j;
	int x;
	int y;
	int radio;	
	
//	i = 200 ;
//	j = 200 ;
	x = 0;
	
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,&img.endian);
/*	while(x < 150 )
	{
		i =200 + x;
		j =200 + x;
		while((i < (500-x) || j < (500-x)) && x >= 0)
		{
			
			while (i < (500-x))
			{
				my_mlx_pixel_put(&img, 200 + x, i, 0xff0000 + x);
				my_mlx_pixel_put(&img, 500 - x, i, 0xff0000 + x);
				i++;
		//		x++;
			}
			my_mlx_pixel_put(&img,j, 200 + x, 0xcd66 + x );
			my_mlx_pixel_put(&img,j, 500 - x, 0xcd66 + x );
			j++;
		//	x++;
		}
		x++;
		x++;
		x++;
		x++;

		
	}

*/	my_mlx_pixel_put(&img, 500, 500, 0xcd66 );
	radio = 300;
	x = 200;
	y = 200;
	i = 500;
	j = 500;
	
	while(x <= 801 && y <= 801)
	{
		x = 200;
		while(x <= 800)
		{
			if (pow((x - i), 2) + pow((y - j), 2) <= pow(radio,2))
			{
				write(1, "a", 1);
				printf("entra valor de x en el pow: %d y x es %d\n ", x, y);
				my_mlx_pixel_put(&img, x, y, 0xcd66);
			}


			x++;
		//	printf("el valor de x: %d\n", x);
		}
		y++;
		write(1,"b", 1);
	//	printf("el valor de y: %d\n", y);
	}

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	
	return(0);
}
