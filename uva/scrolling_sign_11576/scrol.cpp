#include<iostream>
#include<string>

using namespace std;

void kmp_preprocess(string pat, int* lps){
    int len = 0;
    lps[0] = 0;
    int M = pat.length();

    int i = 1;
    while(i<M){
        if(pat[i] == pat[len]){
            len++;
            lps[i] = len;
            i++;
        }

        else{
            if(len!= 0){
                len = lps[len-1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
}

int kmp_search(string pat, string txt, int* lps){
    
    int M = pat.length();
    int N = txt.length();

    int i = 0, j = 0;
    while(i < N){

        if(pat[j] == txt[i]){
            j++;
            i++;
        }

        if(j == M){
            return i-j;
        }


        else if(i < N && pat[j] != txt[i]){
            if(j!= 0) j = lps[j-1];
            else i++;
        }


    }
    return -1;

}

int main(){
    int n;
    cin >> n;
    while(n--){
        int k, w;
        long long scrolled = k;
        cin >> k >> w;
        string before, next;
        cin >> before;
        w --;

        while(w--){
            cin >> next;
            if(next == before) continue;
            int lps[k];
            kmp_preprocess(next,lps);
            int i = k-2;
            while(i >= 0)

                
        }
         

    }
}

