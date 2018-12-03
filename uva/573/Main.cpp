#include <stdio.h>
using namespace std;

int main(){
    int height, down, f, dia, climb;
    float altura, fatiga, speed;
    while(1){
        scanf("%d %d %d %d", &height,&climb,&down,&f);
        if(height == 0) break;
        dia = 1;
        altura = 0;
        speed = climb;
        fatiga = climb * (f/100.0);

        while(1){
            altura += speed;
            // printf("altura:%lf\n", altura);
            if(altura > height){
                printf("success on day %d\n", dia);
                break;
            }
            altura -= down;
            if(altura < 0){
                printf("failure on day %d\n", dia);
                break;
            }

            speed -= fatiga;
            if(speed < 0) speed = 0;
            dia ++;
        }
    }


}
