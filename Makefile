NAME=lumen
CC=g++
CFLAGS=-Wall -Wextra -Werror -std=c++11
LSFML=-lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio -lsfml-network
HEADER=-I includes/
RM=rm -f

MAIN=main2.cpp
O_MAIN=main2.o
SRCS=\
SettingManager.cpp\
VertexManipulator.cpp\
Lst.cpp\
ShotList.cpp\
Shot.cpp\
EnemyList.cpp\
Enemy.cpp\
ft_itos.cpp

OBJ=$(SRCS:.cpp=.o)

$(NAME):
	$(CC) $(CFLAGS) $(HEADER) $(MAIN) $(SRCS) $(LSFML) -c
	$(CC) $(CFLAGS) $(HEADER) $(O_MAIN) $(OBJ) $(LSFML) -o $(NAME)

noWall:
	$(CC) -std=c++11 $(HEADER) $(MAIN) $(SRCS) $(LSFML) -c
	$(CC) -std=c++11 $(HEADER) $(O_MAIN) $(OBJ) $(LSFML) -o $(NAME)

all: $(NAME)

clearDisplay:
	clear

debug:
	$(CC) -g $(CFLAGS) $(HEADER) $(MAIN) $(SRCS) $(LSFML) -o $(NAME)

clean: 
	$(RM) $(O_MAIN) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean clearDisplay all

