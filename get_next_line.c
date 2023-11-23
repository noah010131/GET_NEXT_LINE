/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanypar <chanypar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:56:21 by chanypar          #+#    #+#             */
/*   Updated: 2023/11/23 17:13:09 by chanypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int	i;
	int	size;
	char	buff[1024]; // 버퍼 할당 

	i = read(fd, buff, sizeof(buff);
	if (i < 0)
		return(NULL);
	while (*buff == '\n' || *buff == '\0') // 파일의 '\0' 이나 '\n' 위치 저장
	{
		str++
		size++
	}
	
	// 버퍼 맨 뒤 '\0' 할당 (?)

}
