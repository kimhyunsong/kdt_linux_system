CC = gcc
CFLAGS = -Wall -Wextra -g
SRC = fork.c
OBJ = $(SRC:.c=.o)
TARGET = fork

all: $(TARGET)
$(TARGET) : $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJ) $(TARGET)
