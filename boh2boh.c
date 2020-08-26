#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int
bin(char *s)
{
	int n;

	n = 0;
	while (*s != '\0') {
		n <<= 1;
		n += *s - '0';
		++s;
	}
	return n;
}

static int
oin(char *s)
{
	int n;

	n = 0;
	while (*s != '\0') {
		n <<= 3;
		n += *s - '0';
		++s;
	}
	return n;
}

static int
hin(char *s)
{
	int n;

	n = 0;
	while (*s != '\0') {
		n <<= 4;
		n += *s <= 58 ? *s - '0' : *s - 'A' + 10;
		++s;
	}
	return n;
}

static void
bout(int n)
{
	/* There is no printf format for binary numbers, so we have to create
	 * another way to print a number in binary. */
	char buf[64], *p;

	buf[0] = 0;
	p = (char *)buf;
	do {
		*(++p) = (char)(n & 1) + '0';
		n >>= 1;
	} while(n);
	while (*p != '\0')
		putchar(*(p++));
}

static void
oout(int n)
{
	printf("%o", n);
}

static void
hout(int n)
{
	printf("%X", n);
}

static int(*in[])(char *) = {
	['b'] = bin,
	['o'] = oin,
	['h'] = hin
};

static void(*out[])(int) = {
	['b'] = bout,
	['o'] = oout,
	['h'] = hout
};

int
main(int argc, char **argv)
{
	char *name, *ins;
	int n;

	if (strcmp("boh2boh", argv[0])) {
		name = argv[0];
		if (argc < 2) {
				fprintf(stderr, "An argument is needed to run the command.\n");
				exit(1);
		}
		ins = argv[1];
	} else {
		if (argc < 2) {
				fprintf(stderr, "An command is needed.\n");
				exit(1);
		}
		name = argv[1];
		if (argc < 3) {
				fprintf(stderr, "An argument is needed to run the command.\n");
				exit(1);
		}
		ins = argv[2];
	}
	n = in[(int)name[0]](ins);
	out[(int)name[2]](n);
}
