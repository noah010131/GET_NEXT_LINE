/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanypar <chanypar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:06:02 by chanypar          #+#    #+#             */
/*   Updated: 2023/12/01 18:26:44 by chanypar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif
char	*get_next_line(int fd);

int		ft_count_c(const char *s, int c);

char	*ft_strjoin(char const *s1, char const *s2);

char    *ft_substr(char const *s, unsigned int start, size_t len);

char	*ft_strdup(const char *s);

size_t	ft_strlen(const char *str);

#endif
