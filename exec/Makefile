CC = gcc
CFLAGS = -Wall -Wextra -g
SRC = exec.c
OBJ = $(SRC:.c=.o)
TARGET = exec

all: $(TARGET)
$(TARGET) : $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJ) $(TARGET)
