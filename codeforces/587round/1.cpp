#include <iostream>
#include <string>

using namespace std;

int main(){
	
    string entrada, copy;
  	int count, tam, i;
  	char old;
  	cin>>tam>>entrada;
     
  	copy = entrada;
  	count = 0;

  	for(i = 0; i <tam; i++){
      if(i%2==0){
        old = entrada[i];
      }
      else{
        if(entrada[i] == old){
          count ++;
          copy[i] = (old == 'a') ? 'b' : 'a';
        }
      }
      
    }
  
  	cout << count << endl << copy << endl;
	
}
