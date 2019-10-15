#include <stdio.h>
#include <string.h>

int main(){
	char buffer[100] = "strcmp str1 str2";;
	char *token;
	char *str[3];
	int idx = 0;
	token = strtok(buffer," ");
	printf("1: %s\n", token); //strcmp
	
	while (token != NULL){
		str[idx] = token;
		printf("str[%d] = %s\n", idx, str[idx]);
		idx++;
		token = strtok(NULL, " ");
	
	}
	return 0;
}
