#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>
#include <conio.h>
#include <windows.h>

struct CONSOLE_SIZE{
    int width;
    int height;
}conSize;

struct Vector2{
    int x;
    int y;
};

struct Vector3{
    int x;
    int y;
    int z;
}; 

struct FileIndex{
    int line;
    int index;
};

std::ostream& operator<<(std::ostream& cout, FileIndex& a){
    return cout<<"FileIndex: {line:"<<a.line<<", index:"<<a.index<<"}";
};

std::ostream& operator<<(std::ostream& cout, Vector2& a){
    return cout<<"Vector2: {x:"<<a.x<<", y:"<<a.y<<"}";
};

std::ostream& operator<<(std::ostream& cout, Vector3& a){
    return cout<<"Vector3: {x:"<<a.x<<", y:"<<a.y<<", z:"<<a.z<<"}";
};

namespace dhi{
    
    void ArrayPrint(const std::vector<int> &arr){
        for(const int &value : arr) std::cout<<value<<std::endl;
    }

    void ArrayPrint(const std::vector<int> &arr, std::string prompt){
        std::cout<<prompt;
        for(const int &value : arr) std::cout<<value<<std::endl;
    }
    
    void ArrayPrint(const std::vector<std::string> &arr){
        for(const std::string &value : arr) std::cout<<value<<std::endl;
    }
    
    void ArrayPrint(const std::vector<std::string> &arr, std::string prompt){
        std::cout<<prompt;
        for(const std::string &value : arr) std::cout<<value<<std::endl;
    }

    void ArrayPrint(const std::vector<float> &arr){
        for(const float &value : arr) std::cout<<value<<std::endl;
    }

    void ArrayPrint(const std::vector<float> &arr, std::string prompt){
        std::cout<<prompt;
        for(const float &value : arr) std::cout<<value<<std::endl;
    }

    void ArrayPrint(const std::vector<char> &arr){
        for(const char &value : arr) std::cout<<value<<std::endl;
    }

    void ArrayPrint(const std::vector<char> &arr, std::string prompt){
        std::cout<<prompt;
        for(const char &value : arr) std::cout<<value<<std::endl;
    }

    void Foreach(const std::vector<int> &arr, void(*func)(int)){
        for(const int &value : arr) func(value);
    }

    void Foreach(const std::vector<std::string> &arr, void(*func)(std::string)){
        for(const std::string &value : arr) func(value);
    }

    void Foreach(const std::vector<float> &arr, void(*func)(float)){
        for(const float &value : arr) func(value);
    }

    void Foreach(const std::vector<char> &arr, void(*func)(char)){
        for(const char &value : arr) func(value);
    }

    void GetLineF(const std::string &file,std::string &line){
        std::ifstream Pf(file);
        if(!Pf.is_open()){
            std::cout<<"No se pudo abrir el archivo \""<<file<<"\""<<std::endl;
            return;
        }
        //getline(Pf,line);
    }
    
    void GetLineF(const std::string &file,std::string &line, const char &delimiter){
        std::ifstream Pf(file);
        if(!Pf.is_open()){
            std::cout<<"No se pudo abrir el archivo \""<<file<<"\""<<std::endl;
            return;
        }
        getline(Pf,line, delimiter);
        Pf.close();
    }

    void GetLineF(const std::string &file,std::string &line, const char &delimiterI, const char &delimiterF){
        std::ifstream Pf(file);
        if(!Pf.is_open()){
            std::cout<<"No se pudo abrir el archivo \""<<file<<"\""<<std::endl;
            return;
        }
        Pf.seekg(0, std::ios::beg);
        std::string auxI;
        auxI.erase();
        getline(Pf,auxI, delimiterI);
        getline(Pf,line, delimiterF);
        Pf.close();
    }

    void GetLine(std::string &line, const std::string &prompt){
        std::cout<<prompt;
        std::getline(std::cin,line);
        if(line.empty()) std::cout<<"No se ingreso nada."<<std::endl;
    }
    
    void GetLine(std::string &line){
        std::getline(std::cin,line);
        if(line.empty()) std::cout<<"No se ingreso nada."<<std::endl;
    }

    void FilePrint(const std::string &file_name, const std::string &text){
        std::ofstream file(file_name);
        if(file.is_open()){
            file<<text;
            file.close();
        }
        else std::cout<<"No se pudo abrir el archivo."<<std::endl;
    }

    void FilePrint(const std::string &file_name, std::istream &stream){
        std::ofstream file(file_name);
        if(file.is_open()){
            std::string text;
            stream>>text;
            file<<text;
            file.close();
        }
        else std::cout<<"No se pudo abrir el archivo."<<std::endl;
    }
    
    void FilePrint(const std::string &file_name, std::istream &stream, const std::string prompt){
        std::ofstream file(file_name);
        if(file.is_open()){
            std::cout<<prompt;
            std::string text;
            stream>>text;
            file<<text;
            file.close();
        }
        else std::cout<<"No se pudo abrir el archivo."<<std::endl;
    }

    void GotoXY(int x, int y){
        COORD coord; coord.X = x; coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    }

    void GotoXY(int x, int y, bool clear){
        if(clear) system("@cls");
        COORD coord; coord.X = x; coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    }

    void Cursor(int size, const std::string &text){
        CONSOLE_CURSOR_INFO info; info.dwSize = size; if(text == "true") info.bVisible = TRUE; else if(text == "false")info.bVisible = FALSE;
        SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
    }

    void WaitForEnd(){
        std::cout<<"Presione enter para continuar..."<<std::endl;
        std::cin.get();
    }

    void GetConsoleSize(CONSOLE_SIZE &size){
        int columns=0, rows = 0;
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
        size.height = csbi.dwSize.Y;
        size.width = csbi.dwSize.X;
    }

    void ClearConsole(){
        system("@cls|clear");
    }


    //Return the index of a giveen word and display it
    std::size_t FindS(const std::string &_checkString, const std::string &ToFind){
        return _checkString.find(ToFind);
    }

    //Return the index of a giveen word and display it
    std::size_t FindS(const std::string &_checkString, const std::string &ToFind, const bool &ShowIndex){
        std::size_t index = _checkString.find(ToFind);
        if(ShowIndex) std::cout<<index<<" + (length of the word) "<<ToFind.length();
        return index;
    }

    //Move the pointer of the file to a specific line and show the index
    void SeekF(std::fstream &file,const int &_offsetLines, const bool &ShowIndex = false){
        std::string line;
        int size = 0;
        file.seekg(0, std::ios::beg);
        for(int i = 1; i < _offsetLines; i++){
            getline(file,line);
            size += line.length() + 2;
            file.seekg(size, std::ios::beg);
        }
        if(ShowIndex){
            std::istream::pos_type p = file.tellg();
            std::cout<<"\n"<<p;
        }
    }

    //return the line where it's found
    std::size_t FindF(std::fstream &_file, const std::string &_WordToFind){
        std::string line; int index = 0;
        _file.seekg(0, std::ios::beg);
        while(getline(_file, line)) {
            if (line.find(_WordToFind) != std::string::npos) return (index+1);
            index++;
        }
    }
    
    //return the line where it's found
    std::size_t FindF(std::fstream &_file, const std::string &_WordToFind, const bool &_ShowIndex){
        std::string line; int index = 0;
        _file.seekg(0, std::ios::beg);
        while(getline(_file, line)) {
            if (line.find(_WordToFind) != std::string::npos) {
                if(_ShowIndex){
                    std::size_t indexS = line.find(_WordToFind);
                    std::cout<<"IndexInLine: "<<indexS;
                }
                return (index+1);
            }
            index++;
        }
        if(_ShowIndex) std::cout<<"The word is not in the file"<<std::endl;
        return -1;
    }

    //return a vector with the line and index where it's found 
    FileIndex FindFV(std::fstream &_file, const std::string &_WordToFind, const bool &_ShowIndex = false){
        std::string line; int index = 0 , indexS = 0;
        _file.seekg(0, std::ios::beg);
        while(getline(_file, line)) {
            if (line.find(_WordToFind) != std::string::npos) {
                if(_ShowIndex) std::cout<<"IndexS: "<<indexS;
                indexS = line.find(_WordToFind);
                return {(index+1), indexS};
            }
            index++;
        }
        if(_ShowIndex) std::cout<<"The word is not in the file."<<std::endl;
        return {-1,-1};
    }
}