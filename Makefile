##
# boh2boh
#
# @file
# @version 0.1

CC ?= "cc"
CFLAGS ?= ""
PREFIX ?= "/usr/bin"

all: boh2boh

boh2boh: boh2boh.c
	$(CC) boh2boh.c -o boh2boh $(CFLAGS)

install: boh2boh
	install -C boh2boh $(PREFIX)

# end
