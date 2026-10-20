CC = gcc
CFLAGS = -Wall -Werror -std=c99 -fstackprotector

SRC = main.c \
	  forme.c \
	  liste.c \
	  svg.c \
	  cercle.c \
	

OBJ = $(SRC:.c=.o)

build: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: build clean