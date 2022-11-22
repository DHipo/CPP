#include "..\dhi.h"

void Setup(std::fstream &);

int main(int argc, char * argv[]){
   
    std::fstream file;
    file.open("main.cpp", std::ios::out);
    file.seekg(0, std::ios::beg);
    //Setup(file);
    while(1){
        if(GetAsyncKeyState(VK_ESCAPE)) break;

        std::string inLine;
        getline(std::cin, inLine);
        
        dhi::SeekF(file, 4);
        file<<inLine;
        file.close();

        system("g++ main.cpp -o Main.exe");
        system(".\\Main.exe");
    }
    return 0;
}

void Setup(std::fstream &_file){
    _file<<"#include <iostream>\n\n"
        <<"int main(int argc, char * argv[]){\n\t\n\treturn 0;\n}";
}