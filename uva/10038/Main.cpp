#include <iostream>
#include <cmath>
using namespace std;

int main(){

    long val1, val2;
    int n, i;
    bool is_jolly;

    while(true){

        cin >> n;
        if(cin.eof()) break;

        bool check [n];
        for(i = 0; i < n; i ++) check[i] = false;

        cin >> val1;
        for(i = 0; i < n -1; i++){
            cin >> val2;
            check [(int) abs(val1 - val2)] = true;
            val1 = val2;
        }

        is_jolly = true;

        for(i = 1; i < n; i ++){
            if(!check [i]){
                is_jolly = false;
                break;
            }
        }

        if(is_jolly) cout << "Jolly" << endl;
        else cout << "Not jolly" << endl;

    }

}
