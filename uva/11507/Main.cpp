#include <string>
#include <iostream>
using namespace std;
string contrario(string signal);
int main(){
    int l;
    string bend, curr_signal, curr_co, bend_signal, bend_co;
    while(true){
        cin >> l;
        if(l == 0) break;
        l--;
        curr_signal = "+";
        curr_co = "x";
        while(l--){
            cin >> bend;
            if(bend == "No") continue;
            bend_signal = bend[0];
            bend_co = bend[1];
            if(curr_co == "x"){
                curr_co = bend_co;
                if(curr_signal == "+") curr_signal = bend_signal;
                else curr_signal = contrario(bend_signal);
            }
            else{
                if(curr_co != bend_co){
                    continue;
                }
                else{
                    curr_co = "x";
                    if(curr_signal == bend_signal) curr_signal = "-";
                    else curr_signal = "+";
                }
            }
        }
        cout << curr_signal << curr_co << endl;
    }
}
string contrario(string signal){
    if(signal == "+") return "-";
    else return "+";
}
