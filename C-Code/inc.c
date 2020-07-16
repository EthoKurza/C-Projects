#include <stdio.h>

int main(void) {
	int c;

	printf("Test post-increment:\n");
	c = 5;
	printf("%d\n", c);
	printf("%d\n", c++);	//prints 5 because it reads the line from left to right
	printf("%d\n", c);

	printf("Test pre-increment:\n");
	c = 5;
	printf("%d\n", c);
	printf("%d\n", ++c);
	printf("%d\n", c);

	printf("Playing with characters:\n");
	char letter = 'b';
	int num = letter;
	printf("%c, %d\n", letter, num);
	letter--;
	printf("%c\n", letter);
	letter = 90;
	printf("%c\n", letter);

	return 0;
}
