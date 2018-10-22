#include <stdio.h>
using namespace std;

int main(){
    int k , t, i, maior, atual;
    scanf("%d", &k);
    for(i = 1; i <= k; i ++){
        maior = 0;
        scanf("%d", &t);
        while(t--){
            scanf("%d", &atual);
            if(atual > maior) maior = atual;
        }
        printf("Case %d: %d\n", i, maior);
    }
}
