#include <stdio.h>
#include<string.h>

int main(){
	char buffer[100] = "strcmp str1 str2";;
	char "token;
	token = strtok(buffer," ");
	printf("1: %s\n", token); //strcmp
	token = strtok(NULL," " );
	printf("2: %s\n", token); //str1
	token = strtok(NULL," " );
	printf("3: %s\n", token); //str2

	return 0;
}