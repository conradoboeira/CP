#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#define pb push_back
using namespace std;

typedef long long ll;

vector<int> recursao(int i, vector<int> entrada, vector<int> alone){
  if(i >= entrada.size()) return entrada;
  if(entrada[i] != 0){
    if(i == entrada.size()-1) return entrada;
    return recursao(i+1, entrada, alone);
  } 
  
  if(alone.size() == 0) return entrada;
  
  for (int j = 0; j < alone.size(); j++){
    int gift = alone[j];
    if(gift == i) continue;
    entrada[i] = gift;
    vector<int> copy = alone;
    copy.erase(copy.begin()+j);
    vector<int> lil_resp = recursao(i+1, entrada, copy);
    if(lil_resp[0] > 0){
      return lil_resp;
    }
    entrada[i] = 0;
  }
  entrada[0] = -1;
  return entrada;
  
}

int main() {
  int n;
  cin >> n;
  vector<int> entrada(n);
  vector<int> alone;
  for(int i = 1; i<= n; i++) alone.pb(i);
  cout << "oi1"<< endl; 
  for(int i = 0; i < n; i++){
	int temp;
    cin >> temp;
    entrada.pb(temp);
    if(temp == 0) continue; 
  	alone.erase(find(alone.begin(),alone.end(),temp));
  }
  
  cout << "oi2"<< endl;
  vector<int> resposta = recursao(0, entrada, alone);
  cout << "oi3"<< endl;
  for(int i = 0; i< n; i++) cout << resposta[i] << " ";
  cout << endl;
  
}

