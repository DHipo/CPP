#include "..\dhi.h"

std::vector<bool> Matriz = {false, false, false,   false, false, false,  false, false, false,  false, false, false ,  false, false,false};
std::vector<bool> Rectangle = {false, true, false,   false, true, false, false, true, false,  false, false, false ,  false, false,false};

std::vector<bool> operator +(std::vector<bool> &a, std::vector<bool> &b){
    std::vector<bool> result;
    for(int i = 0; i < a.size(); i++){
        //OR logico        
        result.push_back(a[i] || b[i]);
    }
    return result;
}

std::vector<bool> operator +(std::vector<bool> &a, int num){
    for(int i = 0; i < a.size(); i++){
        if(a[i] && a[i+3] == false){
            a[i] = true;
            a[i-3] = true;
            a[i+3] = true;
            a[i-6] = false;
        }
    }
    return a;
}

void showMatriz(std::vector<bool> &matriz){
    for(int i=0; i<matriz.size(); i++){
        if(matriz[i]) std::cout<<"1";
        else std::cout<<"0";
        if((i%3) == 2) std::cout<<std::endl;
    }
}
int main(){
    //std::vector<bool> result = Rectangle + Matriz;
    system("@cls||clear");
    showMatriz(Rectangle);
    std::cout<<std::endl;
    Rectangle = Rectangle + 1;
    showMatriz(Rectangle);
    return 0;
}