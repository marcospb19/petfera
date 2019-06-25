.DEFAULT_GOAL = exportar
CC = g++
CFLAGS = -O2 -Wall -Wextra -Werror -pedantic -std=c++11
OBJECTS = exportar.o arquivo.o parse.o messages.o


exportar: $(OBJECTS)
	$(CC) -o exportar $(OBJECTS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	@rm $(OBJECTS) 2> /dev/null || exit 0
