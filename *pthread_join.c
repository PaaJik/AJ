#include <stdio.h>
#include <pthread.h>

void *do_sum(void *); // 스레드가 수행할 함수
//인자로 받은 수까지의 합을 출력

int main() {
    pthread_t thread_id[3];
    int status[3];
    int a = 4; //첫번째 스레드의 인자
    int b = 5;
    int c = 6;
}
