/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 13:08:01 by albagarc          #+#    #+#             */
/*   Updated: 2022/09/24 13:30:28 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/defines.h"

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
