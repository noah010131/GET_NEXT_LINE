/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanypar <chanypar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:56:24 by chanypar          #+#    #+#             */
/*   Updated: 2023/12/04 16:52:10 by chanypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

// int	main()
// {
// 	int	i;
// 	// int	fd;
// 	char	*line;

// 	i = 1;
// 	// fd = open("get_next_line.c", O_RDONLY);
// 	line = get_next_line(0);
// 	// while (line)
// 	// {
// 		printf("%d : %s\n", i, line);
// 	// 	free(line);
// 	// 	line = get_next_line(1);
// 	// 	i++;
// 	// }
// 	// free(line);
// 	// close(fd);
// 	return (0);
// }

int	main()
{
	int	i;
	int	fd1;
	int	fd2;
	char	*line1;
	char	*line2;

	i = 1;
	fd1 = open("text1", O_RDONLY);
	fd2 = open("text2", O_RDONLY);
	line1 = get_next_line(fd1);
	line2 = get_next_line(fd2);
	while (line1 || line2)
	{
		printf("text1 : %d :%s\n", i, line1);
		printf("test2 :%d : %s\n", i, line2);
		free(line1);
		free(line2);
		line1 = get_next_line(fd1);
		line2 = get_next_line(fd2);
		i++;
	}
	free(line1);
	free(line2);
	close(fd1);
	close(fd2);
	return (0);
}

