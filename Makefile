##
## EPITECH PROJECT, 2018
## makefile
## File description:
## 
##

NAME		= bomberman

RM		= rm -rf

SRC_DIR		= srcs

INC_DIR		= incs

LIB_IRRKLANG	= irrKlang/libIrrKlang.so

CXX		= g++

CXXFLAGS	= -g3 -std=c++14 -Wall -Wextra -I$(INC_DIR) -lIrrlicht -lGL -lXxf86vm -lXext -lX11 -lXcursor -pthread

SRC		= $(shell find $(SRC_DIR) -type f -name '*.cpp')

OBJ		= $(SRC:.cpp=.o)

###
ECHO		= /bin/echo -e
DEFAULT		= "\033[00m"
GREEN		= "\033[1;32m"
YELLOW		= "\033[1;33m"
TEAL		= "\033[1;36m"
RED		= "\033[1;31m"
###

all: mrclean $(NAME)

$(NAME): $(OBJ)
	@$(CXX) -o $(NAME) $(OBJ) $(CXXFLAGS) $(LIB_IRRKLANG) && \
	$(ECHO) $(GREEN) "[OK]"$(YELLOW)"  BUILD : $(NAME)" $(DEFAULT)  || \
	$(ECHO) $(RED) "[ERROR]" $(TEAL) $(Snake) $(DEFAULT)

install:
	make -C ./irrlicht-1.8.4/source/Irrlicht/
	sudo cp ./irrlicht-1.8.4/lib/Linux/libIrrlicht.a /usr/lib
	sudo cp ./irrlicht-1.8.4/include/* /usr/include

clean_install:
		rm -rf $(IRRLICHT)
		make -C ./irrlicht-1.8.4/source/Irrlicht/ clean

uninstall:	clean_install
		sudo $(RM) /usr/lib/libIrrlicht.a
		sudo $(RM) /usr/include/irrlicht.h

mrclean:
	@$(RM) *~
	@$(RM) $(SRC_DIR)/*~
	@$(RM) $(INC_DIR)/*~

clean: mrclean
	@$(RM) $(OBJ) && \
        $(ECHO) $(GREEN) "[OK]" $(RED) "Cleaning object files" $(TEAL) $(OBJ) $(DEFAULT) || \
	$(ECHO) $(RED) "[ERROR] Doesn't exist" $(YELLOW) $(OBJ) $(DEFAULT)

fclean: clean
	@$(RM) $(NAME) && \
	$(ECHO) $(GREEN) "[OK]" $(RED)  "Cleaning binary" $(YELLOW) $(NAME) $(DEFAULT) || \
	$(ECHO) $(RED) "[ERROR] Doesn't exist" $(YELLOW) $(NAME) $(DEFAULT)

re: mrclean fclean all

.cpp.o  :
	@$(CXX) $(CXXFLAGS) -c -o $@ $< && \
	$(ECHO) $(GREEN) "[OK]" $(TEAL) $< "->" $@ $(DEFAULT) || \
	$(ECHO) $(RED) "[ERROR] Doesn't exist" $(TEAL) $^ $(DEFAULT)

re: fclean all

rec: all clean

.PHONY: all install clean_install uninstall clean fclean re
