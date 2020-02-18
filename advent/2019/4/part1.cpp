#include<iostream>
#include<string>
using namespace std;

bool valid(int n){
  string str = to_string(n);
  bool rep = false;
  for(int i = 0; i < 5; i++){
    if(str[i] == str[i+1]) rep = true;
    if(str[i] > str[i+1]) return false;
  }
  return rep;
}

int main(){
  cout << valid(111111) << endl;
  cout << valid(223450) << endl;
  cout << valid(123789) << endl;
  int beg = 254032;
  int end = 789860;
  int count = 0;
  while(beg <= end){
    if(valid(beg)) count ++;
    beg++;
  }

  cout << count << endl;

}
