/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrt_pnt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkushche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 15:31:23 by dkushche          #+#    #+#             */
/*   Updated: 2018/01/06 15:31:23 by dkushche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphlib.h"

t_matrix			wrt_pnt(double x, double y, double z)
{
	t_matrix		point;

	point = create_mtx(4, 1);
	point.data[0][0] = x;
	point.data[1][0] = y;
	point.data[2][0] = z;
	point.data[3][0] = 1;
	return (point);
}
