/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanypar <chanypar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:56:21 by chanypar          #+#    #+#             */
/*   Updated: 2023/11/24 18:45:26 by chanypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*put_res(char *str)
{
	int		i;
	static char	*dest;
	char	*res;

	i = 0;
	dest = malloc(BUFF_SIZE + 1); // 사이즈를 얼마로 줘야할까?
	if (!dest)
		return (0);
	if (*dest) // dest에 값이 있다면 strjoin
		ft_strjoin(dest, str);
	else 
		ft_strncpy(dest, str, BUFF_SIZE);
	dest[BUFF_SIZE + 1] = '\0';
	while (dest[i] && (dest[i] != '\n'))
		i++;
	res = malloc(i) //크기 할당
	ft_strncpy(res, dest, i);	
	free(dest);
	return (res);
}

char	*stock_buff(char *buff)
{
	char	*res;
//	char	*str;
//	int	i;

//	i = 0;
//	while (buff[i] && buff[i] != '\n')
//		i++;
//	str = (char *)malloc(i + 1);
//	if (!str)
// 		return (0);
//	str = strncpy(str, buff, );
	res = put_res(buff);
	free(str); 
	return (res);
}	

char	*get_next_line(int fd)
{
	int	i;
	int	size;
	int	check_n;
	char	buff[BUFF_SIZE + 1]; // 버퍼 할당 

	i = BUFF_SIZE;
	while (i == BUFF_SIZE && check_n != 0) 
	{	check_n = 0;
		i = read(fd, buff, BUFF_SIZE);
		if (i < 0)
			return(NULL);
		buff[i] ='\0';// 버퍼 맨 뒤 '\0' 할당
		if (ft_strchr != NULL )
			check_n = 1;
		res = stock_buff(buff); // 버퍼의 값 저장    
	}
	return (res);
}
