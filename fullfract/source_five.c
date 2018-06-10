/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source_five.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkushche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 17:57:13 by dkushche          #+#    #+#             */
/*   Updated: 2018/01/17 17:57:13 by dkushche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int					fract_jul(t_compl z, t_compl c, int col)
{
	int			k;
	t_compl		p;

	k = 0;
	while (k < QUALITY)
	{
		if (com_mod(z) < 4)
		{
			p = com_mult(com_mult(com_mult(com_mult(z, z), z), z), z);
			z = com_sum((com_mult(p, z)), c);
		}
		else
			return (color_theme(k, col));
		k++;
	}
	return (0);
}

int					fract_brain(t_compl z, t_compl c, int col)
{
	int			k;

	k = 0;
	while (k < QUALITY)
	{
		if (com_mod(z) < 4)
		{
			z.re = fabs(z.re);
			z = com_sum((com_mult(z, z)), c);
		}
		else
			return (color_theme(k, col));
		k++;
	}
	return (0);
}

int					fract_plane(t_compl z, t_compl c, int col)
{
	int			k;

	k = 0;
	while (k < QUALITY)
	{
		if (com_mod(z) < 4)
		{
			z.re = fabs(z.re);
			z.im = fabs(z.im);
			z = com_sum((com_mult(z, z)), c);
		}
		else
			return (color_theme(k, col));
		k++;
	}
	return (0);
}

int					fract_pep(t_compl z, t_compl c, int col)
{
	int				k;
	t_compl			a;
	t_compl			zxf;

	k = 0;
	a = com_init(1, 0);
	while (k < QUALITY)
	{
		if (com_mod(z) < 4)
		{
			zxf = com_mult(z, z);
			z = com_div(com_mult(z, z), com_sum(com_sum(a, z), zxf));
			z = com_sum(z, c);
		}
		else
			return (color_theme(k, col));
		k++;
	}
	return (0);
}

void				change_n(t_pack *pack, int k)
{
	int				i;

	i = -1;
	if (k == 86)
	{
		while (++i < 8)
		{
			if (pack->aims[i].n - 1 > 0)
				pack->aims[i].n--;
			else
				pack->aims[i].n = 8;
		}
	}
	else
	{
		while (++i < 8)
		{
			if (pack->aims[i].n + 1 < 9)
				pack->aims[i].n++;
			else
				pack->aims[i].n = 1;
		}
	}
}
