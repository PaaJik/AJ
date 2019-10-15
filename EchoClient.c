#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <string.h>

#define PORT 10000
#define IPADDR "127.0.0.1"
#define BUFSIZE 100

int main(){
	int c_socket; 
	struct sockaddr_in c_addr;
	int n;
	char rcvBuffer[BUFSIZE];//�������� ������ �޼����� �����ϴ� ����
	
	//1. Ŭ���̾�Ʈ ���� ����
	c_socket = socket(PF_INET, SOCK_STREAM, 0); //������ ������ �������� ����
	//2.���� ���� �ʱ�ȭ
	memset(&c_addr, 0, sizeof(c_addr));
	c_addr.sin_addr.s_addr = inet_addr(IPADDR); //������ IP ���� (127.0.0.1)
	c_addr.sin_family = AF_INET;
	c_addr.sin_port = htons(PORT);

	//3. ������ ����
	if(connect(c_socket, (struct sockaddr *) &c_addr, sizeof(c_addr)) == -1){
		//���� ���ӿ� �����ϸ� 
		printf("Cannot Connect\n"); //Cannot connect �޼��� ���
		close(c_socket); //�ڿ� ȸ��
		return -1;  //���μ��� ����
	}
	//4. �������� ���� �޽��� �б� 
	n = read(c_socket, rcvBuffer, sizeof(rcvBuffer)); 
	//�������� ������ �޼����� rcvBuffer�� �����ϰ�, �޼����� ���̸� ����
	//���� read�� �����ϸ�, -1�� ����
	if (n < 0){ //read() �Լ� ���� 
		printf("Read Failed\n");
		return -1;
	}
	rcvBuffer[n] = '\0'; //���ڿ� �޺κ� ���� ����
	printf("received data: %s\n", rcvBuffer); //�������� ���� �޼��� ���
	printf("rcvBuffer length: %d\n", n); //3-2. �������� ���� �޼����� ���� ��� 
	close(c_socket);
	return 0;	
}