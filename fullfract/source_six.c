/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source_six.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkushche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 18:21:42 by dkushche          #+#    #+#             */
/*   Updated: 2018/01/18 18:21:43 by dkushche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				key_mover(t_pack *pack, int k)
{
	if (k == 126)
		move_fract(S_WID / 2, 0, pack, MOVE_P);
	if (k == 123)
		move_fract(0, S_HEI / 2, pack, MOVE_P);
	if (k == 124)
		move_fract(S_WID, S_HEI / 2, pack, MOVE_P);
	if (k == 125)
		move_fract(S_WID / 2, S_HEI, pack, MOVE_P);
}
