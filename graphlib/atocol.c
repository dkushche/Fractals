/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atocol.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkushche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 15:26:16 by dkushche          #+#    #+#             */
/*   Updated: 2018/01/06 15:26:16 by dkushche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphlib.h"

color				atocol(char *arr)
{
	int				i;
	int				mnoj;
	color			result;

	i = 8;
	if (ft_strlen(arr) != 8)
		return (0xFFFFFF);
	mnoj = 1;
	result = 0;
	while (--i != 1)
	{
		if (arr[i] >= '0' && arr[i] <= '9')
			result += (arr[i] - '0') * mnoj;
		else if (arr[i] >= 'A' && arr[i] <= 'F')
			result += (arr[i] - 55) * mnoj;
		else if (arr[i] >= 'a' && arr[i] <= 'f')
			result += (arr[i] - 87) * mnoj;
		else
			return (0xFFFFFF);
		mnoj *= 16;
	}
	return (result);
}
