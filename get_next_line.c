/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanypar <chanypar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 11:46:45 by chanypar          #+#    #+#             */
/*   Updated: 2023/12/02 16:40:21 by chanypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*put_stock(char *stock)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	while (stock[i] && stock[i] != '\n')
		i++;
	if (!stock[i])
	{
		free(stock);
		return (NULL);
	}
	i++;
	res = ft_calloc((ft_strlen(stock) - i + 1), 1);
	j = 0;
	while (stock[i])
		res[j++] = stock[i++];
	free(stock);
	return (res);
}

char	*free_malloc(char *stock, char *buff)
{
	char	*temp;

	temp = ft_strjoin(stock, buff);
	free(stock);
	return (temp);
}

char	*put_res(char *stock)
{
	char	*res;
	int		i;

	i = 0;
	if (!stock[i])
		return (NULL);
	while (stock[i] && stock[i] != '\n')
		i++;
	res = ft_calloc(i + 2, 1);
	i = 0;
	while (stock[i] && stock[i] != '\n')
	{
		res[i] = stock[i];
		i++;
	}
	if (stock[i] && stock[i] == '\n')
		res[i] = '\n';
	return (res);
}

char	*read_buff(int fd, char *stock)
{
	char	*temp;
	int		i;

	temp = ft_calloc(BUFFER_SIZE + 1, 1);
	if (stock == NULL)
	{
		stock = malloc(1);
		if (!stock)
			return (NULL);
		stock[0] = '\0';
	}
	i = 1;
	while (i > 0 && (!(ft_strchr(temp, '\n'))))
	{
		i = read(fd, temp, BUFFER_SIZE);
		temp[i] = 0;
		stock = free_malloc(stock, temp);
	}
	free(temp);
	return (stock);
}

char	*get_next_line(int fd)
{
	static char	*stock;
	char		*res;

	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	stock = read_buff(fd, stock);
	if (!stock)
		return (NULL);
	res = put_res(stock);
	stock = put_stock(stock);
	return (res);
}
