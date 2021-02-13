/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pnt_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkushche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 15:29:49 by dkushche          #+#    #+#             */
/*   Updated: 2018/01/06 15:29:50 by dkushche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphlib.h"

t_point				pnt_init(int x, int y, int z, int color)
{
	t_point			point;

	point.x = x;
	point.y = y;
	point.z = z;
	if (color >= 0)
		point.p_color = color;
	else
		point.p_color = 0xFFFFFF;
	return (point);
}
