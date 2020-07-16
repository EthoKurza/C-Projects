#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define STRLEN 256


int main(int argc, char** argv){
	
	
	//char arr[100] ="";
	
	//puts("Enter a String:");
	//scanf("%s",arr);

	//int len = strlen(arr);
	//for(int i =0; i<len(;i+=2){
		
		//if((i % 2) == 0){
	//		printf("%c",arr[i]);
		//}
		
		
	//}
	
	//return 0;
	
	
	char str[STRLEN] = "";
	printf("Please enter a string: ");
	scanf("%255[^\n]",str);		//reads spaces
	
	unsigned int len = strlen(str);
	
	//create a new string containing every second character
	char str2[STRLEN];
	int j = 0;									//another loop variable
	for(int i = 0 ; i < len; i+=2){
		str2[j++] = str[i];
		
	}
	
	
str2[len]= '\0';								//make sure null terminated

printf("%s\n",str2);
	
	
}//end of main
