#include<iostream>
#include<map>

using namespace std;

int main(){

    int c, n, maior, curr;
    long atual;
    cin >> c;

    while(c--){
        cin >> n;
        map<long,int> used;
        maior = curr = 0;
        for(int i = 1; i <= n; i++){
            cin >> atual;
            
            if(used[atual]>= (i-curr)) curr = i - used[atual];
            else curr ++;
            used[atual] = i;
            if(curr > maior) maior = curr;
        }
        cout << maior << endl;
    }

}
