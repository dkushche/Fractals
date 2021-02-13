/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkushche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 13:32:59 by dkushche          #+#    #+#             */
/*   Updated: 2017/11/03 13:32:59 by dkushche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putstr(char *str)
{
	char	*kek;

	if (str != NULL)
	{
		kek = str;
		while (*kek != '\0')
		{
			ft_putchar(*kek);
			kek = kek + 1;
		}
	}
}