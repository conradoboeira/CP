#include <iostream>

int main(){
    int n, soma;
    soma = 0;
    while(std::cin >> n){
        soma += n;
    }
    std::cout << soma << std::endl;
}
