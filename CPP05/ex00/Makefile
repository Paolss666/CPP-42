# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npaolett <npaolett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/04 16:22:18 by npaolett          #+#    #+#              #
#    Updated: 2024/06/24 16:43:42 by npaolett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = Bureaucrat

CXX = c++

RM = rm -fr

CXXFLAGS = -g3 -Wall -Wextra -Werror  -std=c++98 -MMD -Wno-shadow



SRC = 	main.cpp \
	 	Bureaucrat.cpp \

 

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