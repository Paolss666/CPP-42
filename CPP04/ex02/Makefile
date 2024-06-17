# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npoalett <npoalett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/04 16:22:18 by npaolett          #+#    #+#              #
#    Updated: 2024/06/17 12:37:31 by npoalett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = AnimalAB

CXX = c++

RM = rm -fr

CXXFLAGS = -g3 -Wall -Wextra -Werror  -std=c++98 -MMD -Wno-shadow



SRC = 	src/main.cpp \
	 	src/Animal.cpp \
	 	src/Brain.cpp \
	 	src/Cat.cpp \
	 	src/Dog.cpp \
	 	src/WrongAnimal.cpp \
	 	src/WrongCat.cpp \

 

OBJ = $(SRC:.cpp=.o)
DEP = $(SRC:.cpp=.d)


$(NAME): $(OBJ)
		$(CXX) -o $(NAME) $(OBJ)

all : $(NAME)

-include $(DEP)

%.o: %.cpp
	$(CXX) $(INCL) $(CXXFLAGS) -o $@ -c $<

	
clean:
	$(RM) $(OBJ) $(DEP)

fclean: clean
	$(RM) $(NAME)

re: fclean 
	make all

.PHONY: all clean fclean 