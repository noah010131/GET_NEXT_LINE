/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanypar <chanypar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:14:50 by chanypar          #+#    #+#             */
/*   Updated: 2023/11/27 15:36:05 by chanypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"
int	main(void)
{
	int	fd;
	int	n;

	fd = open("test.c", O_RDONLY);
	printf("fd : %d\n", fd);
	n = 0;
	if (fd < 0)
		return (0);
        printf("%s\n", get_next_line(fd));
	close(fd);
	return (0);
}
