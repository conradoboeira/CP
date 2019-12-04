#include <iostream>
#include <vector>

using namespace std;

struct sheet{
  int top;
  int bottom;
  int left;
  int right;
};

int biggerH(sheet w, sheet b) {
  return b.bottom <= w.bottom && b.top >= w.top;
}

int biggerV(sheet w, sheet b) {
  return b.left <= w.left && b.right >= w.right;
}

int main(){
		sheet white, b1, b2;
  	
  	cin >> white.left >> white.bottom >> white.right >> white.top;
  	cin >> b1.left >> b1.bottom >> b1.right >> b1.top;
  	cin >> b2.left >> b2.bottom >> b2.right >> b2.top;
  

      
    //maiorzao
  	if(biggerH(white,b1) && biggerV(white,b1)) {
      cout << "NO" << endl;
      return 0;
    }
    
    //change top limit
  	if(b1.bottom < white.top && b1.bottom > white.bottom && b1.top >= white.top){
      //if(b1.left <= white.left && b1.right >= white.right){
      if(biggerV(white,b1)) {
        white.top = b1.bottom;
      }
    }
  	//change bottom limit
  	if(b1.top > white.bottom && b1.top < white.top && b1.bottom <= white.bottom){
      //if(b1.left <= white.left && b1.right >= white.right){
      if(biggerV(white,b1)) {
        white.bottom = b1.top;
      }
    }

		//change left limit
  	if(b1.right > white.left && b1.right < white.right && b1.left <= white.left){
      if(biggerH(white,b1)){
        white.left = b1.right;
      }
    }
  
  	//change right limit
  	if(b1.left > white.left && b1.left < white.right && b1.right >= white.right){
      if(biggerH(white,b1)){
        white.right = b1.left;
      }
    }

//    cout << "Left " << white.left << endl;
//    cout << "Right " << white.right<< endl;
//    cout << "top " << white.top<< endl;
//    cout << "bottom " << white.bottom<< endl;
  
  	if(biggerH(white,b2) && biggerV(white,b2)) {
      cout << "NO" << endl;
      return 0 ;
    }
  
  	cout << "YES" << endl;


}
