/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stepen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkushche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 23:11:10 by dkushche          #+#    #+#             */
/*   Updated: 2017/11/08 23:11:11 by dkushche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_stepen(int i, int st)
{
	if (i == 0)
		return (0);
	if (st == 0 || i == 1)
		return (1);
	while (st != 1)
	{
		i *= i;
		st--;
	}
	return (i);
}