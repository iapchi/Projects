/*
Jacky Li

*/
//Header Files
#define _XOPEN_SOURCE 700
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM 20
//Function to set values for blanks
int Spaces(char anum[], int i, int len){
	while(anum[i]==' '|| anum[i]=='\t')
		i++;
	return i;
}
//Math operations with switch
int operate(int first, int second, char bnum){
	int result = 0;
		switch(bnum){
			case '+':
			result = first+second;
			break;
			case '-':
			result = first-second;
			break;
			case '*':
			result = first*second;
			break;
			case '/':
			result = first/second;
			break;
			default:
			result = first;
	}}
//Main method
int main(){
	char anum[NUM] = {'\0'};
	int i;
	printf("Enter expression from left to right\n");fflush(stdout);
//Math and cases for expressions of input
	fgets(anum, 20, stdin);
//Flag for first term
    bool flag = true;
    int result = anum[0] - '0';
    int len = strlen(anum);
//Length loop
	if(len == 1){
		printf("%c\n",anum[0]);;fflush(stdout);
	}
	else{
		for (i = 0; i < len;){
            int first;
            if(flag)
            {
                first = anum[i++] - '0';
                flag = false;
            }
            else
            {
                first = result;
            }
			i = Spaces(anum, i ,len);
			if(i >= len)
			break;
        char bnum = anum[i++];
        i = Spaces(anum, i, len);
        if(i >= len)
            break;
		int second = anum[i++] - '0';
		result = operate(first, second, bnum);
	}}
//prints solution
	printf("%d\n", result);fflush(stdout);
	return 0;
}
