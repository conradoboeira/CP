#include<iostream>
#include<string>
#define ascii 32

using namespace std;

int main(){
    string str;
    cin >> str;

    int i, size;
    bool nada_mudou;
    while(true){
        nada_mudou = true;
        i = 0;
        while(i < str.size()-1){
            int c1, c2;
            c1 = (int) str[i];
            c2 = (int) str[i+1];
        
            if((c1 + ascii == c2) || (c1 - ascii == c2)){
                str.erase(i,1);
                str.erase(i,1);
                nada_mudou = false;
                break;
            }
            else i++;
        }
        if(nada_mudou) break;
    }

    cout << str.size() << endl;
}
