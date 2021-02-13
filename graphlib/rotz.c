/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotZ.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkushche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 15:37:28 by dkushche          #+#    #+#             */
/*   Updated: 2018/01/06 15:37:28 by dkushche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphlib.h"

t_matrix			rotz(double angle, t_matrix *input, int back)
{
	t_matrix		turn_mtx;
	t_matrix		result;

	turn_mtx = create_mtx(4, 4);
	turn_mtx.data[0][0] = cos(angle);
	turn_mtx.data[1][0] = sin(angle);
	turn_mtx.data[0][1] = -sin(angle);
	turn_mtx.data[1][1] = cos(angle);
	turn_mtx.data[2][2] = 1;
	turn_mtx.data[3][3] = 1;
	result = mtx_mult(turn_mtx, input, back);
	free_mtx(&turn_mtx);
	return (result);
}
