/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkushche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 15:34:10 by dkushche          #+#    #+#             */
/*   Updated: 2018/01/06 15:34:11 by dkushche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphlib.h"

t_matrix			mtx_mult(t_matrix f, t_matrix *s, int back)
{
	t_matrix		rs;
	int				v[3];

	v[1] = -1;
	if (f.colum != s->rows)
		return (f);
	rs = create_mtx(f.rows, s->colum);
	while (++v[1] < (int)rs.colum)
	{
		v[0] = -1;
		while (++v[0] < (int)f.rows)
		{
			v[2] = -1;
			while (++v[2] < (int)f.colum)
				rs.data[v[0]][v[1]] += f.data[v[0]][v[2]] * s->data[v[2]][v[1]];
		}
	}
	if (!back)
		free_mtx(s);
	return (rs);
}
