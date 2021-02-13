/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source_three.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkushche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 19:36:26 by dkushche          #+#    #+#             */
/*   Updated: 2018/01/13 19:36:27 by dkushche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			draw(t_aim *aim)
{
	int			j;
	int			x;
	int			y;

	mlx_clear_window(aim[0].mlx, aim[0].win);
	j = -1;
	while (++j < 8)
	{
		x = ((j % 4) * S_WID / 4);
		y = ((j / 4) * S_HEI / 2);
		mlx_put_image_to_window(aim[j].mlx, aim[j].win, aim[j].im, x, y);
	}
}

int				color_theme(int k, int col)
{
	if (col % N_OF_THEME == 0)
		return (rgb(0, 0, k * 250));
	if (col % N_OF_THEME == 1)
		return (rgb(0, k * 250, 0));
	if (col % N_OF_THEME == 2)
		return (rgb(k * 250, 0, 0));
	if (col % N_OF_THEME == 3)
		return (rgb(k * 250, 0, k * 250));
	if (col % N_OF_THEME == 4)
		return (rgb(0, k * 250, k * 250));
	if (col % N_OF_THEME == 5)
		return (rgb(k * 250, k * 250, 0));
	if (col % N_OF_THEME == 6)
		return (rgb(k * 250, k * 250, k * 250));
	return (255);
}

int				my_mouse_hook(int button, int x, int y, void *param)
{
	t_pack		*pack;
	static int	insider = 0;

	pack = param;
	if (button == 5)
	{
		if (insider < 71)
		{
			move_fract(x, y, pack, MOVE_P / 3);
			zoom_fract(pack, 1);
			insider++;
		}
	}
	if (button == 4)
	{
		move_fract(x, y, pack, MOVE_P / 3);
		zoom_fract(pack, 0);
		insider--;
	}
	if (button == 1)
		move_fract(x, y, pack, MOVE_P);
	thread_col_f(&(pack->aims));
	mlx_clear_window(pack->aims[0].mlx, pack->aims[0].win);
	draw(pack->aims);
	return (0);
}

t_aim			aim_init(int s_x, int s_y, void *mlx, void *win)
{
	t_aim		res;
	int			endian;

	res.start_x = s_x;
	res.start_y = s_y;
	res.s_im = -1.0;
	res.s_re = -2.0;
	res.e_im = 1.0;
	res.e_re = 1;
	res.mlx = mlx;
	res.win = win;
	res.stop = 0;
	res.tcol = 0;
	res.step = fabs(res.e_im - res.s_im) / S_HEI;
	res.im = mlx_new_image(mlx, S_WID / 4, S_HEI / 2);
	res.im_d = mlx_get_data_addr(res.im, &(res.bpp), &(res.sl), &endian);
	return (res);
}

int				my_motion_notif(int x, int y, void *param)
{
	t_pack		*pack;
	int			j;

	j = -1;
	pack = param;
	if (pack->aims[0].n != 2 && pack->aims[0].n < 3)
		return (0);
	if (!pack->aims[0].stop)
		return (0);
	if (x > 0 && x < S_WID && y > 0 && y < S_HEI)
	{
		while (++j < 8)
		{
			pack->aims[j].par.re = -1 + (2.0 / S_WID) * x;
			pack->aims[j].par.im = -1 + (2.0 / S_HEI) * y;
		}
		thread_col_f(&(pack->aims));
		mlx_clear_window(pack->aims[0].mlx, pack->aims[0].win);
		draw(pack->aims);
	}
	return (0);
}
