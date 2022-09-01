/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaspar <algaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 19:33:14 by algaspar          #+#    #+#             */
/*   Updated: 2022/09/01 22:30:51 by algaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	ft_strlen(const char *s)
{
	if (*s)
		return (1 + ft_strlen(s + 1));
	return (0);
}

size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize)
	{
		while (src[i] && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

char	*ft_strdup(const char *s)
{
	char	*dst;

	dst = malloc(ft_strlen(s) + 1);
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, s, ft_strlen(s) + 1);
	return (dst);
}

int	ft_strcmp(const char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

void	*ft_malloc(size_t size)
{
	void *a;

	a = malloc(size);
	if (!a)
		exit(EXIT_FAILURE);
	return (a);
}