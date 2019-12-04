#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main(){
	ll N, aux, maior =0;
  vector<ll> sobrando;
  vector<ll> diff;
  cin >> N;
  for(ll i = 0; i < N; i++){
    cin >> aux;
    if(aux > maior) maior = aux;
    sobrando.push_back(aux);
  }
  
  for(ll i = 0; i < N; i++){
    if(sobrando[i] == maior) continue;
    diff.push_back(maior - sobrando[i]);
  }
  
  ll elem = diff[0];
  
  for(ll i = 1; i< diff.size(); i++){
  	elem = __gcd(elem, diff[i]);  
  }
  
  ll count = 0;
  for(ll i = 0; i < diff.size(); i++){
    count += diff[i]/elem;
  }
  
  cout << count << " " << elem << endl;  
}

