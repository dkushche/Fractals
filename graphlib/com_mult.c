/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkushche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 21:05:31 by dkushche          #+#    #+#             */
/*   Updated: 2018/01/10 21:05:31 by dkushche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphlib.h"

t_compl				com_mult(t_compl a, t_compl b)
{
	t_compl			i;

	i.re = a.re * b.re - a.im * b.im;
	i.im = a.re * b.im + a.im * b.re;
	return (i);
}