#include <iostream>
#include <vector>

using namespace std;

int main(){
  int N, aux;
  vector<int> cams;
  cin >> N;
  for(int i = 0; i < N; i++){
    cin>>aux;
    cams.push_back(aux);
  }

  vector<int> marcado(N);
  vector<int> resp (N);
  int maior, count, maiorj;
  count = 0;
  
  for(int i = 0; i < N; i++){
    
    maior = maiorj = 0;
    
    for (int j = 0; j< N; j++){
      if(marcado[j]) continue;
      if(cams[j]> maior) {
        maior = cams[j];
        maiorj = j;
      } 
    }
    
    count += (i * maior)+1;
    resp[i] = (maiorj+1);
    marcado[maiorj] = 1;
  }
  
  cout << count <<endl;
  for(int i = 0; i < N; i++) cout << resp[i] << " ";
  cout << endl;
  
}
