CC=cc
CFLAGS=-g -O0
CP=cp
BIN_DIR=/usr/local/bin

all: entab detab

entab: entab.c
	$(CC) $(CFLAGS) $^ -o $@

detab: detab.c
	$(CC) $(CFLAGS) $^ -o $@

install:
	$(CP) entab detab $(BIN_DIR)
