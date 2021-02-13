/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkushche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 15:40:54 by dkushche          #+#    #+#             */
/*   Updated: 2018/01/06 15:40:54 by dkushche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphlib.h"

t_matrix			move(t_point point_vec, t_matrix *input, int back)
{
	t_matrix		move_mtx;
	t_matrix		result;

	move_mtx = create_mtx(4, 4);
	move_mtx.data[0][3] = point_vec.x;
	move_mtx.data[1][3] = point_vec.y;
	move_mtx.data[2][3] = point_vec.z;
	move_mtx.data[3][3] = 1;
	move_mtx.data[2][2] = 1;
	move_mtx.data[1][1] = 1;
	move_mtx.data[0][0] = 1;
	result = mtx_mult(move_mtx, input, back);
	free_mtx(&move_mtx);
	return (result);
}
