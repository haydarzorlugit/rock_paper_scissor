CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g

SRC = main.c game.c
OBJ = $(SRC:.c=.o)
DEPS = game.h

TARGET = rps

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ) $(TARGET)
