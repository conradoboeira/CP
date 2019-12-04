#include<iostream>
#include<stdio.h>

using namespace std;

int main(){

    int id, left, top, widht, length, resp, i, j;
    resp = 0;
    int matriz[1000][1000] = {0};
    while(scanf("#%d @ %d,%d: %dx%d\n", &id, &left, &top, &widht, &length) != EOF){
        for(i = left; i < left + widht; i ++){
            for(j = 1000 - top; j > 1000 - top - length; j --){
                if(matriz[i][j] == 1) resp ++;
                matriz[i][j] ++;
            }
        }
    }

    cout << resp << endl;

}
