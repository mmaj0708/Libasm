# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/12 17:09:42 by mmaj              #+#    #+#              #
#    Updated: 2020/12/12 17:24:04 by mmaj             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

TEST = test.out

SRCS = srcs/ft_read.s srcs/ft_strcmp.s srcs/ft_strcpy.s srcs/ft_strdup.s\
		srcs/ft_strlen.s srcs/ft_write.s

OBJECTS = srcs/ft_read.o srcs/ft_strcmp.o srcs/ft_strcpy.o srcs/ft_strdup.o\
		srcs/ft_strlen.o srcs/ft_write.o

INCLUDES = ./header/

all : $(NAME) $(TEST)

$(NAME)

$(TEST) :

	@clang -g3 -Wall -Wextra -Werror -I$(INCLUDES) $(SRCS) 
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)

clean : 
	@/bin/rm -f $(OBJECTS)

fclean : clean
	@/bin/rm -f $(NAME)

re : fclean all