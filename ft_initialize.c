/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 10:39:03 by obahi             #+#    #+#             */
/*   Updated: 2023/01/25 17:00:06 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

t_cmd	*ft_initialize(char **envp, char *argv)
{
	t_cmd	*cmd;
	char	**path;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (0);
	path = ft_path(envp);
	cmd -> envp = envp;
	cmd -> args = ft_split(argv, ' ');
	cmd -> path = ft_cmd(*(cmd -> args), path);
	ft_free(path);
	return (cmd);
}
