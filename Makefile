NAME		=	space-invaders

ERRLOG		=	2>> errors~

CC			=	clang++
RM			=	rm -rf
ECHO		=	echo

FLAGS		=	-W -Wall -Werror -Wextra -g3
FLAGS		+=	-std=c++11
#			-lasan				\
			-fsanitize=address		\
			-fno-omit-frame-pointer		\
			-O0
#DEBUG		=	-g -g3 -ggdb

DEFAULT		=	"\033[00m"
GREEN		=	"\033[0;32m"
TEAL		=	"\033[1;36m"
RED		=	"\033[0;31m"

INCLUDE		=	-I./include/
LIBRARY		= 	-lsfml-graphics			\
			-lsfml-window			\
			-lsfml-system

ENTRYPOINT	=	$(wildcard ./src/*.cpp)

FILE		=	$(ENTRYPOINT)

OBJ			=	$(FILE:.cpp=.o)

## Compile ---------------------------------------------------------------------
all:		temp $(NAME)

$(NAME):	$(OBJ)
		@$(CC) $(INCLUDE) $(OBJ) -o $(NAME) $(LIBRARY) \
		 $(ERRLOG) && \
		 $(ECHO) $(GREEN) "[OK]" $(TEAL) $@ $(DEFAULT) || \
		 $(ECHO) $(RED) "[XX]" $(TEAL) $@ $(DEFAULT)
.cpp.o:
		@$(CC) -c $(INCLUDE) $< -o $@ $(DEBUG) $(FLAGS) \
		 $(ERRLOG) && \
		 $(ECHO) $(GREEN) "[OK]" $(TEAL) $< $(DEFAULT) || \
		 $(ECHO) $(RED) "[XX]" $(TEAL) $< $(DEFAULT)

## Misc ------------------------------------------------------------------------
temp:
		@find . -name "*~" -delete
clean:		temp
		@$(RM) $(OBJ)
fclean:		clean
		@$(RM) $(NAME)
re:		fclean all
