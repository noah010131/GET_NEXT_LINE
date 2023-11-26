/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanypar <chanypar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:14:50 by chanypar          #+#    #+#             */
/*   Updated: 2023/11/26 20:51:26 by chanypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"
int	main(void)
{
	int	fd;
	char	*res;

	fd = open("test.c", O_RDONLY);
	printf("fd : %d\n", fd);
	if (fd < 0)
		return (0);
	do
	{
		res = get_next_line(fd);
		printf("res : %s\n", res);
	}
	while (res);
	close(fd);
	return (0);
}
