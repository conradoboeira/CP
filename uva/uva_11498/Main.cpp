#include <iostream>
using namespace std;


int main(){
    int k, n, m, x,y;
    while (true){
        cin >> k;
        if(!k) break;
        cin >> n >> m;
        while(k--){
            cin >> x >> y;
            if(x== n || y == m) cout << "divisa" << endl;
            else{
                if(y> m) cout << "N";
                else cout << "S";
                if( x > n) cout << "E" << endl;
                else cout << "O" << endl;
            }
        }
    }
}
