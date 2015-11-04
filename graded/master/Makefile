CFLAGS+=-std=c11 -Wall -Werror -Wno-deprecated -Wextra -Wstack-usage=1024 -pedantic

.PHONY: clean debug

mastermind : mastermind.c
	cc $(CFLAGS) $^ -o master

debug: CFLAGS+=-g
debug: mastermind

clean:
	rm master *.o