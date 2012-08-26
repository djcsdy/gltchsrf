#include <stdio.h>
#include <error.h>
#include <errno.h>

int main(int argc, char **argv) {
	int load_address = 0xb000;
	int c;
	int last_was_space = 1;
	int count = 0;
	
	FILE *prg, *hdr;
	
	if (argc != 4) {
		fprintf(stderr, "Incorrect argument count\n");
		fprintf(stderr, "Usage: %s out.prg out.hdr symbol < in.txt\n",
				argv[0]);
		return 1;
	}
	
	if ((prg = fopen(argv[1], "wb")) == NULL) {
		error(2, errno, "Failed to open %s for output", argv[1]);
		return 2;
	}
	
	if ((hdr = fopen(argv[2], "w")) == NULL) {
		error(3, errno, "Failed to open %s for output", argv[1]);
		return 3;
	}
	
	fputc(load_address & 0xff, prg);
	fputc((load_address >> 8) & 0xff, prg);
	
	fprintf(hdr, "%s = $%x\n", argv[3], load_address);
	
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n') {
			if (!last_was_space) {
				fputc(' ', prg);
				last_was_space = 1;
				++count;
			}
		} else if (c >= 'a' && c <= 'z') {
			fputc(c - 'a' + 1, prg);
			last_was_space = 0;
			++count;
		}
	}
	
	fprintf(hdr, "%s._end = $%x\n", argv[3], load_address + count);
	
	fclose(prg);
	fclose(hdr);
	
	return 0;
}
