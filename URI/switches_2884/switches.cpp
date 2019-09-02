#include<iostream>
#include<set>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

typedef long long ll;

set<vector<int> > estados;

int main()
{
    ll n,m; // N interruptores M lâmpadas.

    cin >> n >> m;

    int l, i; // L = lampadas ligadas

    cin >> l;

    vector<int> ligadas;

    while(l--)
    {  
        cin >> i;

        ligadas.push_back(i);

    }

    map<int, vector<int> > interruptores;

    for(int j = 0; j < n; j++)
    {
        vector<int> aux;
        cin >> i;
        int lampada;
        while(i--)
        {
            cin >> lampada;
            aux.push_back(lampada);
        }
        
        interruptores[j] = aux;

    }

    // pre processssssamento

    map<int, vector<int> > list_lamp;

    for (int i = 1; i <= m; i++){
        vector<int> sequencia (n+1);
        sequencia.push_back(1);
        for(int j = 0; j < n; j++){
            if(count(interruptores[j].begin(), interruptores[j].end(), i)){
                sequencia.push_back(1);
            }
            else sequencia.push_back(0);

        }
        list_lamp[i] = sequencia;

    }

    int resp = 0;
    while(true){
        if(estados.count(ligadas)) {
            resp = -1;
            break;
        }

        estados.insert(ligadas);
        for (int i = 0; i < n; i++){
            int achou = 1;
            for(int j = 1; j < m; j++){
                int val= list_lamp[j][i];
                if ((val && ligadas.count(j)) || (!val && !ligadas.count(j))) {
                    achou = 0;
                    break;
                }
            }
            if (achou) break;

        }
        if (achou) break;

    }
}