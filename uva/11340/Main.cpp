#include <iostream>
#include <stdio.h>
using namespace std;


int main(){
    int N;
    cin >> N;
    while(N--){

        double valores[255];

        //inicializa valores como garantia
        for(int i = 0; i < 255; i ++) valores[i] = 0.0;

        int k, valor;
        char letra;
        cin >> k;
        while(k--){
            cin >> letra >> valor;
            valores[(int) letra] = valor / 100.0;
        }

        int m;
        double resp = 0.0;
        char texto [10000];
        char nothing [10000];
        cin >> m;
        cin.getline(nothing , 10000); //se livra do \n da linha anterior (tem jeitos mais bonitos mas assim funciona ué)

        while(m --){
            cin.getline(texto, 10000);
            // cout << texto[0] << texto [1] << texto[2] << endl;
            int i = 0;
            char aux;
            while(true){
                aux = texto[i];
                //cout << aux << endl;
                if(aux == '\n' || aux == '\0' ) break;
                resp += valores[(int) aux];
                i ++;
            }
        }

        printf("%.2f$\n", resp);
        // cout << resp << endl;

    }
}
