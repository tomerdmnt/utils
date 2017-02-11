#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define DEFAULT_TAB_SIZE 4

void usage(void) {
	printf("detab [-n <tab size>]");
}

int main(int argc, char *argv[]) {
	int c, n, i, opt;

	n = DEFAULT_TAB_SIZE;
	while ((opt = getopt(argc, argv, "hn:")) != -1) {
		switch(opt) {
		case 'n':
			n = atoi(optarg);
			break;
		case 'h':
			usage();
			break;
		}
	}

	while ((c = getchar()) != EOF)
		if (c == '\t')
			for (i = n; i > 0; --i)
				putchar(' ');
		else
			putchar(c);
}
