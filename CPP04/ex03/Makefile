# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npoalett <npoalett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/04 16:22:18 by npaolett          #+#    #+#              #
#    Updated: 2024/06/18 20:02:53 by npoalett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = Materia

CXX = c++

RM = rm -fr

CXXFLAGS = -g3 -Wall -Wextra -Werror  -std=c++98 -MMD -Wno-shadow



SRC = 	src/main.cpp \
	 	src/AMateria.cpp \
	 	src/Cure.cpp\
	 	src/Ice.cpp\
	 	src/MateriaSource.cpp\
	 	src/Character.cpp\

 

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