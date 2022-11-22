#include "dhi.hpp"

string Palogol(int, int);

string respuesta[] = {"Gol\n", "Palo\n", "Fuera\n"};
Vector2 cancha = {232, 732};

int main(int argc, char * argv[]){
    int n, x, y;

    std::cin>>n;

    for(int i = 0; i<n; i++){
        std::cin>>x>>y;
        std::cout<<Palogol(x,y);
    }
    return 0;
}

string Palogol(int x, int y){
    if(x > 0 && x < cancha.x && y>0 && y<cancha.y) return respuesta[0];
    if(x<0 || x>cancha.x || y>cancha.y) return respuesta[2];
    if(x==232 && y == 732) return respuesta[1];
}