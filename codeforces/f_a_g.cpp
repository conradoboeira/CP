#include<iostream>
#include<vector>
#define vi vector<int>

using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vi entrada(n), givers(n), takers(n);
    
    for(int i = 0; i < n; i++){
      cin >> entrada[i];
      --entrada[i];
      if( entrada[i] > -1){
        givers[i] = 1;
        takers[entrada[i]] = 1;
      }
    }

    /*
    for(int i = 0; i < n; i++) cout << givers[i] << " ";
    cout << endl;
    for(int i = 0; i < n; i++) cout << takers[i] << " ";
    cout << endl;
    */

    vi lonely;
    for(int i = 0; i < n; i++){
      if(givers[i] == 0 && takers[i] == 0){
        lonely.push_back(i);
      }
    }
   
    //cout << lonely.size() << endl; 

    if(lonely.size() == 1){
      for(int i = 0; i < n; i++){
        if(takers[i] == 0 && i != lonely[0]){
          entrada[lonely[0]] = i;
          givers[lonely[0]] = 1;
          takers[i] = 1;
          break;
        }
      }
    }

    if(lonely.size() > 1){
      for(int i = 0; i < lonely.size(); i++){
        if(i == lonely.size() -1) {
          entrada[lonely[i]] = lonely[0];
          givers[lonely[i]] = 1;
          takers[lonely[0]] = 1;
        }
        else{
          entrada[lonely[i]] = lonely[i+1];
          givers[lonely[i]] = 1;
          takers[lonely[i+1]] = 1;
        }
      }
    }

    vi giv, tak;
    for(int i = 0; i < n; i++){
      if(givers[i] == 0) giv.push_back(i);
      if(takers[i] == 0) tak.push_back(i);
    }
    
    for(int i = 0; i < giv.size(); i++){
      entrada[giv[i]] = tak[i]; 
    }

    for(int i = 0; i < n; i++){
      cout << entrada[i] + 1 << " ";
    }
    cout << endl;
}
