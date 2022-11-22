#include <dhi>

Vector2 axis={10,10};
int main(){
    dhi::GetConsoleSize(conSize);
    while(1){
        
        if(kbhit()){
            switch(getch()){
                case 'A': axis.y--;break;
                case 'B': axis.y++;break;
                default:break;
            }
            system("@cls||clear");
        }
        dhi::GotoXY(axis.x,axis.y);
        std::cout<<"X";
    }
    return 0;
}