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
	if(idx < 3)
		strcpy(buffer, "문자열 비교를 위해서는 두 문자열이 필요합니다");
	else if(!strcmp(str[1], str[2])) //같은 문자열이면
	     sprintf(buffer, "%s와 %s는 같은 문자열입니다", str[1], str[2]);
	else
	     sprintf(buffer, "%s와 $s는 다른 문자열입니다", str[1], str[2]);
		
	printf("%s\n",buffer); //srpitnf는 버퍼에 저장하는것, 출력하려면 printf 사용
	return 0;
}
