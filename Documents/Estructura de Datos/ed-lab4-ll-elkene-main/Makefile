BANDERAS = -std=c99 -pedantic -Wall -Werror -g

SOURCE = $(wildcard *.c) $(wildcard */*.c)
HEADERS = $(wildcard *.h) $(wildcard */*.h)

leak := 
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	leak += valgrind
endif
ifeq ($(UNAME_S),Darwin)
	leak += leaks --atExit --
endif

compilar: $(HEADERS)
	gcc $(BANDERAS) $(SOURCE) -o LES

fuga: compilar
	$(leak) ./LES