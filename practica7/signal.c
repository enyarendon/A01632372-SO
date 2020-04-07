#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void processSignal(int s){
    printf("Recibi señal %d\n",s);
}
void processSignal15(int s){
    printf("No me puedes matar %d\n",s);
    while(1){
        sleep(3);
        printf("Trabajando\n");
    }
}
int main(void){
    signal(10,processSignal);
    signal(15,processSignal15);
    while(1){
        sleep(3);
        printf("Trabajando\n");
    }
    return 1;
}