#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <string.h>

#define PORT 10000
#define BUFSIZE 10000

char buffer[BUFSIZE] = "Hi, i'm server.\n";
//sizeof(buffer) => 100 (배열의 크기)
//strlen 
char rcvBuffer[BUFSIZE];

int main(){
	int c_socket, s_socket;
	struct sockaddr_in s_addr, c_addr;
	int len;
	int n;

	// 1. 서버 소켓 생성
	//서버 소켓 = 클라이언트의 접속 요청을 처리(허용)해 주기 위한 소켓
	s_socket = socket(PF_INET, SOCK_STREAM, 0); //TCP/IP 통신을 위한 서버 소켓 생성
	
	//2. 서버 소켓 주소 설정
	memset(&s_addr, 0, sizeof(s_addr)); //s_addr의 값을 모두 0으로  초기화
	s_addr.sin_addr.s_addr = htonl(INADDR_ANY); //IP 주소 설정
	s_addr.sin_family = AF_INET;
	s_addr.sin_port = htons(PORT);

	//3. 서버 소켓바인딩
	if(bind(s_socket,(struct sockaddr *) &s_addr, sizeof(s_addr)) == -1){ 
		//바인딩 작업 실패 시, Cannot Bind 메시지 출력 후 프로그램 종료
		printf("Cannot Bind\n");
		return -1;
	}
	
	//4.listen() 함수 실행
	if(listen(s_socket, 5) == -1){
		printf("listen Fail\n");
		return -1;
	}

	//5. 클라이언트 요청 처리
	// 요청을 허용한 후, Hello World 메세지를 전송함
	while(1){ //무한 루프
		len = sizeof(c_addr);
		printf("클라이언트 접속을 기다리는 중....\n");
		c_socket = accept(s_socket, (struct sockaddr *)&c_addr, &len); 
		//클라이언트의 요청이 오면 허용(accept)해 주고, 해당 클라이언트와 통신할 수 있도록 클라이언트 소켓(c_socket)을 반환함.
		printf("/client is connected\n");
		printf("클라이언트 접속 허용\n");
		while(1){
			n = read(c_socket, rcvBuffer,sizeof(rcvBuffer));
			printf("rcvBuffer: %s\n", rcvBuffer);
			if(strncasecmp(rcvBuffer, "quit",4) == 0 || strncasecmp(rcvBuffer, "kill server", 11) == 0
			   break;
			   else if (!strncasecmp(rcvBuffer,"안녕하세요",strlen("안녕하세요")))
				strcpy(buffer,"안녕하세요 만나서 반가워요"); //5-2 안녕하세요 -> 이름이 뭐야로 변경, 대답을 이름으로 변경, else if문을 늘릴수록 대답이 많아짐
			   else if (!strncasecmp(rcvBuffer,"strlen" , strlen("strlen ")))
				//문자열의 길이는 XX입니다.
				sprintf(buffer, "문자열의 길이는 %d입니다.",strlen(rcvBuffer)-7);	
			   else
				strcpy(buffer, "무슨 말인지 모르겠습니다");
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
	     sprintf(buffer, "%s와 %s는 다른 문자열입니다", str[1], str[2]);
			   
			   } else if (!strcmp(rcvBuffer, "readfile ")){
			   char *token;
				token - strtok(rcvBuffer, " "); //token = readfile
				token = strtok(NULL, " ");//token = <파일명>
				FILE *fp = fopen(token, "r");
				if(fp){//정상적으로 파일이 오픈된다면,
					char tempStr[BUFSIZE]; //파일 내용을 저장할 변수 
					memset(buffer, 0, BUFSIZE); //buffer 초기화 
					while(fgets(tempStr, BUFSIZE, (FILE *fp)){
						strcat(buffer, tempStr); // 여러 줄의 내용을 하나의 buffer에 저장하기 위해 strcat() 함수 사용
					}
					 fclose(fp);
				}else { //해당 파일이 없는 경우.
					strcpy(buffer, "해당 파일은 존재하지 않습니다");
			   }else
			   strcpy(buffer, "무슨 말인지 모르겠습니다");
			   
			   write(c_socket, buffer, strlen(buffer)); //클라이언트가
			   }
			   close(c_socket);
		
		
	printf("%s\n",buffer); //srpitnf는 버퍼에 저장하는것, 출력하려면 printf 사용
				    
			write(c_socket, buffer, strlen(buffer)); //클라이언트에게 buffer의 내용을 전송함
		close(c_socket);
		if (strncasecmp(rcvBuffer,"kill server", 11) == 0
		break;
	}
	close(s_socket);
	return 0;	
}
