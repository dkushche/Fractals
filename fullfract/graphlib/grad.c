/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grad.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkushche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 15:55:16 by dkushche          #+#    #+#             */
/*   Updated: 2018/01/06 15:55:16 by dkushche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphlib.h"

int					grad(t_point start, t_point end, int change)
{
	static int		number = 0;
	static int		size;
	static int		cl[3][2];
	int				dl[3];

	if (change)
	{
		size = abs(start.x - end.x) + abs(start.y - end.y);
		number = 0;
		cl[2][0] = (end.p_color % 256);
		cl[2][1] = (start.p_color % 256);
		cl[1][0] = ((end.p_color - cl[2][0]) / 256 % 256);
		cl[1][1] = ((start.p_color - cl[2][1]) / 256 % 256);
		cl[0][0] = (end.p_color - (cl[1][0] * 256) - cl[2][0]) / 65536 % 256;
		cl[0][1] = (start.p_color - (cl[1][1] * 256) - cl[2][1]) / 65536 % 256;
		return (start.p_color);
	}
	else
	{
		dl[2] = ((cl[2][0] - cl[2][1]) * number) / size;
		dl[1] = ((cl[1][0] - cl[1][1]) * number) / size;
		dl[0] = ((cl[0][0] - cl[0][1]) * number) / size;
		number++;
		return (rgb(cl[0][1] + dl[0], cl[1][1] + dl[1], cl[2][1] + dl[2]));
	}
}
