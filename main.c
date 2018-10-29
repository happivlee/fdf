/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 15:51:26 by vlee              #+#    #+#             */
/*   Updated: 2018/09/12 20:28:37 by vlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error(char *str)
{
	ft_putendl(str);
	exit(0);
}

int		my_key_funct(int keycode, void *param)
{
	ft_putstr("Keyevent: ");
	ft_putendl(ft_itoa(keycode));
	if (keycode == 53)
		exit(0);
	return (0);
}

int		main(int ac, char **av)
{
	t_map	*m;
	t_env	*fdf;
	t_hooks	*hooks;

	if (ac != 2)
		ft_error("Error: Invalid Map Arg");
	ft_parse(av[1]);
	if (!(m = (t_map *)malloc(sizeof(t_map))))
		ft_error("Error: Malloc");
	ft_store(av[1], m);
	fdf = ft_makeenvironment(m);
	ft_draw(fdf, fdf->hooks);
	mlx_key_hook(fdf->win, my_key_funct, 0);
	mlx_loop(fdf->mlx);
	return (0);
}
