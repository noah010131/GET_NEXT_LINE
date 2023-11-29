/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanypar <chanypar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 21:07:32 by chanypar          #+#    #+#             */
/*   Updated: 2023/11/29 15:09:43 by chanypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_count_c(const char *s, int c)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s == (char)c)
			i++;
		s++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*str;
	char	*res;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	str = (char *)malloc(len_s1 + len_s2 + 1);
	if (str == 0)
		return (0);
	res = str;
	while (len_s1 && *s1)
	{
		*str = *s1;
		str++;
		s1++;
	}
	while (len_s2 && *s2)
	{
		*str = *s2;
		str++;
		s2++;
	}
	*str = '\0';
	return (res);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int		i;
	
	i = 0;
	while (*(src + i) && i < n)
	{
		*(dest + i) = *(src + i);
		i++;
	}
	if (i < n)
		*(dest + i) = '\0';
	return (dest);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	int		i;
	if (!s)
		return (NULL);
	str = (char *)malloc(ft_strlen((const char *)s) + 1);
	i = 0;
	if (str == 0)
		return (0);
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
