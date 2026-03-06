# Makefile for task4 - State file I/O

CC = gcc
CFLAGS = -Wall -Wextra -I include

SRCDIR = src
OBJDIR = obj
BINDIR = bin

SOURCES = $(SRCDIR)/main.c $(SRCDIR)/state.c
OBJECTS = $(OBJDIR)/main.o $(OBJDIR)/state.o
TARGET = $(BINDIR)/states

all: $(TARGET)

$(TARGET): $(OBJECTS)
	mkdir -p $(BINDIR)
	$(CC) -o $@ $^

$(OBJDIR)/main.o: $(SRCDIR)/main.c include/state.h
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/state.o: $(SRCDIR)/state.c include/state.h
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR) $(BINDIR)

check:
	@true

distcheck:
	@true

.PHONY: all clean check distcheck
