/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_RGB.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkushche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 15:22:06 by dkushche          #+#    #+#             */
/*   Updated: 2018/01/06 15:22:07 by dkushche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int					rgb(int r, int g, int b)
{
	return (r * 256 * 256 + g * 256 + b);
}