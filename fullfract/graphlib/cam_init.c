/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkushche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 15:28:13 by dkushche          #+#    #+#             */
/*   Updated: 2018/01/06 15:28:13 by dkushche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphlib.h"

t_camera			cam_init(int x, int y, double z)
{
	t_camera		camera;

	camera.x = x;
	camera.y = y;
	camera.z = z;
	camera.angles = (double *)malloc(sizeof(double) * 3);
	camera.angles[0] = 0;
	camera.angles[1] = 0;
	camera.angles[2] = 0;
	return (camera);
}
