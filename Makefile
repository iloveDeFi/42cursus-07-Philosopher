# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/03 19:09:12 by bat               #+#    #+#              #
#    Updated: 2024/02/04 17:28:39 by bbessard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=			action.c \
					check.c \
					destroy.c \
					error.c \
					init.c \
					message.c \
					philo.c \
					state.c \
					thread.c \
					time.c 					

OBJS	=			${SRCS:.c=.o}

CC		=			gcc -g3

RM		=			rm -f

CFLAGS	=			-Wall -Wextra -Werror -g -fsanitize=thread

NAME	=			philo

all: 				$(NAME)

%.o: 				%.c
					${CC} ${CFLAGS} -c -o $@ $<

${NAME}:			${OBJS}
					${CC} ${CFLAGS} $^ -o $(NAME)

clean:
					${RM} $(OBJS)

fclean:				clean
					${RM} ${NAME}

re: 				fclean all

.PHONY:				all  clean fclean re