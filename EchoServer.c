#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <string.h>

#define PORT 10000

char buffer[100] = "Hi, i'm server.\n";
//sizeof(buffer) => 100 (�迭�� ũ��)
//strlen 
char rcvBuffer[100];

int main(){
	int c_socket, s_socket;
	struct sockaddr_in s_addr, c_addr;
	int len;
	int n;

	// 1. ���� ���� ����
	//���� ���� = Ŭ���̾�Ʈ�� ���� ��û�� ó��(���)�� �ֱ� ���� ����
	s_socket = socket(PF_INET, SOCK_STREAM, 0); //TCP/IP ����� ���� ���� ���� ����
	
	//2. ���� ���� �ּ� ����
	memset(&s_addr, 0, sizeof(s_addr)); //s_addr�� ���� ��� 0����  �ʱ�ȭ
	s_addr.sin_addr.s_addr = htonl(INADDR_ANY); //IP �ּ� ����
	s_addr.sin_family = AF_INET;
	s_addr.sin_port = htons(PORT);

	//3. ���� ���Ϲ��ε�
	if(bind(s_socket,(struct sockaddr *) &s_addr, sizeof(s_addr)) == -1){ 
		//���ε� �۾� ���� ��, Cannot Bind �޽��� ��� �� ���α׷� ����
		printf("Cannot Bind\n");
		return -1;
	}
	
	//4.listen() �Լ� ����
	if(listen(s_socket, 5) == -1){
		printf("listen Fail\n");
		return -1;
	}

	//5. Ŭ���̾�Ʈ ��û ó��
	// ��û�� ����� ��, Hello World �޼����� ������
	while(1){ //���� ����
		len = sizeof(c_addr);
		printf("Ŭ���̾�Ʈ ������ ��ٸ��� ��....\n");
		c_socket = accept(s_socket, (struct sockaddr *)&c_addr, &len); 
		//Ŭ���̾�Ʈ�� ��û�� ���� ���(accept)�� �ְ�, �ش� Ŭ���̾�Ʈ�� ����� �� �ֵ��� Ŭ���̾�Ʈ ����(c_socket)�� ��ȯ��.
		printf("/client is connected\n");
		printf("Ŭ���̾�Ʈ ���� ���\n");
		while(1){
			n = read(c_socket, rcvBuffer,sizeof(rcvBuffer));
			printf("rcvBuffer: %s\n", rcvBuffer);
			if(strncasecmp(rcvBuffer, "quit",4) == 0 || strncasecmp(rcvBuffer, "kill server", 11) == 0
			   break;
			   else if (!strncasecmp(rcvBuffer,"�ȳ��ϼ���",strlen("�ȳ��ϼ���")))
				strcpy(buffer,"�ȳ��ϼ��� ������ �ݰ�����"); //5-2 �ȳ��ϼ��� -> �̸��� ���߷� ����, ����� �̸����� ����, else if���� �ø����� ����� ������
			   else if (!strncasecmp(rcvBuffer,"strlen" , strlen("strlen ")))
				//���ڿ��� ���̴� XX�Դϴ�.
				sprintf(buffer, "���ڿ��� ���̴� %d�Դϴ�.",strlen(rcvBuffer)-7);	
			   else
				strcpy(buffer, "���� ������ �𸣰ڽ��ϴ�");
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
		strcpy(buffer, "���ڿ� �񱳸� ���ؼ��� �� ���ڿ��� �ʿ��մϴ�");
	else if(!strcmp(str[1], str[2])) //���� ���ڿ��̸�
	     sprintf(buffer, "%s�� %s�� ���� ���ڿ��Դϴ�", str[1], str[2]);
	else
	     sprintf(buffer, "%s�� $s�� �ٸ� ���ڿ��Դϴ�", str[1], str[2]);
		
	printf("%s\n",buffer); //srpitnf�� ���ۿ� �����ϴ°�, ����Ϸ��� printf ���
				    
			write(c_socket, buffer, strlen(buffer)); //Ŭ���̾�Ʈ���� buffer�� ������ ������
		close(c_socket);
		if (strncasecmp(rcvBuffer,"kill server", 11) == 0
		break;
	}
	close(s_socket);
	return 0;	
}