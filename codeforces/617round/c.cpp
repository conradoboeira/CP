#include<iostream>
#include<map>
#include<utility>
#include<string>

using namespace std;

int main(){
    int n;
    cin >> n;
    while (n--){
        int len;
        cin >> len;
        map< pair<int, int>, int> posi;
        int smallest = -1;
        //check string max size
        string moves;
        cin >> moves;
        pair<int, int> posicao = make_pair(0,0);
        pair<int, int> answer = make_pair(0,0);
        posi[posicao] = 0;
        for(int i = 1; i <= len; i++){
            char c = moves[i-1];
            if(c == 'L') posicao.first -= 1;
            else if(c == 'R') posicao.first += 1;
            else if(c == 'U') posicao.second += 1;
            else if(c == 'D') posicao.second -= 1;
            
            if ( posi.find(posicao) == posi.end() ) {
                posi[posicao] = i;
            } 
            else {
                int dif = i - posi[posicao];
                if(dif < smallest || smallest == -1){
                    smallest = dif;
                    answer = make_pair(posi[posicao]+1, i );
                }
                posi[posicao] = i;
            }
        }
        if (smallest < 0) cout << "-1"<< endl;
        else cout << answer.first << " " << answer.second << endl;

    
    }
}
