/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com_sub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkushche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 14:33:35 by dkushche          #+#    #+#             */
/*   Updated: 2018/01/14 14:33:36 by dkushche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphlib.h"

t_compl				com_sub(t_compl a, t_compl b)
{
	t_compl			i;

	i.re = a.re - b.re;
	i.im = a.im - b.im;
	return (i);
}
