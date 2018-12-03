#include<iostream>
#include<vector>
using namespace std;

int compara(string pal1, string pal2){
    int i, diff_pos;
    bool diff, deu_bom;
    deu_bom = true;
    for(i = 0; i < pal1.size(); i++){
        if(pal1[i] != pal2[i]){
            if(diff) {
                deu_bom = false;
                break;
            }
            else {
                diff_pos = i;
                diff = true;
            }
        }
    }
    if(deu_bom) return diff_pos;
    else return -1;
}


int main(){

    string palavra;
    vector <string> palavras;
    int i, j, valor;

    while(cin >> palavra) palavras.push_back(palavra);

    valor = -1;
    for(i = 0; i < palavras.size() -1; i ++){
        for(j = i + 1; j < palavras.size(); j ++){
            valor = compara(palavras[i], palavras[j]);
            if(valor != -1){ 
                palavra = palavras[i];
                break;
            }
        }
        if(valor != -1) break;
    }

    palavra = palavra.erase(valor, 1);

    cout << palavra << endl;

}
