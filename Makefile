# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obahi <obahi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/29 01:49:46 by obahi             #+#    #+#              #
#    Updated: 2023/01/29 01:50:03 by obahi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = pipex
LIBFT = libft/libft.a
MAKE = make
SRC = 	ft_clean.c \
		ft_cmd.c \
		ft_dup2.c \
		ft_execve.c \
		ft_fork.c \
		ft_free.c \
		ft_here_doc_cmd.c \
		ft_initialize.c \
		ft_open.c \
		ft_path.c \
		ft_pipe.c \
		ft_waitall.c \
		pipex.c
OBJ = $(SRC:.c=.o)
HEADER = pipex.h
RM = rm
HEREDOC = here_doc
HEREDOCCMD = here_doc.c

all : $(NAME)

$(NAME) : $(OBJ) $(LIBFT) $(HEREDOC)
	$(CC) $(OBJ) $(LIBFT) -o $@

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT) :
	$(MAKE) -C libft
	$(MAKE) -C libft clean

$(HEREDOC) : $(HEREDOCCMD) $(HEADER) $(LIBFT)
	$(CC) $(CFLAGS) $< $(LIBFT) -o $@

clean :
	$(RM) -f $(OBJ)

fclean : clean
	$(RM) -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
