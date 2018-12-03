#include<iostream>
#include<string>
#include<vector>
using namespace std;

int procura(string pal){
    int letras[128] = {0};
    int i;
    bool t2, t3;
    t2 = false;
    t3 = false;
    for(i = 0; i < pal.size(); i++){
        letras[(int)pal[i]] = letras[(int) pal[i]] + 1;
    }

    for(i = 0; i < 128; i ++) {
        if(letras[i] == 2) t2 = true;
        else if(letras[i] == 3) t3 = true;

        if(t2 && t3) break;
    }

    if(t2&&t3) return 4;
    else if(t2) return 2;
    else if(t3) return 3;
    else return 0;
}


int main(){
    string palavra;
    int tot2, tot3, resp;
    
    tot2 = 0;
    tot3 = 0;
    while(cin >> palavra){
        resp = procura(palavra);
        if(resp == 4){
            tot2 ++;
            tot3 ++;
        }
        else if(resp == 2) tot2++;
        else if(resp == 3) tot3++;
    }
    
    cout << tot2 * tot3 << endl;
    
}
