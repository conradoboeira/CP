#include<vector>
#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int main(){
	int nhp, myatk, opatk, sp;
  cin >> nhp >> myatk >> opatk >> sp;
	vector<int> mhp(nhp);
  for(int i = 0; i<nhp; i++)
    cin >> mhp[i];
  vector<int> resto;

  int pontos=0;
  for(int i=0; i<nhp; i++) {
    int restinho = mhp[i] % (myatk+opatk);
    if (restinho == 0 || restinho > myatk) {
      restinho = (restinho==0) ? (myatk+opatk) : restinho;
      restinho -= myatk;

      //qtd specials
      restinho = ceil( ((float)restinho/myatk) );
      resto.push_back(restinho);
    } else {
      pontos++;
    }

  }

  if(resto.size() == 0){
    cout << pontos  << endl;
    return 0;
  }
  //sort
  //int n = sizeof(resto)/sizeof(resto[0]);
  sort(resto.begin(), resto.end());


  int spsum=0, j=0;
	for( int i=0; i<resto.size(); i++ ) {
    if (spsum+resto[i] <= sp)	{
      spsum += resto[i];
      pontos++;
    }
    else break;
  }

  cout << pontos << endl;

}

