/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com_sum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkushche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 22:18:50 by dkushche          #+#    #+#             */
/*   Updated: 2018/01/10 22:18:51 by dkushche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphlib.h"

t_compl				com_sum(t_compl a, t_compl b)
{
	t_compl			i;

	i.re = a.re + b.re;
	i.im = a.im + b.im;
	return (i);
}