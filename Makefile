NAME = push_swap
CFLAGS = -Wall -Wextra -Werror -I ./libft
LFLAGS = -L ./libft -l ft
Cfiles = $(wildcard *.c)
OBJS = $(Cfiles:.c=.o)

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(LIBFT) $(NAME)

$(NAME) : $(OBJS)
	cc $(CFLAGS) $(OBJS) $(LFLAGS) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR) bonus
	
%.o: %.c push_swap.h
	cc $(CFLAGS) -c $< -o $@ 

clean :
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean : clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re : fclean all

.PHONY: all clean fclean re
