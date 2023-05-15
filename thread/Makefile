CC = gcc
CFLAGS = -Wall -Wextra -g
SRC = thread_cancel.c
OBJ = $(SRC:.c=.o)
TARGET = thread_cancel

all: $(TARGET)
$(TARGET) : $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJ) $(TARGET)
