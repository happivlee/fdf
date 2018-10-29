/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 15:16:44 by vlee              #+#    #+#             */
/*   Updated: 2018/09/12 19:52:29 by vlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//0.6982 radians = 40 degrees
void	ft_xrotate(t_env **f)
{
	float	y;
	float	z;

	(*f)->i = 0;
	while ((*f)->i < (*f)->h)
	{
		(*f)->j = 0;
		while ((*f)->j < (*f)->w)
		{
			y = (*f)->cart[(*f)->i][(*f)->j].y;
			z = (*f)->cart[(*f)->i][(*f)->j].z;
			(*f)->cart[(*f)->i][(*f)->j].y = \
							(y * cos(0.6982) - z * sin(0.6982));
			(*f)->cart[(*f)->i][(*f)->j].z = \
							(y * sin(0.6982) + z * cos(0.6982));
			(*f)->j++;
		}
		(*f)->i++;
	}
}

//.0524 radians = 3 degrees
void	ft_yrotate(t_env **f)
{
	float	x;
	float	z;

	(*f)->i = 0;
	while ((*f)->i < (*f)->h)
	{
		(*f)->j = 0;
		while ((*f)->j < (*f)->w)
		{
			x = (*f)->cart[(*f)->i][(*f)->j].x;
			z = (*f)->cart[(*f)->i][(*f)->j].z;
			(*f)->cart[(*f)->i][(*f)->j].x = \
								(x * cos(0.0524) + z * sin(0.0524));
			(*f)->cart[(*f)->i][(*f)->j].z = \
								-(x * sin(0.0524)) + z * cos(0.0524);
			(*f)->j++;
		}
		(*f)->i++;
	}
}

//0.7854 radians = 45 degrees
void	ft_zrotate(t_env **f)
{
	float	x;
	float	y;

	(*f)->i = 0;
	while ((*f)->i < (*f)->h)
	{
		(*f)->j = 0;
		while ((*f)->j < (*f)->w)
		{
			x = (*f)->cart[(*f)->i][(*f)->j].x;
			y = (*f)->cart[(*f)->i][(*f)->j].y;
			(*f)->cart[(*f)->i][(*f)->j].x = \
							(x * cos(0.6982) - y * sin(0.6982));
			(*f)->cart[(*f)->i][(*f)->j].y = \
							(x * sin(0.6982) + y * cos(0.6982));
			(*f)->j++;
		}
		(*f)->i++;
	}
}

void	ft_rotate(t_env *f, t_hooks *hooks)
{
	ft_xrotate(&f);
	ft_yrotate(&f);
	ft_zrotate(&f);
}
