/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkushche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 18:01:41 by dkushche          #+#    #+#             */
/*   Updated: 2017/10/25 18:01:42 by dkushche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_bzero(void *memptr, size_t num)
{
	char	*p;

	p = memptr;
	while (num)
	{
		*p = '\0';
		p = p + 1;
		num--;
	}
}
