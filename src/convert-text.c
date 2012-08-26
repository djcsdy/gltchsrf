#include "stdio.h"

int main() {
	int load_address = 0xb000;
	int c;
	int last_was_space = 1;
	
	putchar(load_address & 0xff);
	putchar((load_address >> 8) & 0xff);
	
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n') {
			if (!last_was_space) {
				putchar(' ');
				last_was_space = 1;
			}
		} else if (c >= 'a' && c <= 'z') {
			putchar(c - 'a' + 1);
			last_was_space = 0;
		}
	}
	
	exit(0);
}
