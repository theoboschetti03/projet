CC = gcc
CFLAGS = -Wall -Werror -std=c99 -fstack-protector
TARGET = main

SRC = main.c \
	  shape.c \
	  shape_list.c \
	  svg.c \
	  circle.c \
	  rectangle.c \
	  ellipse.c \
	  line.c \
	  polyline.c \
	  polygon.c

OBJ = $(SRC:.c=.o)

build: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: build clean