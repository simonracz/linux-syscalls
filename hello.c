#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main() {
	printf("Hello!\n");
	FILE * f = fopen("./test.txt", "w");
	if (f == NULL) {
		printf("Couldn't open file.\n");
		return EXIT_FAILURE;
	}
	char data[5] = {'h', 'e', 'l', 'l', 'o'};
	size_t count = fwrite(data, 1, 5, f);
	if (count != 5) {
		printf("Wrote out only %lu bytes.\n", count);
		return EXIT_FAILURE;
	}
	int ret = fclose(f);
	if (ret == EOF) {
		printf("Now what!?\n");
		return EXIT_FAILURE;
	}
	char * mem = (char*) malloc(50000000);
	if (mem == NULL) {
		printf("Couldn't allocate memory.\n");
		return EXIT_FAILURE;
	}
	sleep(1);
	free(mem);
}
