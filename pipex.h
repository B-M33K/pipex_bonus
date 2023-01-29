/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 21:32:46 by obahi             #+#    #+#             */
/*   Updated: 2023/01/29 01:42:36 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include<unistd.h>
# include<sys/wait.h>
# include<stdio.h>
# include <errno.h>
# include <fcntl.h>
# include "libft/libft.h"	

typedef struct s_cmd
{
	char	**envp;
	char	**args;
	char	*path;
}	t_cmd;

void	ft_clean(t_cmd *cmd);
char	*ft_cmd(char *cmd, char **path);
void	ft_dup2(int i, int j);
void	ft_execve(t_cmd *cmd);
void	ft_fork(t_cmd *cmd);
// void	ft_fork(char **envp, char *argv, int out, int next_in);
void	ft_free(char **ptr);
t_cmd	*ft_here_doc_cmd(char *heredoc, char *limiter);
t_cmd	*ft_initialize(char **envp, char *argv);
void	ft_open(int *fd, char *path, int oflag, mode_t mode);
char	**ft_path(char **envp);
void	ft_pipe(int t[2]);
void	ft_waitall(int	n);

#endif