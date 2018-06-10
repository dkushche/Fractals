/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphlib.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkushche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 15:15:07 by dkushche          #+#    #+#             */
/*   Updated: 2018/01/06 15:15:07 by dkushche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
	Правило работы с матрицами 
	сначала масштабируем, затем вращаем, перемещаем и наконец проецируем

	функция draw_pixel может быть дополнена всякими шейднрами и прочей хелпой

	Будет настроение перепиши умножение матриц и вбей место вектора столбца вектор строку

	Standart настраивается под каждый проект 
*/

#ifndef GRAPHLIB_H
# define GRAPHLIB_H

# include <math.h>
# include <stdlib.h>
# include "minilibx/mlx.h"
# include "../libft/libft.h"

typedef unsigned int color;

typedef	struct		complex
{
	double			re;
	double			im;
}					t_compl;

typedef struct		point
{
	int				x;
	int				y;
	int				z;
	color			p_color;
}					t_point;

typedef struct		matrix
{
	double			**data;
	unsigned int	rows;
	unsigned int	colum;
}					t_matrix;

typedef struct		camera
{
	int				x;
	int				y;
	double			z;
	double			*angles;
}					t_camera;

typedef	struct		sandart
{
	void			*mlx;
	void			*win;
	int				s_height;
	int				s_width;
}					t_stand;

int					rgb(int r, int g, int b);
t_point				mtp(t_matrix mtx, int color);
color				atocol(char	*arr);
t_camera			cam_init(int x, int y, double z);
t_point				pnt_init(int x, int y, int z, int color);
t_matrix			wrt_pnt(double x, double y, double z);
t_matrix			create_mtx(unsigned int rows, unsigned int colum);
t_matrix			mtx_mult(t_matrix fm, t_matrix *sm, int back);
t_matrix			roty(double angle, t_matrix *input, int back);
t_matrix			rotx(double angle, t_matrix *input, int back);
t_matrix			rotz(double angle, t_matrix *input, int back);
t_matrix			sizing(double times, t_matrix *input, int back);
t_matrix			move(t_point point_vec, t_matrix *input, int back);
void				free_mtx(t_matrix *mtx);
int					check_bord2d(t_point point, t_stand set);
void				pnt_swap(t_point **a, t_point **b);
int					vert_straight(t_stand set, t_point start, t_point end);
void				line_loop(t_stand set, t_matrix *points, color *obj_col, int number);
int					line2d(t_stand set, t_point start, t_point end);
int					grad(t_point start, t_point end, int change);
void				fill_quad(t_stand set, t_point start, t_point end);
void				drwpxl(t_stand set, int x, int y, color mycol);
t_compl				com_mult(t_compl a, t_compl b);
t_compl				com_sum(t_compl a, t_compl b);
double				com_mod(t_compl a);
t_compl				com_init(double re, double im);
t_compl				com_sub(t_compl a, t_compl b);
t_compl				com_div(t_compl a, t_compl b);

#endif
