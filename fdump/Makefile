.PHONY: clean

CFLAGS = -Wall -Werror -g -fsanitize=address,undefined
CC = cc

fdump:	main.c
				$(CC) $(CFLAGS) -o fdump main.c	

clean:
				rm -f fdump
