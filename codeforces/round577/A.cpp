#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
    
    int n,m;
    vector<string> respostas;    
    vector<int> valores;
    cin >> n >> m;
    
    while(n--){
        string resp;
        cin >> resp;
        respostas.push_back(resp);
    }
    for(int i = 0; i < m; i ++){
        int val;
        cin >> val;
        valores.push_back(val);
    }
    int maior, custo_total;
    custo_total = 0;
    for(int i = 0; i < m; i++){
        int cont[5] = {0,0,0,0,0};
        maior = 0;
        for(int j = 0; j < respostas.size(); j++){
            string atual = respostas[j];
            int index = (int) atual[i] - (int) 'A';
            cont[index] ++;
        
        }
        
        for(int j = 0; j < 5; j++){
            if(cont[j]> maior) maior = cont[j];
        }
    
        custo_total += maior*valores[i];
    }

    cout << custo_total << endl;
    return 0;
}
