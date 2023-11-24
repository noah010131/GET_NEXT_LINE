/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanypar <chanypar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:14:50 by chanypar          #+#    #+#             */
/*   Updated: 2023/11/24 11:33:57 by chanypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int	main(void)
{
	int	fd;
	int	bytes_read;
	char	buff[100];

	fd = open("test.c", O_RDONLY);
	if (fd < 0)
		return (0);
	bytes_read = read(fd, buff, sizeof(buff));
	if (bytes_read < 0)
		return (0);
	write(1, buff, bytes_read);
	close(fd);
	return (0);
}
