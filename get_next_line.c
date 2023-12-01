/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanypar <chanypar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:56:21 by chanypar          #+#    #+#             */
/*   Updated: 2023/12/01 19:48:58 by chanypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_malloc(char *arr, int i)
{
	char	*temp;

	temp = ft_strdup(arr + (i + 1));
	free (arr);
	arr = temp;
	if (arr[0] == '\0')
	{
		free(arr);
		return (NULL);
	}
	return (arr);
}

char	*put_res(char **stock, int i)
{
	char	*res;

	res = NULL;
	if (ft_count_c(*stock, '\n')) // 뒤에 '\n'이 없는 텍스트도 다뤄야 함
	{
		res = ft_substr(*stock, 0, i + 1);
		*stock = free_malloc(*stock, i);
	}
	return (res);
}

char	*put_stock(char *buff)
{
	int			i;
	static char	*stock;
	char		*res;
	char		*temp;

	i = 0;
	res = NULL;
	if (stock == NULL)
		stock = ft_strdup(buff);
	else if (buff != NULL)
	{
		temp = ft_strjoin(stock, (char const *)buff);
		free(stock);
		stock = temp;
	}
	while (stock[i] && (stock[i] != '\n'))
		i++;
	res = put_res(&stock, i);
	return (res);
}
#include <stdio.h>
#include <string.h>
char	*get_next_line(int fd)
{
	int				i;
	static int		check_n;
	char			*res;
	static char			buff[BUFFER_SIZE + 1];

//	buff = malloc(BUFFER_SIZE + 1);
//	free(buff);
	res = NULL;
	while (res == NULL)
	{
		i = BUFFER_SIZE + 1;
		if (check_n <= 0)
			i = read(fd, buff, BUFFER_SIZE);
		if (i <= 0)
			return (res);
		buff[i] = '\0';
		if (check_n > 0)
			buff[0] = '\0';
		else
			check_n = ft_count_c(buff, '\n');
		res = put_stock(buff);
		check_n--;
	}
	return (res);
}
