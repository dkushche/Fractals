/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotX.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkushche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 15:36:36 by dkushche          #+#    #+#             */
/*   Updated: 2018/01/06 15:36:36 by dkushche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphlib.h"

t_matrix			rotx(double angle, t_matrix *input, int back)
{
	t_matrix		turn_mtx;
	t_matrix		result;

	turn_mtx = create_mtx(4, 4);
	turn_mtx.data[0][0] = 1;
	turn_mtx.data[1][1] = cos(angle);
	turn_mtx.data[1][2] = -sin(angle);
	turn_mtx.data[2][1] = sin(angle);
	turn_mtx.data[2][2] = cos(angle);
	turn_mtx.data[3][3] = 1;
	result = mtx_mult(turn_mtx, input, back);
	free_mtx(&turn_mtx);
	return (result);
}
