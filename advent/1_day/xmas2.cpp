#include <iostream>
#include <vector>
using namespace std;

bool vec_handler(int freq, vector<int> &vec){
    int i;
    for(i = 0; i < vec.size(); i ++){
        if( vec[i] == freq) return true;
    }
    vec.push_back(freq);
    return false;
}

int main(){
    int freq, val, i;
    freq = 0;
    vector <int> freq_vec, val_vec;
    while(cin>>val) val_vec.push_back(val);
    
    i = 0;
    while(true){
        if(i >= val_vec.size()) i = 0;
        freq += val_vec[i];
        if(vec_handler(freq, freq_vec)) break;
        i ++;
    }

    cout << freq << endl;

}
