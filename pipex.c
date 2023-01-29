/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:57:10 by obahi             #+#    #+#             */
/*   Updated: 2023/01/29 01:42:50 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

int main(int argc, char **argv, char **envp)
{
	int		t[2];
	int		commands;
	t_cmd	*cmd;
	int		i;
// ./pipex here_doc LIMITER cmd cmd1 file
//     0       1       2     3   4     5
	if (argc >= 5)
	{
		commands = argc - 3;
		i = -1;
		if (!ft_strcmp(*(argv + 1), "here_doc"))
		{
			t[0] = 0;
			cmd = ft_here_doc_cmd(*(argv + 1), *(argv + 2));
		}
		else
			ft_open(t, *(argv + 1), O_RDONLY, 0);
		while (++i < commands)
		{
			ft_dup2(t[0], 0);
			if (i != commands - 1)
				ft_pipe(t);
			else
				ft_open(t + 1, *(argv + argc - 1), O_WRONLY | O_CREAT | O_TRUNC, 0777);	
			ft_dup2(t[1], 1);
			if (!cmd)
				cmd = ft_initialize(envp, *(argv + 2 + i ));
			ft_fork(cmd);
			ft_clean(cmd);
			cmd = 0;
		}
		ft_waitall(commands);
		// while(1);
	}
	return (0);
}