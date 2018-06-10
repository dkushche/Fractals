/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line2d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkushche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 15:54:00 by dkushche          #+#    #+#             */
/*   Updated: 2018/01/06 15:54:00 by dkushche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphlib.h"

int					line2d(t_stand set, t_point start, t_point end)
{
	int				vec[2];
	int				dl[2];
	int				n;
	t_point			*p[2];

	p[0] = &start;
	p[1] = &end;
	if (end.y < start.y)
		pnt_swap(&p[0], &p[1]);
	vec[0] = p[1]->x - p[0]->x;
	vec[1] = p[1]->y - p[0]->y;
	dl[0] = vec[0] > 0 ? 1 : -1;
	if (!vec[0] || (n = 0))
		return (vert_straight(set, *p[0], *p[1]));
	drwpxl(set, p[0]->x, p[0]->y, grad(*p[0], *p[1], 1));
	while ((p[0]->x != p[1]->x || p[0]->y != p[1]->y) && ++n)
	{
		drwpxl(set, (p[0]->x += dl[0]), p[0]->y, grad(*p[0], *p[1], 0));
		dl[1] = ((n * vec[1]) / vec[0]) * dl[0];
		dl[1] -= (((n - 1) * vec[1]) / vec[0]) * dl[0] - 1;
		while (--dl[1])
			drwpxl(set, p[0]->x, ++(p[0]->y), grad(*p[0], *p[1], 0));
	}
	drwpxl(set, p[1]->x, p[1]->y, p[1]->p_color);
	return (1);
}
