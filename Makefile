exec = hawk
sources = $(wildcard src/collections/*.c src/compiler/*.c src/*.c)
objects = $(sources:.c=.o)
flags = -Wall -Isrc/include/

all: $(exec)

$(exec): $(objects)
	echo $(sources)
	echo $(objects)
	gcc $(objects) $(flags) -o $(exec)

$(objects): %.o : %.c
	gcc -c $(flags) $< -o $@


clean:
	-rm hawk
	-rm *.o
	-rm src/*.o
	-rm src/collections/*.o
	-rm src/compiler/*.o