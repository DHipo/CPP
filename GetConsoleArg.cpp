#include "dhi.h"

std::string Command(char *);

int main(int argc, char * argv[]){
    std::string args[argc];
    for(int i =0; i<argc; i++){
        args[i] = Command(argv[i]);
        std::cout<<"value ["<<i<<"]: "<< args[i]<<std::endl;
    }
    if(args[1] == "-version") std::cout<<"Version 1"<<std::endl;
    std::cout<<"end."<<std::endl;
    return 0;
}

std::string Command(char * str){
    std::string a(str);
    return a;
}