##
## Created by André Paulos
## paulos_a@epitech.eu
##

CXX	= clang++

DIR_SRC	= ./src

SRCS	= main.cpp	\
	$(DIR_SRC)/Menu.cpp

OBJS	= $(SRCS:.cpp=.o)

CXXFLAGS	= -I./include

CXXFLAGS	+= -Wall -Werror -Wextra

CXXFLAGS	+= -g3

CXXFLAGS	+= -O3

LDFLAGS		= -framework sfml-graphics -lsfml-window -lsfml-system

RM	= rm -f

NAME	= space\ invaders

all	: $(NAME)

$(NAME)	: $(OBJS)
	@echo "\t\033[33mCompiling...\033[39m"
	@$(CXX) $(OBJS) $(CXXFLAGS) $(LDFLAGS) -o $(NAME)
	@echo "\t\033[32mSuccess!\033[39m"

clean	:
	@echo "\t\033[91mRemoving objects...\033[39m"
	@$(RM) $(OBJS)
	@echo "\t\033[32mDone\033[39m"

fclean	: clean
	@echo "\t\033[91mRemoving executable ...\033[39m"
	@$(RM) $(NAME)
	@echo "\t\033[32mDone\033[m"

re	: fclean all
