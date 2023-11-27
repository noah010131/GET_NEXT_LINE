/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanypar <chanypar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:56:21 by chanypar          #+#    #+#             */
/*   Updated: 2023/11/27 15:34:30 by chanypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*stock_clear(char **s_ptr)
{
	char	*temp;  // stock의 새 할당을 위함
	int	i;
	
	
	temp = ft_strdup(*s_ptr);
	free (*s_ptr);
	i = 0;
	while (temp[i])
	{
		if (temp[i] == '\n') // '/n' 이 있다면 위 이후 복사
		{
			i++;
			*s_ptr = ft_strdup(temp + i);
			free (temp);
			return (*s_ptr);
		}
		i++;
	}
	free (temp);
	return (*s_ptr);
}

char	*free_res(char *res)
{
	char	temp[ft_strlen(res)];
	char	*p;

	temp[ft_strlen(res)] = '\0';	
	p = ft_strncpy(temp, res, ft_strlen(res));
	free(res);
	
	printf("2%s\n", p);
	return (p);
	
}

char	*check_res(char *stock, int i)
{
	char	*res;

	res = NULL;
	if ((i % BUFF_SIZE) == 0) // buff 맨 뒤에 '\0' 이 잘 저장되어 있다면
		res = ft_strjoin(res, (char const *)stock);
	else // buff 처음이나 중간에 '\n' 이나 '\0' 이 저장되어 있다면	
	{
		res = malloc(i + 1);
		if (!res)
			return (0);
		res = ft_strncpy(res, stock, i); // '\n' 이나 '\0' 전까지 복사
		printf("1%s\n", res);
		stock = stock_clear(&stock);
	}
	return (free_res(res));
}

char	*put_res(char *buff)
{
	int		i;
	static char	*stock;
	char	*res;

	i = 0;
	if (stock == NULL)
	{
		stock = malloc(1);
		if (!stock)
			return (NULL);
//		stock = NULL;
	}
	stock = ft_strjoin(stock, (char const *)buff);
	while (stock[i] && (stock[i] != '\n'))
		i++;
	res = check_res(stock, i);
	printf("3%s\n", res);
	return (res);
}

char	*get_next_line(int fd)
{
	int	i;
	int	check_n;
	char	*res;
	char	buff[BUFF_SIZE + 1]; // 버퍼 할당 

	i = BUFF_SIZE;
	check_n = 0;
	while (i == BUFF_SIZE && check_n == 0) 
	{	check_n = 0;
		i = read(fd, buff, BUFF_SIZE);
		if (i < 0)
			return(NULL);
		if (i == 0)
			return ("\0");
		buff[i] ='\0'; // 버퍼 맨 뒤 '\0' 할당
		if (ft_strchr(buff, '\n') != NULL )
			check_n = 1;
		res = put_res(buff); // 버퍼의 값 저장    
		printf("4%s\n", res);
	}	
	printf("5%s\n", res);
	return (res);
}
