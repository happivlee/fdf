/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 16:47:34 by vlee              #+#    #+#             */
/*   Updated: 2018/09/12 19:58:59 by vlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		*ft_atoimap(char **s, int w)
{
	int		*map;
	int		j;

	j = 0;
	map = (int *)malloc(sizeof(int) * (w + 1));
	while (j < w)
	{
		map[j] = ft_atoi(&s[j][0]);
		j++;
	}
	return (map);
}

void	ft_zvalue(int fd, t_map *m)
{
	int		x;
	int		j;
	char	**coord;
	char	*line;

	x = 0;
	m->hmax = 0;
	m->hmin = 0;
	m->map = (int **)malloc(sizeof(int *) * (m->h + 1));
	while (ft_get_next_line(fd, &line))
	{
		coord = ft_strsplit(line, ' ');
		m->map[x] = ft_atoimap(coord, m->w);
		free(coord);
		free(line);
		j = 0;
		while (j < m->w)
		{
			m->hmax = m->map[x][j] > m->hmax ? m->map[x][j] : m->hmax;
			m->hmin = m->map[x][j] < m->hmin ? m->map[x][j] : m->hmin;
			j++;
		}
		x++;
	}
	close(fd);
}

int		ft_findw(char **coord)
{
	int	x;

	x = 0;
	while (coord[x])
		x++;
	return (x);
}

void	ft_findwh(int fd, t_map *list)
{
	char	*line;
	char	**coord;
	int		y;

	y = 0;
	if (ft_get_next_line(fd, &line))
	{
		y++;
		coord = ft_strsplit(line, ' ');
		list->w = ft_findw(coord);
		free(coord);
		free(line);
	}
	while (ft_get_next_line(fd, &line))
	{
		y++;
		free(line);
	}
	list->h = y;
	close(fd);
}

void	ft_store(char *av, t_map *list)
{
	int		fd;

	if ((fd = open(av, O_RDONLY)) == -1)
		ft_error("Error Opening\n");
	ft_findwh(fd, list);
	fd = open(av, O_RDONLY);
	ft_zvalue(fd, list);
}
