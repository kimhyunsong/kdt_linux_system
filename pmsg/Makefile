CC = gcc
CFLAGS = -Wall -Wextra -g
SRC = pmsg_receive.c
OBJ = $(SRC:.c=.o)
TARGET = pmsg_receive

all: $(TARGET)
$(TARGET) : $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJ) $(TARGET)
