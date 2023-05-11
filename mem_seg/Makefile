CC = gcc
CFLAGS = -Wall -Wextra -g
SRC = mem_segments.c
OBJ = $(SRC:.c=.o)
TARGET = mem_segments

all: $(TARGET)
$(TARGET) : $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJ) $(TARGET)
