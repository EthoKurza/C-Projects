/*
Name: Heyzzen Flores
Date: January 29, 2020
Project: Quiz 2
*/

#include <stdio.h>
#include <string.h>

const char table[] = "XOYQMCRGUKSWAFLNTHDJPZIBEV";

//declare prototype
void encode(char str[]);			
void decode(char str[]);

int main(int argc, char** argv){
	//declare and initialize variables
	
	char chInput[256]; 
	//char ch = 'X';					//character to encode
	//char newCH = table[ch - 'A'];	//Do table lookup to get encoded letter
	
	//get input from user
	printf("Enter a string: ");
	scanf("%255[^\n]",chInput);
	
	//encode string of characters
	encode(chInput);
	printf("\nNew encoded String: %s\n",chInput);
	
	
	//decode
	decode(chInput);
	printf("\nDecoded String: %s",chInput);
	
}//end of main

//methods
void encode(char str[]){
	//declare and initialize variables
	const char table[] = "XOYQMCRGUKSWAFLNTHDJPZIBEV";
	//const char table2[] = "xoyqmcrgukswaflnthdjpzibev";
	int len = strlen(str);
	char newCH;
	
	//encode string
	for(int i =0; i < len;i++){
		char ch = str[i];
		//newCH = table[ch - 'A'];
		
		if((ch >= 'a') && (ch <= 'z')){
		//if((newCH == '\0') || ((newCH < 65) || newCH > 90)){
			//newCH = table2[ch - 'a'];
			//ch-=32;
			newCH = table[ch - 'a']+32;
			//newCH+=32;
		}
		else{
			newCH = table[ch - 'A'];
		}
		

		str[i] = newCH;
		
		
	}//end of for loop
}//end of encode


void decode(char str[]){
	//declare and initialize variables
	//const char table[] = "XOYQMCRGUKSWAFLNTHDJPZIBEV";
	//const char table2[] = "xoyqmcrgukswaflnthdjpzibev";
	int len = strlen(str);
	//char newCH;
	
	//encode string
	for(int i =0; i < len;i++){
		char ch = str[i];
		
		for(int j =0; j < 26; j++){
			if(ch == table[j]){
				str[i] = 'A' + j;
			}

		}


		//str[i] = newCH;
		
		
	}//end of for loop
}//end of decode
