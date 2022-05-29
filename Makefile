CC = gcc
override CFLAGS += -g -Wvla -Wall -Wpedantic -Wextra -Wdeclaration-after-statement

SRCS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.c' -print)
OBJS = $(patsubst %.c, %.o, $(SRCS))

main: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o main -lm

clean:
	rm -f $(OBJS) main
	clear

zip:
	rm -rf src.zip
	zip -r src.zip *.c *.h board.o