# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/04 16:22:18 by npaolett          #+#    #+#              #
#    Updated: 2024/06/03 11:45:07 by npaolett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = Fixed

CC = c++

RM = rm -fr

CFLAGS = -g3 -Wall -Wextra -Werror  -std=c++98 -MMD



SRC = 	main.cpp \
		Fixed.cpp \
 

OBJ = $(SRC:.cpp=.o)
DEP = $(SRC:.cpp=.d)


$(NAME): $(OBJ)
		$(CC) -o $(NAME) $(OBJ)

all : $(NAME)

-include $(DEP)

%.o: %.cpp
	$(CC) $(INCL) $(CFLAGS) -o $@ -c $<

	
clean:
	$(RM) $(OBJ) $(DEP)

fclean: clean
	$(RM) $(NAME)

re: fclean 
	make all

.PHONY: all clean fclean 