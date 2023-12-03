/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanypar <chanypar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 11:46:45 by chanypar          #+#    #+#             */
/*   Updated: 2023/12/03 13:09:32 by chanypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*put_stock(char *stock)
{
	int		i;
	int		j;
	int		len;
	char	*res;

	i = 0;
	len = ft_strlen(stock);
	while (stock[i] && stock[i] != '\n')
		i++;
	if (!stock[i])
	{
		free(stock);
		return (NULL);
	}
	i++;
	res = ft_calloc((len + i + 1), 1);
	j = 0;
	while (stock[i])
		res[j++] = stock[i++];
	free(stock);
	return (res);
}

char	*free_malloc(char **stock, char *buff)
{
	char	*temp;

	temp = ft_strjoin(*stock, buff);
	free(*stock);
	return (temp);
}

char	*read_buff(int fd, char *stock)
{
	char	*temp;
	int		i;

	temp = malloc(BUFFER_SIZE + 1);
	if (!temp)
		return (0);
	temp[0] = '\0';
	if (!stock)
	{
		stock = malloc(1);
		if (!stock)
			return (0);
		stock[0] = '\0';
	}
	i = 1;
	while (i > 0 && (!(ft_strchr(temp, '\n'))))
	{
		i = read(fd, temp, BUFFER_SIZE);
		temp[i] = 0;
		stock = free_malloc(&stock, temp);
	}
	free(temp);
	return (stock);
}

char	*get_next_line(int fd)
{
	static char	*stock[4096];
	char		*res;
	int			i;

	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	stock[fd] = read_buff(fd, stock[fd]);
	i = 0;
	if (!stock[fd] || !stock[fd][i])
		return (NULL);
	while (stock[fd][i] && stock[fd][i] != '\n')
		i++;
	res = ft_calloc(i + 2, 1);
	i = 0;
	while (stock[fd][i] && stock[fd][i] != '\n')
	{
		res[i] = stock[fd][i];
		i++;
	}
	if (stock[fd][i] && stock[fd][i] == '\n')
		res[i] = '\n';
	stock[fd] = put_stock(stock[fd]);
	return (res);
}
