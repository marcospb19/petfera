.DEFAULT_GOAL = petfera
CC = g++
CFLAGS = -O2 -Wall -Wextra -Werror -pedantic -std=c++11
OBJECTS = petfera.o menu.o funcionario.o veterinario.o tratador.o date.o animal.o


petfera: $(OBJECTS)
	$(CC) -o petfera $(OBJECTS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	@rm $(OBJECTS) 2> /dev/null
