/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com_div.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkushche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 14:45:02 by dkushche          #+#    #+#             */
/*   Updated: 2018/01/14 14:45:03 by dkushche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphlib.h"

t_compl				com_div(t_compl a, t_compl b)
{
	t_compl			i;

	i.re = (a.re * b.re + a.im * b.im) / (b.re * b.re + b.im * b.im);
	i.im = (b.re * a.im - b.im * a.re) / (b.re * b.re + b.im * b.im);
	return (i);
}
