/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanypar <chanypar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:56:21 by chanypar          #+#    #+#             */
/*   Updated: 2023/11/26 21:40:26 by chanypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*stock_clear(char **s_ptr)
{
	char	*temp; // stock의 새 할당을 위함

	temp = ft_strdup(*s_ptr);
	while (**s_ptr)
	{
		**s_ptr = 0;
		(*s_ptr)++;
	}
	free (*s_ptr);
	while (*temp)
	{
		if (*temp == '\n') // '/n' 이 있다면 위 이후 복사
		{
			temp++;
			*s_ptr = ft_strdup(temp);
			free (temp);
			return (*s_ptr);
		}
		temp++;
	}
	free (temp);
	return (*s_ptr);
}
char	*check_res(char *stock, int i)
{
	char	**temp;
	char	*res;

	temp = NULL;
	if ((i % BUFF_SIZE) == 0) // buff 맨 뒤에 '\0' 이 잘 저장되어 있다면
		res = ft_strjoin(res, (char const *)stock);
	else // buff 처음이나 중간에 '\n' 이나 '\0' 이 저장되어 있다면	
	{
		res = malloc(i + 1);
		if (!res)
			return (0);
		res = ft_strncpy(res, stock, i); // '\n' 이나 '\0' 전까지 복사
		stock = stock_clear(&stock);
	}
	*temp = res; // temp 에 복사
	free(res);
	return (*temp);
}

char	*put_res(char *buff)
{
	int		i;
	static char	*stock;

	i = 0;
	if (stock == NULL)
	{
		stock = malloc(1);
		if (!stock)
			return (NULL);
		stock = NULL;
	}
	stock = ft_strjoin(stock, (char const *)buff);
	while (stock[i] && (stock[i] != '\n'))
		i++;
	return (check_res(stock, i));
}

char	*get_next_line(int fd)
{
	int	i;
	int	check_n;
	char	*res;
	char	buff[BUFF_SIZE + 1]; // 버퍼 할당 

	i = BUFF_SIZE;
	while (i == BUFF_SIZE && check_n != 0) 
	{	check_n = 0;
		i = read(fd, buff, BUFF_SIZE);
		if (i < 0)
			return(NULL);
		if (i == 0)
			return (res);
		buff[i] ='\0'; // 버퍼 맨 뒤 '\0' 할당
		if (ft_strchr(buff, '\n') != NULL )
			check_n = 1;
		res = put_res(buff); // 버퍼의 값 저장    
	}
	return (res);
}
