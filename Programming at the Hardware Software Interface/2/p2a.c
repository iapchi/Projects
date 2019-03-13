/*
Jacky Li

*/
//Header Files
#include <stdio.h>
#include <string.h>
//function for radix control 16 max
char radix(int num)
{
   if (num >= 0 && num <= 9)
       return (char)(num + '0');
   else
       return (char)(num - 10 + 'A');
}
//Math converting and reversing to print out results
char* convert(char result[], int base, int anum)
{
   int index = 0;
   while(anum > 0)
   {
       result[index++] = radix(anum % base);
       anum /= base;
   }

   result[index] = '\0';
   int len = strlen(result);
   int i;
	for (i = 0; i < len/2; i++)
	{
		char temp = result[i];
		result[i] = result[len-i-1];
		result[len-i-1] = temp;
	}
   return result;
}
//Main function
int main()
{
//Variables
   int anum , base;
   do{
		printf("Enter decimal and radix :\n");fflush(stdout);
		scanf("%d %d",&anum , &base);
		char result[100];
		printf("%s\n",convert(result, base, anum));fflush(stdout);
   }while(base >=2);
   return 0;
}
