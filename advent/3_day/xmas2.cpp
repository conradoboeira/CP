#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

struct squares{
    int id;
    int left;
    int top;
    int widht;
    int length;
};

int main(){

    int id, left, top, widht, length, resp, i, j,q, resp_id;
    resp = 0;
    bool unico;
    int matriz[1000][1000] = {0};
    vector <squares> quadrados;
    while(scanf("#%d @ %d,%d: %dx%d\n", &id, &left, &top, &widht, &length) != EOF){
        for(i = left; i < left + widht; i ++){
            for(j = 1000 - top; j > 1000 - top - length; j --){
                matriz[i][j] ++;
            }
        }
        squares qd;
        qd.id = id;
        qd.left = left;
        qd.top = top;
        qd.widht = widht;
        qd.length = length;
        quadrados.push_back(qd);

    }
    for(q = 0; q < quadrados.size(); q ++ ){
        squares qd = quadrados[q];
        unico = true;
        for(i = qd.left; i < qd.left + qd.widht; i ++){
            for(j = 1000 - qd.top; j > 1000 - qd.top - qd.length; j --){
                if(matriz[i][j] > 1) {
                    unico = false;
                    break;
                }
            }
            if(!unico) break;
        }
        if(unico) {
            resp_id = qd.id;
            break;
        }
    }

    cout << resp_id << endl;

}
