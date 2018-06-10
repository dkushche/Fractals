/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkushche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 19:19:30 by dkushche          #+#    #+#             */
/*   Updated: 2018/01/10 19:19:31 by dkushche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int				fract_h(t_compl z, unsigned int powz, int col)
{
	t_compl		def;
	t_compl		t[3];
	int			i;
	int			k;

	k = -1;
	t[1] = com_init(-1, 0);
	t[2] = com_init(powz, 0);
	while (++k < QUALITY)
	{
		i = 0;
		def = com_init(1, 0);
		t[0] = com_init(1, 0);
		while (++i < (int)(powz))
		{
			t[0] = com_mult(z, t[0]);
			def = com_mult(z, def);
		}
		t[0] = com_mult(z, t[0]);
		if (com_mod(z) < 100)
			z = com_sub(z, com_div(com_sub(t[0], t[1]), com_mult(t[2], def)));
		else
			return (color_theme(k, col));
	}
	return (0);
}

int				fract_col(t_compl z, t_compl c, int col)
{
	int			k;

	k = 0;
	while (k < QUALITY)
	{
		if (com_mod(z) < 4)
			z = com_sum((com_mult(z, z)), c);
		else
			return (color_theme(k, col));
		k++;
	}
	return (0);
}

void			cnv(int x, int y, t_aim *aim, t_compl z)
{
	int			dt;
	t_compl		p;

	p = com_init(0, 0);
	dt = ((y - aim->start_y) * S_WID / 4 + (x - aim->start_x)) * 4;
	if (aim->n == 1)
		*(int *)(aim->im_d + dt) = fract_col(p, z, aim->tcol);
	if (aim->n == 2)
		*(int *)(aim->im_d + dt) = fract_col(z, aim->par, aim->tcol);
	if (aim->n == 3)
		*(int *)(aim->im_d + dt) = fract_h(z, 3, aim->tcol);
	if (aim->n == 4)
		*(int *)(aim->im_d + dt) = fract_travka(z, aim->par, aim->tcol);
	if (aim->n == 5)
		*(int *)(aim->im_d + dt) = fract_jul(z, aim->par, aim->tcol);
	if (aim->n == 6)
		*(int *)(aim->im_d + dt) = fract_brain(z, aim->par, aim->tcol);
	if (aim->n == 7)
		*(int *)(aim->im_d + dt) = fract_plane(z, aim->par, aim->tcol);
	if (aim->n == 8)
		*(int *)(aim->im_d + dt) = fract_pep(z, aim->par, aim->tcol);
}

void			*draw_fract(void *param)
{
	t_aim		*aim;
	t_compl		z;
	double		i;
	double		j;
	int			xy[2];

	aim = param;
	j = aim->s_im + (aim->step * aim->start_y);
	xy[1] = aim->start_y;
	while (xy[1] < aim->start_y + (S_HEI / 2))
	{
		i = aim->s_re + (aim->step * aim->start_x);
		xy[0] = aim->start_x;
		while (xy[0] < aim->start_x + (S_WID / 4))
		{
			z.re = i;
			z.im = j;
			cnv(xy[0], xy[1], aim, z);
			xy[0]++;
			i += aim->step;
		}
		xy[1]++;
		j += aim->step;
	}
	pthread_exit(NULL);
}

int				main(int argc, char **argv)
{
	void			*mlx;
	int				*numbs;
	int				i;

	if (argc < 2)
		return (sorry_mes());
	numbs = (int *)malloc(sizeof(int) * (argc - 1));
	i = 0;
	while (++i < argc)
	{
		numbs[i - 1] = ft_atoi(argv[i]);
		if (numbs[i - 1] < 1 || numbs[i - 1] > 8)
			return (sorry_mes());
	}
	mlx = mlx_init();
	return (mult_win_mode(numbs, argc - 1, mlx));
}
