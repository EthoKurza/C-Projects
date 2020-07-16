#include <stdio.h>
#include <stdbool.h> // So we can use 'true'
#include <dogs.h>
// Prints the sound a dog might make.
// 'dogNum' is the dog number, 'dogWeight' is weight in kg


int main(int argc, char** argv) {
	float weight = 0;
	int count = 0;

	while (true) { // Loop until 'break'
		// Prompt for input and read in the weight
		printf("Enter the weight of dog %d in kg: ", ++count);
		int result = scanf("%f", &weight);
		if(result != 1) {
			printf("Error Wrong input\n");
			fflush(stdin);							//removes bad input
			/**
			Mac fix:
			
			char ch[256];
			gets(ch);
			*/
			//continue;
		} else {
			if (weight == 0)
				break; // Quit if weight is 0
			bark(count, weight);
			printf("\n"); // Leave a blank line
		}



	}
	return 0;
}

void bark(int dogNum, float dogWeight) {
	if (dogWeight < 10) {
		printf("Dog #%d says Yip! Yip!\n", dogNum);
	} else if (dogWeight < 50) {
		printf("Dog #%d says Ruff! Ruff!\n", dogNum);
	} else {
		printf("Dog #%d says Woof! Woof!\n", dogNum);
	}
}
