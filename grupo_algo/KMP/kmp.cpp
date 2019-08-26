#include <iostream>
#include <string>

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

void kmp_search(string pat, string txt, int* lps){
    
    int M = pat.length();
    int N = txt.length();

    int i = 0, j = 0;
    while(i < N){

        if(pat[j] == txt[i]){
            j++;
            i++;
        }

        if(j == M){
            cout << "Found pattern at index: " << i-j << endl;
            j= lps[j-1];
        }


        else if(i < N && pat[j] != txt[i]){
            if(j!= 0) j = lps[j-1];
            else i++;
        }


    }

}

int main(){

    string txt = "ABABDABACDABABCABAB"; 
    string pat = "ABABCABAB"; 
    int lps[pat.length()];
    kmp_preprocess(pat,lps);
    kmp_search(pat,txt,lps);
}
