/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 15:22:05 by vlee              #+#    #+#             */
/*   Updated: 2018/09/12 20:31:34 by vlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "./minilibx_macos/mlx.h"

# define KEY_ENTER	36
# define KEY_ESC	52
# define KEY_MORE_1	69
# define KEY_MORE_2 24
# define KEY_LESS_1	78
# define KEY_LESS_2 27
# define KEY_TOP	126
# define KEY_LEFT	123
# define KEY_BOTTOM 125
# define KEY_RIGHT	124
# define KEY_D		2
# define KEY_C		8

typedef struct	s_hooks
{
	int		zr;
	int		yr;
	int		xr;
	int		xt;
	int		yt;
	int		zs;
}				t_hooks;

typedef struct	s_map
{
	int		**map;
	int		hmin;
	int		hmax;
	int		w;
	int		h;
	int		midx;
	int		midy;
	float	xpixelloc;
	float	ypixelloc;
}				t_map;

typedef struct	s_point
{
	float	x;
	float	y;
	float	z;
	float	rawz;
}				t_points;

typedef struct	s_bresen
{
	float	offset;
	float	threshold;
	float	adjust;
	float	delta;
	float	tmp;
	int		colorgrade;
	float	color;
	float	range;
	char	*str;
	char	**coord;
	char	*line;
}				t_bresen;

typedef struct	s_fdf
{
	t_hooks		*hooks;
	t_points	**cart;
	float		y1;
	float		x1;
	float		y2;
	float		x2;
	int			hmin;
	int			hmax;
	float		curr_z;
	float		next_z;
	int			w;
	int			h;
	int			big;
	int			gap;
	int			i;
	int			j;
	float		m;
	float		rise;
	float		run;
	float		max;
	float		maxside;
	void		*mlx;
	void		*win;
}				t_env;

void			ft_error(char *str);
void			ft_parse(char *av);
void			ft_zvalue(int fd, t_map *list);
int				ft_findw(char **coord);
void			ft_findwh(int fd, t_map *list);
void			ft_store(char *av, t_map *list);
void			ft_hooked(t_hooks **hooks);
t_env			*ft_makeenvironment(t_map *m);
void			ft_populate(t_env **fdf, t_map *m);
t_points		**ft_makecartesian(t_env *fdf, t_map *m);
void			ft_draw(t_env *fdf, t_hooks *hooks);
void			ft_rotate(t_env *fdf, t_hooks *hooks);
void			ft_translate(t_env **f, t_hooks *hooks);
void			ft_slopestraight(t_env *fdf);
void			ft_slopegradual(t_env *fdf, t_bresen *breezy);
void			ft_slopesharp(t_env *fdf, t_bresen *breezy);
int				ft_color(t_env *fdf, t_bresen *breezy, float distance);
void			ft_zvalue(int fd, t_map *list);

#endif
