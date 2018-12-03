#include <iostream>
using namespace std;


int main(){
    int k, s1, s2, s3, i, resp;
    cin >> k;
    for(i = 1; i <= k; i++){
        cin >> s1 >> s2 >> s3;

        if(s1 > s2){
            if(s1 < s3) resp = s1;
            else resp = (s2 > s3) ? s2 : s3;
        }

        else if(s2 > s3){
                resp = (s1 > s3) ? s1 : s3;
        }

        else resp = s2;

        cout << "Case " << i << ": " << resp << endl;
    }
}
