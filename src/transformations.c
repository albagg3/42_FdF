/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 13:08:01 by albagarc          #+#    #+#             */
/*   Updated: 2022/11/24 17:15:07 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/defines.h"
#include <stdio.h>

void zoom (t_point *points, int len, float scale)
{
	int i;

	i = 0;
	while (i < len)
	{
		points[i].coordinates[X] *= scale;
		points[i].coordinates[Y] *= scale;
		points[i].coordinates[Z] *= scale;
		i++;
	}


}

void ft_reduce_z(int len, t_point *points, float divisor)
{
	int i;

	i = 0;
	while (i < len)
	{
		printf("reduzzzz: %f\n",points[i].coordinates[Z]);
		points[i].coordinates[Z] /= divisor;
		i++;
	}
}
