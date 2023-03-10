/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 22:30:57 by obahi             #+#    #+#             */
/*   Updated: 2023/01/28 21:02:26 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

int	main(int argc, char **argv)
{
	char	*limiter;
	char	*line;
	char	*tmp;
	int		n;

	if (argc == 2)
	{
		limiter = *(argv + 1);
		n = ft_strlen(limiter);
		line = get_next_line(0);
		while (*(line + n) != '\n' || ft_strncmp(line, limiter, n))
		{
			ft_putstr_fd(line, 1);
			tmp = line;
			line = get_next_line(0);
			if (tmp)
				free(tmp);
		}
		free(line);
	}
	return (0);
}