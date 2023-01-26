/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:57:10 by obahi             #+#    #+#             */
/*   Updated: 2023/01/25 22:17:53 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

int main(int argc, char **argv, char **envp)
{
	int		t[2];
	int		commands;
	t_cmd	*cmd;
	int		i;

	commands = argc - 3;
	i = -1;
	if (argc >= 5)
	{
		ft_open(t, *(argv + 1), O_RDONLY, 0);
		while (++i < commands)
		{
			ft_dup2(t[0], 0);
			if (i != commands - 1)
				ft_pipe(t);
			else
				ft_open(t + 1, *(argv + argc - 1), O_WRONLY | O_CREAT | O_TRUNC, 0777);	
			ft_dup2(t[1], 1);
			cmd = ft_initialize(envp, *(argv + 2 + i));
			ft_fork(cmd);
			ft_clean(cmd);
		}
		ft_waitall(commands);
		// while(1);
	}
	return (0);
}