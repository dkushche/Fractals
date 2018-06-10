/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_quad.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkushche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 15:56:59 by dkushche          #+#    #+#             */
/*   Updated: 2018/01/06 15:56:59 by dkushche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphlib.h"

void				fill_quad(t_stand set, t_point st, t_point ed)
{
	int				vector[2];

	vector[0] = ed.x - st.x;
	vector[1] = abs(ed.y - st.y);
	while (vector[1]--)
	{
		line2d(set, st, pnt_init(st.x + vector[0], st.y, 0, ed.p_color));
		st.y += get_sign(ed.y - st.y);
	}
}
