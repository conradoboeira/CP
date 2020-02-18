#include<iostream>


using namespace std;

typedef long long ll;

int main() {
	ll t=0,n,k;
	cin >> t;
  while (t--){
  	cin >> n >> k;
  	ll safe = n/k;
    ll restante = n -k*safe;
    ll resp = restante - (int) k/2;
    if(resp < 0) cout << n << endl;
    else cout << (n-resp) << endl;
  }
}
