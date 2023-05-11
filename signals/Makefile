CC = gcc
CFLAGS = -Wall -Wextra -g
SRC = t_kill.c
OBJ = $(SRC:.c=.o)
TARGET = t_kill

all: $(TARGET)
$(TARGET) : $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJ) $(TARGET)
