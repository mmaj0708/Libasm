# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/12 17:09:42 by mmaj              #+#    #+#              #
#    Updated: 2020/12/14 15:21:20 by mmaj             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

TEST = test

SRCS = srcs/ft_read.s srcs/ft_strcmp.s srcs/ft_strcpy.s srcs/ft_strdup.s\
		srcs/ft_strlen.s srcs/ft_write.s

OBJECTS = $(SRCS:.s=.o)

INCLUDES = ./header/

NA = nasm

NA_FLAG = -felf64


%.o: %.s # applique la règle pour chaque fichier

	$(NA) $(NA_FLAG) $<

all : $(NAME)

$(NAME): $(OBJECTS)

	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)


$(TEST) : $(NAME)

	@clang -g3 -Wall -Wextra -Werror -I$(INCLUDES) main_test.c $(NAME)
	./a.out

clean : 
	@/bin/rm -f $(OBJECTS)

fclean : clean
	@/bin/rm -f $(NAME)

re : fclean all