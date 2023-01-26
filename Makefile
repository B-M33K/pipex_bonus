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
		ft_initialize.c \
		ft_open.c \
		ft_path.c \
		ft_pipe.c \
		ft_waitall.c \
		pipex.c
OBJ = $(SRC:.c=.o)
HEADER = pipex.h
RM = rm

all : $(NAME)

$(NAME) : $(OBJ) $(LIBFT)
	$(CC) $(OBJ) $(LIBFT) -o $@

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT) :
	$(MAKE) -C libft 
	$(MAKE) -C libft clean

clean :
	$(RM) -f $(OBJ)

fclean : clean
	$(RM) -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
