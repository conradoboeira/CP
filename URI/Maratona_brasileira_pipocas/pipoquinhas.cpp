#include <iostream>
#include <math.h>

using namespace std;

bool testa(int* pacotes, int n, int c, int soma) {

    int s_at = 0;
    for(int i = 0; i < n; i ++) {

        if(s_at + pacotes[i] > soma) {
            c--;
            s_at = 0;
            if(!c) return false;
        }
        s_at += pacotes[i];
    }
    return true;
}

int main() {
    int n,c,t, maior, soma, aux;
    cin >> n >> c >> t;
    int pacotes[n];
    maior = soma = 0;

    for (int i = 0; i < n; i++) {
        cin >> aux;
        soma += aux;
        if(aux>maior) maior = aux;
        pacotes[i] = aux;
    }

    int minimo = maior;
    int maximo = soma;
    int meio;
    while(true) {
        meio = (minimo + maximo) /2;
        bool r = testa(pacotes, n, c, meio);
        if(r) maximo = meio;
        else minimo = meio +1;
	if(maximo == minimo) break;
    }

    cout << maximo/t + ( maximo % t > 0 ) << endl;

}
