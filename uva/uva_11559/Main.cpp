#include <stdio.h>
#include <limits>
using namespace std;

int main(){

    int n, b, h, w;
    while(scanf("%d %d %d %d", &n, &b, &h, &w) != EOF){
        // printf("num:%d\n", n);
        // printf("bud:%d\n", b);
        // printf("weeks:%d\n", w);
        int cost, num_people, min_cost, i;
        int first = 1;
        min_cost = 0;

        while(h--){
            scanf("%d", &cost);
            int cabe = 0;
            for(i = 0; i < w; i++){
                scanf("%d", &num_people);
                if(num_people >= n){
                    cabe = 1;
                }
            }
            if(cabe && cost * n < b ){
                // printf("cabe:%d\n", cabe);
                if(first || cost * n < min_cost ){
                    min_cost = cost * n;
                    first = 0;
                }
            }
        }


        if(!min_cost) printf("stay home\n");
        else printf("%d\n", min_cost);
    }
}
