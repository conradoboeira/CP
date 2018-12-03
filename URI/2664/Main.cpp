#include <iostream>
using namespace std;

unsigned long mod(unsigned long num) {

    return num % 1000000007;

}

int recursao(int tempo, int estado, int max, int min, unsigned long **dp, bool **check ){
    if(estado > max || estado < min) return 0;
    if(tempo == 0) return 1;
    if(check[estado][tempo]) return dp[estado][tempo];
    // cout << dp[estado][tempo] << endl;

    unsigned long resp = mod(mod(recursao(tempo - 1, estado + 1, max, min, dp, check)) +
                         mod(recursao(tempo - 1, estado - 1, max, min, dp, check)));
    //cout << resp << endl;
    dp[estado][tempo] = resp;
    check[estado][tempo] = true;
    return resp;
}



int main(){
    int t,m, n, i; // t = tempo, m = minimo , n = maximo
    unsigned long resp = 0;

    cin >> t >> m >> n;


    unsigned long **dp = new unsigned long*[n+5];
    for(int l = 0; l < n+5; l ++) dp[l] = new unsigned long[t +5];

    bool **check = new bool*[n+5];
    for(int l = 0; l < n+5; l ++) check[l] = new bool[t +5];

    for(int j = 0; j < n + 5; j ++){
        for(int k = 0; k < t + 5; k ++){
            check [j][k] = false;
        }
    }


    for(i = m; i <= n; i ++){
        resp = mod(resp + recursao(t-1, i, n, m, dp, check));
    }

    //resp = (resp % 1000000000) + 7 ;
    cout << resp << endl;

}