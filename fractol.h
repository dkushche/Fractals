/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkushche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 19:19:39 by dkushche          #+#    #+#             */
/*   Updated: 2018/01/10 19:19:40 by dkushche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "graphlib/graphlib.h"
# include <pthread.h>

# define S_HEI 600
# define S_WID 900
# define QUALITY 100
# define ZOOM 100
# define MOVE_P 5
# define N_OF_THEME 7
# define CHECK(x) if (!x) return (-1)
# define ACM "\x1b[35m"
# define ACR "\x1b[0m"
# define ACC "\x1b[36m"
# define ACY "\x1b[33m"

typedef struct		s_aim
{
	unsigned int	tcol;
	int				n;
	int				start_x;
	int				start_y;
	double			step;
	double			s_im;
	double			s_re;
	double			e_im;
	double			e_re;
	void			*mlx;
	void			*win;
	void			*im;
	char			*im_d;
	int				bpp;
	int				stop;
	int				sl;
	t_compl			par;
}					t_aim;

typedef	struct		s_pack
{
	t_aim			*aims;
}					t_pack;

int					sorry_mes();
int					thread_col_f(t_aim **aims);
void				*draw_fract(void *param);
void				zoom_fract(t_pack *pack, int in);
void				move_fract(int x, int y, t_pack *pack, int power);
int					my_key_funct(int keycode, void *param);
void				draw(t_aim *aim);
char				nic(int numb);
int					color_theme(int k, int col);
int					my_mouse_hook(int button, int x, int y, void *param);
t_aim				aim_init(int s_x, int s_y, void *mlx, void *win);
int					my_motion_notif(int x, int y, void *param);
t_aim				*aim_create(int numb, void **mlx, void *win);
void				check_stop(t_pack *pack);
int					my_destr_win(void *param);
int					mult_win_mode(int	*numb, int size, void *mlx);
int					fract_travka(t_compl z, t_compl c, int col);
int					fract_jul(t_compl z, t_compl c, int col);
int					fract_brain(t_compl z, t_compl c, int col);
int					fract_plane(t_compl z, t_compl c, int col);
int					fract_pep(t_compl z, t_compl c, int col);
void				change_n(t_pack *pack, int k);
void				key_mover(t_pack *pack, int k);

#endif
