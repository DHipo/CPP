//#include "C:\Users\BautiPC\OneDrive - Escuela Tecnica Roberto Rocca\Programacion\LE\C++\dhi.cpp"
#include "..\dhi.hpp"

Vector2 aceleration = {1,1};

void HideCursor(){
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 1;
    cci.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}

void ConMarco(struct CONSOLE_SIZE &size, int x, int y){
    for(int i=0; i<30; i++){
        for(int j=0; j<size.width; j++){
            if(i==0 || i==29 || j==0 || j==size.width-1){
                dhi::GotoXY(j,i);
                std::cout<<"*";
            }
        }
    }
    dhi::GotoXY(x,y);
}

class Snake{
    public: 
        int x=10, y=10;
        int points;
        std::string direction;
        char Character;
        std::vector<Vector2> CTail;
        Snake(){};
}Snake;

int main(int argc, char * argv[]){
    dhi::GetConsoleSize(conSize);
    Snake.Character = 'x';
    std::cout<<"Console size: "<<conSize.width<<"x"<<conSize.height<<std::endl;
    HideCursor(); ConMarco(conSize, Snake.x, Snake.y);
    while(1){
        if(GetAsyncKeyState(VK_ESCAPE)) break;
        dhi::GotoXY(Snake.x, Snake.y);
        if(kbhit()){
            char keyPressed = getch();
            switch (keyPressed){
                case 'w': 
                    //if((Snake.y-1) < 0) break; else Snake.y--; break;
                    Snake.direction = "-y"; break;
                case 's': 
                    //if((Snake.y+1) > conSize.height) break; else Snake.y++; break;
                    Snake.direction = "y+";break;
                case 'a': 
                    //if((Snake.x-1) < 0) break; else Snake.x--; break;
                    Snake.direction = "-x";break;
                case 'd': 
                    //if((Snake.x+2) > conSize.width) break; else Snake.x++; break;
                    Snake.direction = "x+"; break;
                default: break;
            }
        }
        if(Snake.direction == "-x") {
            if ((Snake.x - aceleration.x) < 2) aceleration.x = 0; else Snake.x-= aceleration.x;
        }
        if(Snake.direction == "x+") {
            if ((Snake.x + aceleration.x) > (conSize.width - 2)) aceleration.x = 0; else Snake.x+= aceleration.x;
        }
        if(Snake.direction == "y+") {
            if ((Snake.y + aceleration.y) > (conSize.height - 2000)) aceleration.y = 0; else Snake.y+= aceleration.y;
        }
        if(Snake.direction == "-y") {
            if ((Snake.y - aceleration.y) < 1) aceleration.y = 0; else Snake.y-= aceleration.y;
        }

        Snake.CTail.push_back(Vector2{Snake.x, Snake.y});
        
        for(int i = 0; i < Snake.CTail.size(); i++){
            dhi::GotoXY(Snake.x, Snake.y, true);
            ConMarco(conSize, Snake.x, Snake.y);
            std::cout<<Snake.Character;
            Sleep(50);
        }
    }
    dhi::ClearConsole();
    std::cout<<"Gracias por usar este programa."<<std::endl;
    return 0;
}