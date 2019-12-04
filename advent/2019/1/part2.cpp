#include<iostream>
using namespace std;

int rec(int num){
  int fuel = ((int) num/3) -2; 
  if(fuel <=0) return 0;
  else return fuel + rec(fuel);
}

int main(){
  int val, sum;
  sum = 0;
  while(cin>>val){
    sum += rec(val);
  }
  cout << sum << endl;
}
