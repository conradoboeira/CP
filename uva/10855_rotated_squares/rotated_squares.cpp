#include <iostream>
#include <string>

#define ROT 4 //numero de rotacoes

using namespace std;

char** rotaciona(char** matrix, int n){
    
    int i, j, pos_i, pos_j;
    char** resp = new char*[n];
    for(i = 0; i < n; ++i) resp[i] = new char[n]; 
    
    for(i = 0; i < n; i ++){
        for(j = 0; j < n; j++){
        
            pos_i = j;
            pos_j = n - (i+1);

            resp[pos_i][pos_j] = matrix[i][j];
        
        }
    }

    return resp;
    
}

int teste(char ** matrix_grande, char ** matrix_pequena, int N, int n){

    int resp, inicio_i, inicio_j, i, j, diff;
    resp = 0;

    for(inicio_i = 0; inicio_i <= (N-n); inicio_i ++){
        for(inicio_j = 0; inicio_j <= (N-n); inicio_j ++){
            diff = 0;
            for(i = inicio_i; i < (inicio_i + n); i ++) {
                for(j = inicio_j; j < (inicio_j + n); j++){
                     if(matrix_grande[i][j] != matrix_pequena[i-inicio_i][j-inicio_j]){
                        diff = 1;
                        break;
                     }

                }

                if(diff) break; 
            }

            if(!diff) resp++;
        }
    }

    return resp;
}

int main(){
    
    int n, N, i, j;
    string linha;

    while(true){
        
        cin >> N >> n;
        if(N == 0) break;
        
        int i;  
        char** matrix_grande = new char*[N];
        for(i = 0; i < N; i++) matrix_grande[i] = new char[N];
        char** matrix_pequena = new char*[n];
        for(i = 0; i < n; i++) matrix_pequena[i] = new char[n]; 
    
       
        for(i = 0; i < N; i ++){
            cin >> linha;
            for(j = 0; j < N; j++){
                matrix_grande[i][j] = linha[j];
            }
        }

    
        for(i = 0; i < n; i ++){
            cin >> linha;
            for(j = 0; j < n; j++){
                matrix_pequena[i][j] = linha[j];
            }
        }

        int resps[ROT];
        
        for(i = 0; i < ROT; i ++){
            resps[i] = teste(matrix_grande, matrix_pequena, N, n);
            matrix_pequena = rotaciona(matrix_pequena, n);
        }

        cout << resps[0] << " " << resps[1] << " " << resps[2] << " " << resps[3] << endl;
           
    
    }

}
