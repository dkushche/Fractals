/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkushche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 15:23:52 by dkushche          #+#    #+#             */
/*   Updated: 2018/01/06 15:23:52 by dkushche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphlib.h"

t_point				mtp(t_matrix mtx, int color)
{
	t_point			point;

	point.x = mtx.data[0][0];
	point.y = mtx.data[1][0];
	point.z = mtx.data[2][0];
	point.p_color = color;
	return (point);
}
