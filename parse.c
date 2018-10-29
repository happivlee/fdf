/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 15:54:52 by vlee              #+#    #+#             */
/*   Updated: 2018/09/12 20:20:43 by vlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_checkline(char *s)
{
	int	i;

	i = 0;
	if (!*s)
		ft_error("Error: Line read");
	while (s[i] != '\0')
	{
		if (ft_isalpha(s[i]))
			ft_error("Error: Found alphabet chars");
		if ((s[i] == '-' && !(ft_isdigit(s[i + 1]))) || s[i] == '\t')
			ft_error("Error: Found Forbidden Characters");
		i++;
	}
}

void	ft_checkwidth(int fd, int w, int w1, t_bresen *var)
{
	if (ft_get_next_line(fd, &(var->line)))
	{
		ft_checkline(var->line);
		if ((var->coord = ft_strsplit(var->line, ' ')) == NULL || !*var->coord)
			ft_error("Error: content");
		if (!(w = ft_findw(var->coord)))
			ft_error("Error: width");
		free(var->coord);
		free(var->line);
	}
	else
		ft_error("Empty File");
	while (ft_get_next_line(fd, &var->line))
	{
		ft_checkline(var->line);
		if ((var->coord = ft_strsplit(var->line, ' ')) == NULL || !*var->coord)
			ft_error("Error: content");
		w1 = ft_findw(var->coord);
		if (w != w1)
			ft_error("Error: Width uneven");
		free(var->coord);
		free(var->line);
	}
}

void	ft_parse(char *av)
{
	t_bresen	var;
	int			w;
	int			w1;
	int			fd;

	w1 = 0;
	w = 0;
	if ((var.str = ft_strstr(av, ".fdf")) == 0)
		ft_error("Error: Filename");
	if ((fd = open(av, O_RDONLY)) < 0)
		ft_error("Error: Opening\n");
	ft_checkwidth(fd, w, w1, &var);
}
