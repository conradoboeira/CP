#include<iostream>
#include<string>
using namespace std;

bool valid(int n){
  string str = to_string(n);
  bool rep = false;
  for(int i = 0; i < 5; i++){
    if(str[i] == str[i+1]) {
      bool back = (i == 0) || (str[i] != str[i-1]);
      bool front = (i == 4) || (str[i] != str[i+2]);
      if(back && front) rep = true;
    }
    if(str[i] > str[i+1]) return false;
  }
  return rep;
}

int main(){
  cout << valid(112233) << endl;
  cout << valid(123444) << endl;
  cout << valid(111122) << endl;
  int beg = 254032;
  int end = 789860;
  int count = 0;
  while(beg <= end){
    if(valid(beg)) count ++;
    beg++;
  }

  cout << count << endl;

}
