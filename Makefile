EXEC = hawk
CC = gcc
SHELL = /bin/sh
SOURCES = $(shell find src -type f -name '*.c')
OBJECTS = $(SOURCES:.c=.o)
CFLAGS = -Wall -O3 -Isrc/include/ -fms-extensions
BINDIR = build/bin
BUILDDIR = build
BUILDOBJ = $(addprefix build/, $(OBJECTS))

all: dir $(EXEC)

$(EXEC): $(OBJECTS)
	echo $(SOURCES)
	echo $(OBJECTS)
	$(CC)  $(BUILDOBJ) $(CFLAGS) -o $(BINDIR)/$(EXEC)
	@cp build/bin/hawk .

$(OBJECTS): %.o : %.c
	$(CC) -c $(CFLAGS) $< -o $(BUILDDIR)/$@

install:
	@cp hawk /usr/bin/

clean:
	-rm -rf build/*

dir:
	@mkdir -p build
	@mkdir -p build/bin
	@mkdir -p build/src
	@mkdir -p build/src/compiler
	@mkdir -p build/src/collections
