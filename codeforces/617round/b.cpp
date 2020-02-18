// 9876 => 10973 // 1097

#include<vector>
#include<iostream>

using namespace std;
int main(){
    int n;
    cin >> n;
  //num casos
    while(n--){
    	int x,sum=0;
      cin >> x;
      
      //resolv
      while(1) {
        int payback = x / 10;
        int restinho = x - payback;
        sum+= payback;
        
        x = payback + restinho;
        if (x<10) {
          sum+= x;
          break;
        }
      }
      cout << sum;

    }

}
