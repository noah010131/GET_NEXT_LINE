/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanypar <chanypar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:08:34 by chanypar          #+#    #+#             */
/*   Updated: 2023/12/02 16:09:34 by chanypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000000
# endif

char	*get_next_line(int fd);

char	*ft_strchr(const char *s, int c);

void	*ft_calloc(size_t nmenb, size_t size);

size_t	ft_strlen(const char *str);

char	*ft_strdup(const char *s);

char	*ft_strjoin(char const *s1, char const *s2);

#endif
