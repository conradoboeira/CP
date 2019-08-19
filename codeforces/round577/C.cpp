#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void imprime(vector<long> v){
    int i;
    for(i = 0; i < v.size(); i ++){

        cout << v[i];
    }

    cout << endl;
}


int main(){

    long n,k,aux;
    vector<long> vec;
    cin>> n>>k;
    for(long i = 0; i < n; i ++){
        cin >> aux;
        vec.push_back(aux);
    }
    sort(vec.begin(), vec.end());
    long middle = n/2;
    
    while(k--){
        vec[middle]++;
        long index = middle +1;
        while(vec[middle] > vec[index] && index < n) index ++;
        sort(vec.begin()+middle, vec.begin()+index );
    }
    cout << vec[middle]<< endl;

    return 0;
}
