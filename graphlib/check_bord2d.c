/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bord2d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkushche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 15:43:56 by dkushche          #+#    #+#             */
/*   Updated: 2018/01/06 15:43:56 by dkushche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphlib.h"

int					check_bord2d(t_point point, t_stand set)
{
	int				flag;

	flag = 0;
	if (point.x >= 0 && point.x <= set.s_width)
		flag++;
	if (point.y >= 0 && point.y <= set.s_height)
		flag++;
	return (flag == 2 ? 1 : 0);
}
