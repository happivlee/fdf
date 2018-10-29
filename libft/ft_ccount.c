/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ccount.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 23:41:56 by vlee              #+#    #+#             */
/*   Updated: 2018/04/16 23:42:02 by vlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ccount(const char *s, int c)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (s[i] == c)
	{
		i++;
	}
	while (s[i] != c && s[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}