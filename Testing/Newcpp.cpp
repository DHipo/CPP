#include "C:\Users\BautiPC\OneDrive - Escuela Tecnica Roberto Rocca\Programacion\LE\C++\dhi.cpp"

std::vector<std::string> MyArr = {"hola", "mundo"};
std::vector<int> MyArr2 = {1, 2, 3, 4, 5};

int main(){
    dhi::Foreach(MyArr2, [](int value){
        std::cout<<value<<std::endl;
    });

    dhi::FilePrint("Prueba.txt", std::cin, "Ingrese una palabra");
    return 0;
}