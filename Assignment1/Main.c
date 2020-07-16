#include <stdio.h>
#include "fileInput.h"
#include <string.h>

void getLetterCount(char letter, int arr[]);
void printHistogram(const int count[]);


int main (int argc, char** argv) {
	char str[MAX_FILE];
	int len = readFile("wonder.txt", str);
	if (len == -1) {
		printf("An error occurred\n");
	} else {

		//Process the characters in 'str' here

		//declare variables
		char letters[] = {'a','b','c','c','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};		//used to store the whole alphabet for print use
		int letterArr[26];				//stores number of times each letter appeared

		
		//initialize the letter counter to 0
		for(int i=0; i <26; i++) {
			letterArr[i] = 0;
		}

		
		//get the number of occurences for each letter from the file
		for(int i=0; i<len; i++) {

			getLetterCount(str[i], letterArr);
		}



		//Print Letters
		printHistogram(letterArr);
		
		
		//print total occurances for each letter
		puts("========= Total number of Occurences =========");
		for(int i = 0; i <26; i++) {
			printf("Total number of occurences for %c is: %d \n",('A'+i),letterArr[i];
		}

	}//end of else

}//end of main


//methods or functions

//A method to find and see if any character in the array matches.
void getLetterCount(char letter, int arr[]) {

	if(('a' == letter) || ('A' == letter)) {
		arr[0]++;
	} else if(('b'== letter) || (letter == 'B')) {
		arr[1]++;
	} else if((letter == 'c') || (letter == 'C')) {
		arr[2]++;
	} else if((letter == 'd') || (letter == 'D')) {
		arr[3]++;
	} else if((letter == 'e') || (letter == 'E')) {
		arr[4]++;
	} else if((letter == 'f') || (letter == 'F')) {
		arr[5]++;
	} else if((letter == 'g') || (letter == 'G')) {
		arr[6]++;
	} else if((letter == 'h') || (letter == 'H')) {
		arr[7]++;
	} else if((letter == 'i') || (letter == 'I')) {
		arr[8]++;
	} else if((letter == 'j') || (letter == 'J')) {
		arr[9]++;
	} else if((letter == 'k') || (letter == 'K')) {
		arr[10]++;
	} else if((letter == 'l') || (letter == 'L')) {
		arr[11]++;
	} else if((letter == 'm') || (letter == 'M')) {
		arr[12]++;
	} else if((letter == 'n') || (letter == 'N')) {
		arr[13]++;
	} else if((letter == 'o') || (letter == 'O')) {
		arr[14]++;
	} else if((letter == 'p') || (letter == 'P')) {
		arr[15]++;
	} else if((letter == 'q') || (letter == 'Q')) {
		arr[16]++;
	} else if((letter == 'r') || (letter == 'R')) {
		arr[17]++;
	} else if((letter == 's') || (letter == 'S')) {
		arr[18]++;
	} else if((letter == 't') || (letter == 'T')) {
		arr[19]++;
	} else if((letter == 'u') || (letter == 'U')) {
		arr[20]++;
	} else if((letter == 'v') || (letter == 'V')) {
		arr[21]++;
	} else if((letter == 'w') || (letter == 'W')) {
		arr[22]++;
	} else if((letter == 'x') || (letter == 'X')) {
		arr[23]++;
	} else if((letter == 'y') || (letter == 'Y')) {
		arr[24]++;
	} else if((letter == 'z') || (letter == 'Z')) {
		arr[25]++;
	}


}//end of getLetterCount


/*			Print Histogram				*/
void printHistogram(const int count[]){
	//declare variables
	char letters[] = {'a','b','c','c','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};		//used to store the whole alphabet for print 
	int  maxLetter, minLetter, diffChar=0, maxCount, minCount; 
	
	
	//get max, min, differce count
	maxCount = count[0];
	minCount = count[0];
	for(int i = 0; i < 26; i++){
		
		//get most common letter
		if(maxCount < count[i]){
			maxLetter = i;
			maxCount = count[i];
		}
			
		
		//get least common letter
		if(minCount > count[i]){
			minLetter = i;
			minCount = count[i];	
		}
			
			
		//find number of different characters
		if(count[i] != 0)
			diffChar++;

	}
	
	
	
	//print out histogram
	/*
	puts("================== Histogram ===================");
	printf("\n\n");
	
	for(int i = 0; i < 26; i++ ){
		
		//print all letters based on the amount of each letter occurrence
		for(int j = 0; j < count[i]; j++){
			printf("%c",letters[i]);
		}
		printf(": %d \n\n\n",count[i]);
		
	}

	*/

	
	//print NormalizedHistogram
	puts("================== Normalized Histogram ===================");
	printf("\n\n");
	

	for(int i = 0; i < 26; i++){
		int normalizeCounter=1;
		
		//print all letters based on the amount of each letter occurrence
		for(int j = 0; j < count[i]; j++){

			//check if it already printed out 70 in one line
			if(normalizeCounter > 70){
				printf("\n");			//print a new line
				normalizeCounter=1;		//reset the value to 1
			}
			
			printf("%c", letters[i]);	//print the characters
			normalizeCounter++;
			
		}
		printf(": %d \n\n\n",count[i]);	
	}
	
	printf("Most common Letter: %c\n", letters[maxLetter]);
	printf("Least common Letter: %c\n", letters[minLetter]);
	printf("Total number of different letters: %d\n\n", diffChar);
		
}//end of printHistrogram





