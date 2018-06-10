/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source_four.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkushche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 20:51:39 by dkushche          #+#    #+#             */
/*   Updated: 2018/01/15 20:51:40 by dkushche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

t_aim			*aim_create(int numb, void **mlx, void *win)
{
	t_aim		*aim;
	int			j;
	int			x;

	aim = (t_aim *)malloc(sizeof(t_aim) * 8);
	j = -1;
	while (++j < 8)
	{
		x = (j % 4) * S_WID / 4;
		aim[j] = aim_init(x, (j / 4) * S_HEI / 2, mlx, win);
		aim[j].n = numb;
	}
	return (aim);
}

void			check_stop(t_pack *pack)
{
	int			i;

	i = -1;
	while (++i < 8)
	{
		if (pack->aims[i].stop)
			pack->aims[i].stop--;
		else
			pack->aims[i].stop++;
	}
}

int				my_destr_win(void *param)
{
	param = NULL;
	exit(1);
}

int				mult_win_mode(int *numb, int size, void *mlx)
{
	t_pack			*packs;
	t_aim			**aims;
	void			**wins;
	int				i;

	aims = (t_aim **)malloc(sizeof(t_aim *) * size);
	wins = (void **)malloc(sizeof(void *) * size);
	packs = (t_pack *)malloc(sizeof(t_pack) * size);
	i = -1;
	while (++i < size)
	{
		wins[i] = mlx_new_window(mlx, S_WID, S_HEI, "D_FRACTOL");
		aims[i] = aim_create(numb[i], mlx, wins[i]);
		CHECK((thread_col_f(&(aims[i]))));
		draw(aims[i]);
		packs[i].aims = aims[i];
	}
	while (--i != -1)
	{
		mlx_hook(wins[i], 6, 0, my_motion_notif, &(packs[i]));
		mlx_hook(wins[i], 2, 0, my_key_funct, &(packs[i]));
		mlx_hook(wins[i], 4, 0, my_mouse_hook, &(packs[i]));
		mlx_hook(wins[i], 17, 0, my_destr_win, NULL);
	}
	return (mlx_loop(mlx));
}

int				fract_travka(t_compl z, t_compl c, int col)
{
	int			k;
	t_compl		b;
	t_compl		a;

	k = 0;
	while (k < QUALITY)
	{
		if (com_mod(z) < 4)
		{
			b = com_sum((com_mult(z, z)), c);
			a = com_sum((com_mult(c, c)), z);
			z = com_sum(com_mult(b, b), a);
		}
		else
			return (color_theme(k, col));
		k++;
	}
	return (0);
}
