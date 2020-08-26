##
# boh2boh
#
# @file
# @version 0.1

CC ?= cc
CFLAGS ?=
PREFIX ?= /usr/bin

all: boh2boh

boh2boh: boh2boh.c
	$(CC) boh2boh.c -o boh2boh $(CFLAGS)

install: boh2boh uninstall
	install -C boh2boh $(PREFIX)
	ln $(PREFIX)/boh2boh $(PREFIX)/b2o
	ln $(PREFIX)/boh2boh $(PREFIX)/b2h
	ln $(PREFIX)/boh2boh $(PREFIX)/o2b
	ln $(PREFIX)/boh2boh $(PREFIX)/o2h
	ln $(PREFIX)/boh2boh $(PREFIX)/h2b
	ln $(PREFIX)/boh2boh $(PREFIX)/h2o

uninstall:
	rm -f $(PREFIX)/boh2boh $(PREFIX)/b2o $(PREFIX)/b2h $(PREFIX)/o2b $(PREFIX)/o2h \
	      $(PREFIX)/h2b $(PREFIX)/h2o

# end
