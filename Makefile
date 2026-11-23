NAME = push_swap

CC = cc
# -Wall -Wextra -Werror
CFLAGS = -g

PRINTF_DIR = ./ft_printf

PRINTF = $(PRINTF_DIR)/libftprintf.a

SRCS = push_swap.c \
	   operations1.c \
	   operations2.c \
	   utils_lst1.c \
	   utils1.c \
	   validate.c \
	   turk_sort.c \
	   medium_sort.c \
	   utils_med_sort.c \
	   utils_bubble.c \
	   utils_turk.c \
	   utils_turk_1.c \
	   bench.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF) -o $(NAME)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
