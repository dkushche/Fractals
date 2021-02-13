/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkushche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 15:49:44 by dkushche          #+#    #+#             */
/*   Updated: 2018/01/06 15:49:44 by dkushche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphlib.h"

void				line_loop(t_stand set, t_matrix *pnt, color *c, int n)
{
	int				i;

	i = -1;
	while (++i < n)
		line2d(set, mtp(pnt[i], c[i]), mtp(pnt[(i + 1) % n], c[(i + 1) % n]));
}
