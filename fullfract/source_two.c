/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source_two.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkushche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 19:36:21 by dkushche          #+#    #+#             */
/*   Updated: 2018/01/13 19:36:22 by dkushche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int					sorry_mes(void)
{
	ft_putstr(ACC"Write numbers of fractals"ACR"\n");
	ft_putstr(ACM"1.Mandelbrot\n2.Julia\n3.Newton"ACR"\n");
	ft_putstr(ACM"4.Meta\n5.Special\n6.Brain\n7.Plane\n8.Baloons"ACR"\n");
	ft_putstr(ACY"6 or 4 change fractal"ACR"\n");
	ft_putstr(ACY"'Space' - change color"ACR"\n");
	ft_putstr(ACY"'Ctrl' - stop fractal"ACR"\n");
	return (0);
}

int					thread_col_f(t_aim **aims)
{
	pthread_t		pid[8];
	pthread_attr_t	attr;
	int				j;
	int				checker;
	t_aim			*aim;

	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
	pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM);
	j = -1;
	while (++j < 8)
	{
		aim = *aims + j;
		checker = pthread_create(&pid[j], &attr, draw_fract, aim);
		if (checker)
			return (0);
	}
	while (--j > -1)
	{
		checker = pthread_join(pid[j], NULL);
		if (checker)
			return (0);
	}
	return (1);
}

void				zoom_fract(t_pack *pack, int in)
{
	int				j;
	double			del;

	j = -1;
	while (++j < 8)
	{
		if (in)
		{
			pack->aims[j].s_im += pack->aims[j].step * ZOOM;
			pack->aims[j].e_im -= pack->aims[j].step * ZOOM;
			del = fabs(pack->aims[j].e_im - pack->aims[j].s_im);
			pack->aims[j].step = del / S_HEI;
			pack->aims[j].s_re += pack->aims[j].step * ZOOM;
			pack->aims[j].e_re -= pack->aims[j].step * ZOOM;
		}
		else
		{
			pack->aims[j].s_im -= pack->aims[j].step * ZOOM;
			pack->aims[j].e_im += pack->aims[j].step * ZOOM;
			del = fabs(pack->aims[j].e_im - pack->aims[j].s_im);
			pack->aims[j].step = del / S_HEI;
			pack->aims[j].s_re -= pack->aims[j].step * ZOOM;
			pack->aims[j].e_re += pack->aims[j].step * ZOOM;
		}
	}
}

void				move_fract(int x, int y, t_pack *pack, int power)
{
	int				i;
	double			s_x;
	double			s_y;

	i = -1;
	while (++i < 8)
	{
		if (S_WID / 2 < x - 4 || S_WID / 2 > x + 4)
		{
			s_x = ((x - (S_WID / 2)) * pack->aims[i].step);
			pack->aims[i].s_re += s_x / power;
			pack->aims[i].e_re += s_x / power;
		}
		if (S_HEI / 2 < y - 4 || S_HEI / 2 > y + 4)
		{
			s_y = ((y - (S_HEI / 2)) * pack->aims[i].step);
			pack->aims[i].s_im += s_y / power;
			pack->aims[i].e_im += s_y / power;
		}
	}
}

int					my_key_funct(int k, void *param)
{
	t_pack			*pack;
	int				i;

	pack = param;
	if (k == 53)
		exit(0);
	i = -1;
	if (k == 49)
	{
		while (++i < 8)
			pack->aims[i].tcol += 1;
	}
	if (k == 256)
		check_stop(pack);
	if (k == 86)
		change_n(pack, k);
	if (k == 88)
		change_n(pack, k);
	if (k > 122 && k < 127)
		key_mover(pack, k);
	thread_col_f(&(pack->aims));
	mlx_clear_window(pack->aims[0].mlx, pack->aims[0].win);
	draw(pack->aims);
	return (0);
}
