/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 16:48:54 by vlee              #+#    #+#             */
/*   Updated: 2018/09/12 20:13:59 by vlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_color3(t_env *fdf, t_bresen *breezy, float distance)
{
	if (distance <= (breezy->range * 0.10))
		return (0xff);
	else if (distance <= (breezy->range * 0.20))
		return (0x8b008b); //dark magenta
	else if (distance <= (breezy->range * 0.30))
		return (0x8b8b); //cyan
	else if (distance <= (breezy->range * 0.40))
		return (0x90ee90); //light green
	else if (distance <= (breezy->range * 0.50))
		return (0x6400); // green
	else if (distance <= (breezy->range * 0.60))
		return (0x6400); // green
	else if (distance <= (breezy->range * 0.70))
		return (0x90ee90); //light green
	else if (distance <= (breezy->range * 0.80))
		return (0x8b8b); //cyan
	else if (distance <= (breezy->range * 0.90))
		return (0x8b008b); //dark magenta
	else if (distance <= breezy->range)
		return (0x6495ed); //cornflower blue
	return (0x8b8b); //cyan
}

int	ft_color2(t_env *fdf, t_bresen *breezy, float distance)
{
	if (distance <= (breezy->range * 0.10))
		return (0x8b); //dark blue
	else if (distance <= (breezy->range * 0.20))
		return (0x6495ed); //cornflower blue
	else if (distance <= (breezy->range * 0.30))
		return (0x8b8b); //cyan
	else if (distance <= (breezy->range * 0.40))
		return (0x90ee90); //light green
	else if (distance <= (breezy->range * 0.50))
		return (0x6400); //green
	else if (distance <= (breezy->range * 0.60))
		return (0x006600FF); //purple
	else if (distance <= (breezy->range * 0.70))
		return (0x8b008b); //dark magenta
	else if (distance <= (breezy->range * 0.80))
		return (0x6495ed); //cornflower blue
	else if (distance <= (breezy->range * 0.90))
		return (0x778899); //light slate grey
	else if (distance <= breezy->range)
		return (0x6400); //green
	return (0x8b8b); //cyan
}

int	ft_color1(t_env *fdf, t_bresen *breezy, float distance)
{
	if (distance <= (breezy->range * 0.10))
		return (0x6400); //green
	else if (distance <= (breezy->range * 0.20))
		return (0x778899); //light slate grey
	else if (distance <= (breezy->range * 0.30))
		return (0x6495ed); //cornflower blue
	else if (distance <= (breezy->range * 0.40))
		return (0x8b008b); //dark magenta
	else if (distance <= (breezy->range * 0.50))
		return (0x006600FF); //purple
	else if (distance <= (breezy->range * 0.60))
		return (0x6400); //green
	else if (distance <= (breezy->range * 0.70))
		return (0x90ee90); //light green
	else if (distance <= (breezy->range * 0.80))
		return (0x8b8b); //cyan
	else if (distance <= (breezy->range * 0.90))
		return (0x6495ed); //cornflower blue
	else if (distance <= breezy->range)
		return (0x8b); //dark blue
	return (0x8b8b);
}

int	ft_color(t_env *fdf, t_bresen *breezy, float distance)
{
	if ((fdf->next_z || fdf->curr_z) > fdf->hmin)
	{
		if (fdf->curr_z == fdf->next_z)
			return (ft_color3(fdf, breezy, distance));
		if (fdf->curr_z < fdf->next_z)
			return (ft_color1(fdf, breezy, distance));
		else if (fdf->curr_z > fdf->next_z)
			return (ft_color2(fdf, breezy, distance));
	}
	return (0x8b8b);
}
