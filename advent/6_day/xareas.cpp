#include<iostream>
#include<stdio.h>
#include<vector>

struct point{
    int x;
    int y;
}

// 1 = tl, 2 = tr, 3 =bl, 4 = br
int find_pos(point p1, point p2){
    if(
}

int main(){
    int x, y, i, j;
    vector<point> pontos;
    point ponto;

    while(scanf("%d, %d", &x, &y) != EOF){
        ponto.x = x;
        ponto.y = y;
        pontos.push_back(ponto);
    }

    point tl, tr, bl, br;
    int dist_tl, dist_tr, dist_bl, dist_br;
    for(i = 0; i < pontos.size(); i++){
        point pt = pontos[i];
        dist_tl = dist_tr = dist_bl = dist_br = 1000;
        for(j = 0; j < pontos.size(); j ++){
            if(j == i) continue;

        }


    }


}
