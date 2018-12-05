#include<iostream>
#include<string>
#include<algorithm>
#define ascii 32
#define alfa 26

using namespace std;

string remove(int i, string str){
    char c1, c2;
    c1 = (char) (i + 65);
    c2 = (char) ((int)c1 + ascii);
    str.erase(remove(str.begin(), str.end(), c1), str.end());
    str.erase(remove(str.begin(), str.end(), c2), str.end());
    return str;
}

int colapse(string str){
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
    return str.size();

}

int main(){
    string str;
    cin >> str;
    int i, smallest, curr;
    smallest = 1000000;
    for(i = 0; i < alfa; i++){
        string st2 = remove(i, str);
//        cout << st2 << endl;
        curr = colapse(st2);
        if(curr < smallest) smallest = curr;
    }

    cout << smallest << endl;
}
