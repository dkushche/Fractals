/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vert_straight.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkushche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 15:47:34 by dkushche          #+#    #+#             */
/*   Updated: 2018/01/06 15:47:35 by dkushche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphlib.h"

int				vert_straight(t_stand set, t_point start, t_point end)
{
	int				now_y;

	now_y = start.y;
	drwpxl(set, start.x, now_y, grad(start, end, 1));
	while (++now_y != end.y + 1)
		drwpxl(set, start.x, now_y, grad(start, end, 0));
	return (1);
}
