/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 22:31:27 by obahi             #+#    #+#             */
/*   Updated: 2023/01/25 23:40:38 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*get_next_line(int fd)
{
	char	c;
	int		count;
	char	*line;
	char	*tmp;

	line = 0;
	tmp = 0;
	while (1)
	{
		count = read(fd, &c, 1);
		if (count == 0)
			return line;
		tmp = line;
		line = 
	}
}