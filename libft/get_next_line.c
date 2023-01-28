/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 22:31:27 by obahi             #+#    #+#             */
/*   Updated: 2023/01/26 22:37:19 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*get_next_line(int fd)
{
	char	c[1];
	char	*line;
	char	*tmp;
	int		count;

	line = 0;
	tmp = 0;
	if (fd < 0 || read(fd, c, 0) < 0)
		return (0);
	count = read(fd, c, 1);
	while (count > 0)
	{
		tmp = line;
		line = ft_strjoin(line, c);
		if (tmp)
			free(tmp);
		if (*c == '\n')
			break;
		count = read(fd, c, 1);
	}
	return (line);
}
