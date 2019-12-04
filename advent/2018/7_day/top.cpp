#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

class Nodo{
    public:
    char nome;
    vector <Nodo> filhos;
};

bool inc (vector<char> v, char c){
    int i;
    bool achou = false;
    for(i = 0; i < v.size(); i++){
        if(v[i] == c) achou = true;
    }
    return achou;
}

int main(){
    char c1, c2;
    vector<char> nodes;
    map<char, Nodo> dici;
    while(scanf("Step %c must be finished before step %c can begin.", &c1, &c2) 
            != EOF ){
        
        //tem nodo de partida
        if(inc(grafo,c1)){
            //tem nodo de chegada tbm
            if(inc(grafo, c2)){
                dici[c1].filhos.push_back(dici[c2]);
            }
            //n tem chegada
            else{
                nodo nd;
                nd.nome = c2;
                dici[c1].filhos.push_back(nd);
            }
        }
        //n tem partida
        else{
            if(inc(grafo,c2)){
                nodo nd;
                nd.nome = c2;
                    
            }
        }   

    
    }
}
