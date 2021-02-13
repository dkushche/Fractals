/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkushche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 15:58:49 by dkushche          #+#    #+#             */
/*   Updated: 2018/01/06 15:58:49 by dkushche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphlib.h"

void				drwpxl(t_stand set, int x, int y, color mycol)
{
	if (check_bord2d(pnt_init(x, y, 1, -1), set))
		mlx_pixel_put(set.mlx, set.win, x, y, mycol);
}
