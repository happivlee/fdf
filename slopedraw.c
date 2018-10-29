/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slopedraw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 15:47:26 by vlee              #+#    #+#             */
/*   Updated: 2018/09/12 19:54:31 by vlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_slopestraight(t_env *fdf)
{
	float	tmp;

	tmp = 0;
	if (fdf->y2 < fdf->y1)
	{
		tmp = fdf->y1;
		fdf->y1 = fdf->y2;
		fdf->y2 = tmp;
	}
	while (fdf->y1 <= fdf->y2)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, fdf->x1, fdf->y1, 0x003366FF);
		fdf->y1++;
	}
}

void	ft_slopegradual(t_env *fdf, t_bresen *breezy)
{
	float y;

	breezy->delta = fabsf(fdf->m);
	y = fdf->y1;
	if (fdf->x2 < fdf->x1)
	{
		breezy->tmp = fdf->x1;
		fdf->x1 = fdf->x2;
		fdf->x2 = breezy->tmp;
		y = fdf->y2;
	}
	breezy->tmp = fdf->x1;
	breezy->range = (fdf->x2 - breezy->tmp);
	while (fdf->x1 < fdf->x2)
	{
		breezy->color = ft_color(fdf, breezy, (fdf->x1 - breezy->tmp));
		mlx_pixel_put(fdf->mlx, fdf->win, fdf->x1, y, breezy->color);
		breezy->offset += breezy->delta;
		if (breezy->offset >= breezy->threshold)
		{
			y += breezy->adjust;
			breezy->threshold += 1.0;
		}
		fdf->x1++;
	}
}

void	ft_slopesharp(t_env *fdf, t_bresen *breezy)
{
	float	x;

	breezy->delta = fabsf(fdf->run / fdf->rise);
	x = fdf->x1;
	if (fdf->y2 < fdf->y1)
	{
		breezy->tmp = fdf->y1;
		fdf->y1 = fdf->y2;
		fdf->y2 = breezy->tmp;
		x = fdf->x2;
	}
	breezy->tmp = fdf->y1;
	breezy->range = (fdf->y2 - breezy->tmp);
	while (fdf->y1 < fdf->y2)
	{
		breezy->color = ft_color(fdf, breezy, (fdf->y1 - breezy->tmp));
		mlx_pixel_put(fdf->mlx, fdf->win, x, fdf->y1, breezy->color);
		breezy->offset += breezy->delta;
		if (breezy->offset >= breezy->threshold)
		{
			x += breezy->adjust;
			breezy->threshold += 1;
		}
		fdf->y1++;
	}
}
