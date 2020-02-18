#include<vector>
#include<iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    while(n--){
        int n2;
        cin >> n2;
        bool tudo_par = true;
        bool tudo_inpar = true;
        for(int i = 0; i < n2; i++){
            int aux;
            cin  >> aux;
          	if(aux%2!=0) tudo_par = false;
            else tudo_inpar = false;
          	
        }
      	if(tudo_par || (tudo_inpar && n2%2==0))cout << "NO" << endl;
        else cout << "YES" << endl;


    }

}

