/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 13:27:23 by albagarc          #+#    #+#             */
/*   Updated: 2022/08/30 10:01:14 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include "../lib/minilibx_macos/mlx.h"
#include "../inc/keycode_hook.h"
#include "../inc/utils.h"
#include "../inc/defines.h"
#include "../inc/errors.h"
#include "../inc/matrix_utils.h"

int	main(int argc, char **argv)
{


	t_all	all;

	if (argc!= 2)
		terminate (ERR_ARGS);
	all.vars.mlx = mlx_init();
        all.vars.win = mlx_new_window(all.vars.mlx, 1920, 1080, "Hello world!");
        all.data.img = mlx_new_image(all.vars.mlx, 1920, 1080);
        all.data.addr = mlx_get_data_addr(all.data.img, &all.data.bits_per_pixel, &all.data.line_length,&all.data.endian);

	load_map(argv[1], &all.map);
//	draw_points(&all);
//	mlx_put_image_to_window(all.vars.mlx, all.vars.win, all.data.img, 0, 0);
//	mlx_key_hook(all.vars.win, key_press, &all.vars);
//	draw_map(&all);
	mlx_hook(all.vars.win, 2, 0, key_press, &all.vars);
	mlx_hook(all.vars.win, 17, 0, ft_destroy_window, &all.vars);
	mlx_loop(all.vars.mlx);

        return(0);
}
