#include<iostream>

using namespace std;

int main(){
    int n,m,c;
    long double r;
    long resp;
    while(true){
        cin >> n >> m >> c;
        if(!n) break;
        
        r = ((n-7)*(m-7))/2.0;
        resp = (long) r;
        if(r-resp >= 0.4 && c)resp++;
        
        cout << resp << endl;
    }
    return 0;
}