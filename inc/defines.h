/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 11:08:59 by albagarc          #+#    #+#             */
/*   Updated: 2022/08/12 14:38:41 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define BUFFER_SIZE 10
# define X 0
# define Y 1
# define Z 2

typedef struct s_point
{
	int		coordinates[3];
	int		color;
}	t_point;

typedef struct s_map
{
	t_point		*points;
	t_point		limits;
	int			total_size;
	


}	t_map;


#endif                
