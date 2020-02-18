#include<iostream>
#include<utility>
#include<vector>

using namespace std;
vector<int> par;
vector<int> inpar;

int rec(int pos, vector<int> vec, int inpare){
    if(pos >= vec.size() || pos < 0) return -1;
    //cout << vec[pos]<< endl;
    //cout << inpare << " " << vec[pos]%2 << endl;
    if(!inpare && vec[pos]%2==1) return 0;
    if(inpare && vec[pos]%2==0) return 0;

    /* 
    if(!inpare && inpar[pos] != -1){
        if(inpar[pos] == 0) return -1;
        else return inpar[pos];
    }
    if(inpare && par[pos] != -1){
        if(par[pos] == 0) return -1;
        else return par[pos];
    }
    */
    
    

    int left = rec(pos - vec[pos], vec, inpare);
    int right = rec(pos + vec[pos], vec, inpare);
    //cout <<pos << ": "<< left << " " << right << endl;
    if(left == -1 && right == -1){
        //if(inpare) inpar[pos] = 0;
        //else par[pos] = 0;
        return -1;
    }
    else{
        if(left == -1){
            //if(inpare) inpar[pos] = 1+right;
            //else par[pos] = 1+ right;
            return 1+ right;
        }
        if(right == -1){
            //if(inpare) inpar[pos] = 1+ left;
            //else par[pos] = 1+ left;
            return 1+ left;
        }
        else{
            int ans = min(right, left);
            //if(inpare) inpar[pos] = 1+ans  ;
            //else par[pos] = 1+ans  ;
            return 1+ans  ;

        }
    }

}


int main(){

    int k;
    cin >> k;
    vector<int> vec(k);
    for(int i = 0; i < k; i++){
        cin>> vec[i];
    }
    //par.assign(k,-1);
    //inpar.assign(k,-1);
    //for(int i = 0; i < k; i++) cout << vec[i]<< " ";
    //cout << endl;

    for (int i = 0; i <k; i++){
        int ans = rec(i,vec, vec[i]%2);
        cout << ans;
        //cout << "END"<< endl;
        //if(i == 1) break;
        if(i< k-1) cout << " ";
    }
    cout << endl;

}
