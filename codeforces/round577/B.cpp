#include<iostream>
#include<vector>


using namespace std;


int main(){

    int n,i;
    vector<long> vec;
    cin>>n;
    long soma = 0;
    long maior = 0;
    for(i = 0; i <n;i++){
        long aux;
        cin >> aux;
        vec.push_back(aux);
        soma += aux;
        if(aux > maior) maior = aux;
    }

    if(soma % 2 || soma - maior > maior){
        cout << "NO" <<endl;
        return 0;
    }
    cout << "YES" << endl;
    return 0;
}
