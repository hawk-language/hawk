exec = hawk
sources = $(wildcard src/collections/*.c src/compiler/*.c src/*.c)
objects = $(sources:.c=.o)
flags = -Wall -Isrc/include/hawk


$(exec): $(objects)
	gcc $(objects) $(flags) -o $(exec)

%.o: %.c src/include/hawk/%.h
	gcc -c $(flags) $< -o $@

install:
	make

clean:
	-rm *.out
	-rm *.o
	-rm src/*.o