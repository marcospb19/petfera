.DEFAULT_GOAL = petfera
CC = g++
FLAGS = -Wall -Wextra -Werror -pedantic -std=c++11
OBJECTS = petfera.o menu.o funcionario.o veterinario.o tratador.o


petfera: $(OBJECTS)
	$(CC) $(FLAGS) -o petfera $(OBJECTS)

%.o: %.cpp
	$(CC) -c $^ -o $@

clean:
	@rm $(OBJECTS) 2> /dev/null
