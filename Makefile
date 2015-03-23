##
## Created by André Paulos
## paulos_a@epitech.eu
##

CXX	= clang++

DIR_SRC	= ./src

SRCS	=	main.cpp			\
			$(DIR_SRC)/Game.cpp	\
			$(DIR_SRC)/Ship.cpp	\
			$(DIR_SRC)/Wall.cpp	\
			$(DIR_SRC)/Adversary.cpp	\
			$(DIR_SRC)/Bullet.cpp

OBJS	= $(SRCS:.cpp=.o)

CXXFLAGS	= -I./include

CXXFLAGS	+= -Wall -Werror -Wextra

CXXFLAGS	+= -g3

CXXFLAGS	+= -std=c++11

LDFLAGS		= -lsfml-graphics -lsfml-window -lsfml-system

RM	= rm -f

NAME	= space\ invaders

all	: $(NAME)

$(NAME)	: $(OBJS)
	@echo "\t\033[33mCompiling...\033[39m"
	@$(CXX) $(OBJS) $(LDFLAGS) -o $(NAME)
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
