#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define DEFAULT_TAB_SIZE 4

void usage(void) {
	printf("usage: entab [-n <tab size>]");
}

int main(int argc, char *argv[]) {
	int c, n, i, opt, count;

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
	count = n;

	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			if (--count == 0) {
				putchar('\t');
				count = n;
			}
		} else {
			for (; count < n; ++count)
				putchar(' ');
			putchar(c);
		}
	}
}
