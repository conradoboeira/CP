#include<iostream>
#include<string>

typedef long ll;
using namespace std;


ll calcula_path(){
    string cur;
    ll paths = 1;
    while(true){
        cin >> cur;
        if(cur[0] == 'E') break;
        if(cur == "S") continue;
        paths *= calcula_path() + calcula_path();
    }
    return paths;
}

int main(){
    int N;
    cin >> N;
    while(N--){
        cout << calcula_path() << endl;
    }
}
