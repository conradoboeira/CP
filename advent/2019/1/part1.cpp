#include<iostream>
using namespace std;

int main(){
  int val, sum;
  sum = 0;
  while(cin>>val){
    sum += ((int) val/3) -2;
  }
  cout << sum << endl;
}
