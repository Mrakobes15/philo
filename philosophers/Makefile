# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: risolon <risolon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/28 16:14:13 by risolon           #+#    #+#              #
#    Updated: 2022/06/28 19:47:13 by risolon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


FLAGS=-Werror -Wextra -Wall -fsanitize=thread
NAME=philo
SRC=*.c
INCLUDES= -lpthread

all:
	gcc $(SRC) -o $(NAME) $(FLAGS) $(INCLUDES)

clean:
	rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

push:
	git add .
	git status
	git commit -m fdf
	git push

.PHONY:		all clean fclean re push



# SRCS	= *.c

# OBJS	= $(SRCS:.c=.o)

# NAME	= philo

# FLAGS	= -Wall -Wextra -Werror

# INCLUDE	= 

# HEADER	= philo.h




# all:	$(NAME)


# $(NAME): $(OBJS)
# 	gcc $(INCLUDE) $(FLAGS) -o $(NAME) $(OBJS)

# clean:
# 	rm -f $(OBJS) $(B_OBJS)

# fclean: clean
# 	rm -f $(NAME) $(BONUS)

# re: fclean all

# %.o: %.c $(HEADER)
# 	gcc $(FLAGS) -c $<  -o $(<:.c=.o)

# .PHONY:	clean fclean re bonus 