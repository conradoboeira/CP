#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
    
    int resp, r1, r2;
    resp = 1;
    //Valeu JB!
    scanf("%d.%d", &r1, &r2);
    r2 = (r1 * 100) + r2;
    while(true){
        if((resp * r2) % 36000 == 0) break;
        resp ++;
    }
    cout << resp << endl;

}
