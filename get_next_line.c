/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanypar <chanypar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:56:21 by chanypar          #+#    #+#             */
/*   Updated: 2023/11/29 17:41:13 by chanypar         ###   ########.fr       */
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
	*s_ptr = NULL;
	i = 0;
	while (temp[i])
	{
		if (temp[i] == '\n') // '\n' 이 있다면 위 이후 복사
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
	char	*p;

	p = malloc((ft_strlen(res) + 1) * sizeof(char));
	if (!p)
		return (0);
	ft_strncpy(p, res, ft_strlen(res));
	p[ft_strlen(res)] = '\0';	
	free(res);
	
	return (p);
	
}

char	*check_res(char *stock, int i)
{
	char	*res;

 	res = NULL;
	if ((i % BUFFER_SIZE) == 0 && i != 0) // buff 맨 뒤에 '\0' 이 잘 저장되어 있다면
		res = ft_strjoin(NULL, (char const *)stock);
	else // buff 처음이나 중간에 '\n' 이나 '\0' 이 저장되어 있다면	
	{
		res = malloc((i + 2) * sizeof(char));
		if (!res)
			return (0);
		ft_strncpy(res, stock, i + 1); // '\n' 까지  '\0' 전까지 복사
		res[i + 1] = '\0';
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
		stock = ft_strdup(buff);
	else if (buff != NULL) 
		stock = ft_strjoin(stock, (char const *)buff);
	while (stock[i] && (stock[i] != '\n'))
		i++;
	res = check_res(stock, i);
	return (res);
}

char	*get_next_line(int fd)
{
	int	i;
	static int	check_n;
	char	*res;
	char	buff[BUFFER_SIZE + 1]; // 버퍼 할당 
	

	res = NULL;
	while (!(ft_count_c(res, '\n'))) // 받은 res안에 '\n'이 있으면 반환 
	{
		i = BUFFER_SIZE + 1; // read 가 실행됬는 지 flag
		if (check_n <= 0)
			i = read(fd, buff, BUFFER_SIZE);
		if (i <= 0)
			return(NULL);
		buff[i] ='\0'; // 버퍼 맨 뒤 '\0' 할당
		if (i <= BUFFER_SIZE)//read 함수가 실행될 때
		{
			check_n = ft_count_c(buff, '\n');
			res = put_res(buff); // 버퍼의 값 저장
		}
		else
			res = put_res(NULL);
		check_n--;
	}
	return (res);
}
