EXEC = hawk
CC = gcc
SHELL = /bin/sh
SOURCES = $(shell find src -path src/cmake-build-debug -prune -o  -type f -name "*.c" -print)
OBJECTS = $(SOURCES:.c=.o)
CFLAGS = -Wall -O3 -Isrc/include/ -fms-extensions
BINDIR = build/bin
BUILDDIR = build
BUILDOBJ = $(addprefix build/obj/, $(notdir $(OBJECTS)))

all: dir $(EXEC)

$(EXEC): $(OBJECTS)
	echo $(SOURCES)
	echo $(OBJECTS)
	$(CC)  $(BUILDOBJ) $(CFLAGS) -o $(BINDIR)/$(EXEC)
	@cp build/bin/hawk .

$(OBJECTS): %.o : %.c
	@BASENAME="$(notdir $@)"
	$(CC) -c $(CFLAGS) $< -o $(BUILDDIR)/obj/$(notdir $@)

install:
	@cp hawk /usr/bin/

clean:
	-rm -rf build/*

dir:
	@mkdir -p build
	@mkdir -p build/bin
	@mkdir -p build/obj
