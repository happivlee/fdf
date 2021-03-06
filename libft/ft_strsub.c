/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 15:58:58 by vlee              #+#    #+#             */
/*   Updated: 2018/07/23 16:41:36 by vlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *result;

	if (s == NULL)
		return (NULL);
	result = ft_memalloc(len + 1);
	if (result == NULL)
		return (NULL);
	result = ft_strncpy(result, &s[start], len);
	result[len + 1] = '\0';
	return (result);
}
