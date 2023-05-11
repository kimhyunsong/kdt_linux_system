CC = gcc
CFLAGS = -Wall -Wextra -g
SRC = pipe.c
OBJ = $(SRC:.c=.o)
TARGET = pipe

all: $(TARGET)
$(TARGET) : $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJ) $(TARGET)
