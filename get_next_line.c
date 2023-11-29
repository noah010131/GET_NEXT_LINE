/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanypar <chanypar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:56:21 by chanypar          #+#    #+#             */
/*   Updated: 2023/11/29 15:50:58 by chanypar         ###   ########.fr       */
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
	if ((i % BUFF_SIZE) == 0 && i != 0) // buff 맨 뒤에 '\0' 이 잘 저장되어 있다면
		res = ft_strjoin(NULL, (char const *)stock);
	else // buff 처음이나 중간에 '\n' 이나 '\0' 이 저장되어 있다면	
	{
		res = malloc((i + 2) * sizeof(char));
		if (!res)
			return (0);
		ft_strncpy(res, stock, i + 1); // '\n' 까지  '\0' 전까지 복사
		res[ft_strlen(res)] = '\0';
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
	else
		stock = ft_strjoin(stock, (char const *)buff);
	while (stock[i] && (stock[i] != '\n'))
		i++;
	res = check_res(stock, i);
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
	while (i == BUFF_SIZE) 
	{
		if (check_n == 0)
			i = read(fd, buff, BUFF_SIZE);
		else
			check_n--;
		if (i <= 0)
			return(NULL);
		buff[i] ='\0'; // 버퍼 맨 뒤 '\0' 할당
		if (check_n == 0)
			check_n = ft_count_c(buff, '\n');
		res = put_res(buff); // 버퍼의 값 저장
		if (ft_count_c(res, '\n'))
			return (res);
	}
	return (res);
}
