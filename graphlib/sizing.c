/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sizing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkushche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 15:39:30 by dkushche          #+#    #+#             */
/*   Updated: 2018/01/06 15:39:31 by dkushche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphlib.h"

t_matrix			sizing(double times, t_matrix *input, int back)
{
	t_matrix		size_mtx;
	t_matrix		result;

	size_mtx = create_mtx(4, 4);
	size_mtx.data[0][0] = times;
	size_mtx.data[1][1] = times;
	size_mtx.data[2][2] = times;
	size_mtx.data[3][3] = 1;
	result = mtx_mult(size_mtx, input, back);
	free_mtx(&size_mtx);
	return (result);
}
