#include "headers\libs.h"

#define vector2Int std::vector<std::vector<int>>

vector2Int tabla(9, std::vector<int>(9)); 

void DisplayT(vector2Int m){
    for(auto a : m){
        for(auto b : a) std::cout<<" "<<b<<" |";
        std::cout<<"----------------"<<std::endl;
    }
}

void Fill(vector2Int &m){
    //tengo que hacer que el primer set sea random
    std::set<int> n {1,2,3,4,5,6,7,8,9};

    //se lo ingreso a la primera fila de la matriz/tabla
    for(auto & v: m){
        for(auto & e : v){
        }
    }


}

int main(){
    return 0;
}