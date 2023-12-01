/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanypar <chanypar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:56:21 by chanypar          #+#    #+#             */
/*   Updated: 2023/12/01 13:38:53 by chanypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*free_malloc(char *arr, int i)
{
	char	*temp;

	temp = ft_strdup(arr);
	free (arr);
	arr = ft_strdup(temp + (i + 1));
	free (temp);
	return (arr);
}

char	*put_res(char **stock, int i)
{
	char	*res;

 	res = NULL;
	if ((ft_count_c(*stock, '\n'))) // buff 맨 뒤에 '\0' 이 잘 저장되어 있다면
	{
		res = ft_substr(*stock, 0,  i + 1); // '\n' 까지  '\0' 전까지 복사
		*stock = free_malloc(*stock, i);
	}
	return (res);
}

char	*put_stock(char *buff)
{
	int		i;
	static char	*stock;
	char	*res;
	char	*temp;

	i = 0;
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
		if (check_n > 0)//read 함수가 실행될 때
			buff[0] = '\0';
		else
			check_n = ft_count_c(buff, '\n');
		res = put_stock(buff); // 버퍼의 값 저장
		check_n--;
	}
	return (res);
}
