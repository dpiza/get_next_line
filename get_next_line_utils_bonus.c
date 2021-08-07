/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 14:28:28 by dpiza             #+#    #+#             */
/*   Updated: 2021/08/07 14:25:23 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	int	i;

	if (!dst || !src)
		return (0);
	i = ft_strlen(src);
	if (size == 0)
		return (i);
	while (*src && size > 0)
	{
		*dst++ = *src++;
		size--;
	}
	if (size == 0)
		dst--;
	*dst = '\0';
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	is;

	is = ft_strlen(s);
	while (*s != (char)c && is-- > 0)
		s++;
	if (!*s && c)
		return (NULL);
	return ((char *)s);
}

char	*ft_strdup(const char *s)
{
	char	*pret;

	pret = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!pret)
		return (NULL);
	ft_strlcpy(pret, s, (ft_strlen(s) + 1));
	return (pret);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	is1;
	size_t	is2;
	char	*dest;
	char	*tdest;

	if (!s1 || !s2)
		return (NULL);
	is1 = ft_strlen(s1);
	is2 = ft_strlen(s2);
	dest = (char *)malloc((is1 + is2 + 1) * sizeof(char));
	if (!dest)
	{
		return (NULL);
	}
	tdest = dest;
	while (*s1)
		*tdest++ = *s1++;
	while (*s2)
		*tdest++ = *s2++;
	*tdest = '\0';
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	char	*tdest;
	size_t	size;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		size = 0;
	else if (ft_strlen(s) - start < len)
		size = ft_strlen(s) - start;
	else
		size = len;
	dest = (char *)malloc((size + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	tdest = dest;
	s += start;
	while (*s && size > 0)
	{
		*tdest++ = *s++;
		size--;
	}
	*tdest = '\0';
	return (dest);
}
