CC = gcc
CFLAGS = -Wall -Wextra -g
SRC = popen_glob.c
OBJ = $(SRC:.c=.o)
TARGET = popen_glob

all: $(TARGET)
$(TARGET) : $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJ) $(TARGET)
