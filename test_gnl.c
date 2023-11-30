/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanypar <chanypar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:14:50 by chanypar          #+#    #+#             */
/*   Updated: 2023/11/30 16:54:01 by chanypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

/*
int	main(void)
{
	int	fd;
	char	*str;

	fd = open("test.c", O_RDONLY);
	printf("fd : %d\n", fd);
	if (fd < 0)
		return (0);
	str = get_next_line(fd);
        printf("%s\n", str);
	free(str);
	close(fd);
	return (0);
}
*/

int main(void)
{
  int fd;
int i = 1;
  fd = open("test.txt", O_RDONLY);
  char *line = get_next_line(fd);
while (line)
{
  printf("%d : %s\n",i, line);
	i++;
free(line);
line = get_next_line(fd);
}
close(fd);
  return (0);
}
