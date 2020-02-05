EXEC = hawk
SOURCES = $(wildcard src/collections/*.c src/compiler/*.c src/*.c)
OBJECTS = $(SOURCES:.c=.o)
CFLAGS = -Wall -O3 -Isrc/include/
BINDIR = build/bin
BUILDDIR = build
BUILDOBJ = $(addprefix build/, $(OBJECTS))

all: dir $(EXEC)

$(EXEC): $(OBJECTS)
	echo $(SOURCES)
	echo $(OBJECTS)
	gcc  $(BUILDOBJ) $(CFLAGS) -o $(BINDIR)/$(EXEC)
	cp build/bin/hawk .

$(OBJECTS): %.o : %.c
	gcc -c $(CFLAGS) $< -o $(BUILDDIR)/$@

clean:
	-rm -rf build/*

dir:
	@mkdir -p build
	@mkdir -p build/bin
	@mkdir -p build/src
	@mkdir -p build/src/compiler
	@mkdir -p build/src/collections
