/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_doc_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 00:59:49 by obahi             #+#    #+#             */
/*   Updated: 2023/01/29 01:44:41 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_cmd	*ft_here_doc_cmd(char *heredoc, char *limiter)
{
	t_cmd	*cmd;
	char	*args;
	char	*tmp;

	cmd = malloc (sizeof(t_cmd));
	if (!cmd)
		return (0);
	cmd -> path = ft_strdup(heredoc);
	args = ft_strjoin(heredoc, " ");
	tmp = args;
	args = ft_strjoin(args, limiter);
	free(tmp);
	cmd -> args = ft_split(args, ' ');
	free(args);
	cmd -> envp = 0;
	return (cmd);
}