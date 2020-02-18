#include<iostream>
#include<string>
#include<algorithm>
#include<utility>
using namespace std;

pair<int,int> count_char(string st){
    int u_count = 0;
    int r_count = 0;
    int d_count = 0;
    int l_count = 0;

    for(int i = 0; i < st.length(); i++){
        if(st[i] == 'U') u_count++;
        if(st[i] == 'R') r_count++;
        if(st[i] == 'D') d_count++;
        if(st[i] == 'L') l_count++;
    }

    int h_value = min(r_count, l_count);
    int v_value = min(u_count, d_count);
    return make_pair(h_value,v_value);
}


int main(){
    int k;
    cin >> k;
    while(k--){
        string st;
        cin >> st;
        pair<int, int> nums = count_char(st);
        
        if(nums.first*nums.second > 0){
            cout << nums.first*2 + nums.second*2 << endl;
            

            string ans = "";
            for(int i = 0; i < nums.second; i++) ans+= "U";
            for(int i = 0; i < nums.first; i++) ans+= "R";
            for(int i = 0; i < nums.second; i++) ans+= "D";
            for(int i = 0; i < nums.first; i++) ans+= "L";
            cout << ans << endl; 
        }

        else if(nums.first == 0 && nums.second != 0){
            cout << 2 << endl;
            cout << "UD" << endl;
        }
        else if(nums.second == 0 && nums.first != 0) {
            cout << 2 << endl;
            cout << "RL" << endl;
        }

        else{
            cout << 0 << endl<< endl;
        }
    }


}

