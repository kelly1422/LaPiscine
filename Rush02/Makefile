CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRCS = main.c arg.c error.c parse.c func.c
TARGET = rush-02
INC = -I./

$(TARGET): $(SRCS)
	$(CC) $(FLAGS) $(SRCS) $(INC) -o $(TARGET)

all: $(TARGET)

fclean:
	rm -rf $(TARGET)