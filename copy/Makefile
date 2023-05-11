CC = gcc
CFLAGS = -Wall -Wextra -g
SRC = copy.c
OBJ = $(SRC:.c=.o)
TARGET = copy

all: $(TARGET)
$(TARGET) : $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJ) $(TARGET)
