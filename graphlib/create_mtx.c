/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_mtx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkushche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 15:32:50 by dkushche          #+#    #+#             */
/*   Updated: 2018/01/06 15:32:50 by dkushche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphlib.h"

t_matrix			create_mtx(unsigned int rows, unsigned int colum)
{
	t_matrix		mtx;
	int				i;
	int				j;

	mtx.data = (double **)malloc(sizeof(double *) * rows);
	i = -1;
	while (++i < (int)rows)
		mtx.data[i] = (double *)malloc(sizeof(double) * colum);
	mtx.rows = rows;
	mtx.colum = colum;
	j = 0;
	while (--i >= 0)
	{
		while (j < (int)colum)
		{
			mtx.data[i][j] = 0;
			j++;
		}
		j = 0;
	}
	return (mtx);
}
