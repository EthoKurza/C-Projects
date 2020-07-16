#include <stdio.h>
#include <string.h>
#include "Stack.h"



int main(int argc, char** argv) {
    initStack();
    
    // Input string and push it character by character
    char str[256] = "";
    printf("Enter a string: ");
	scanf("%255s", str);
    
    int len = strlen(str);
    for(int i = 0; i < len; i++){
    	push(str[i]);	
	}
    
    
    
    // Pop and print all the character in the stack. Can also use: while (!isEmpty())
    while(!isEmpty()){
    	char ch = pop();
    	if (ch == ROGUEVALUE) {
            break;
        }
        printf("%c", ch);
	}
    while (true) {
        int ch = pop();
        if (ch == ROGUEVALUE) {
        	printf("%c", ch);
            break;
        }
        printf("%c", ch);
    }
    
}
