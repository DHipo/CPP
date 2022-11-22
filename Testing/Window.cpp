#include <windows.h>

void gotoXY(int x, int y){
    /*A Handle can be useful for saving states (among others). If u have data in a structure like an std::vector. 
    Your object may be at different memory locations at different times during execution of a program,
    which means your pointer to that memory will change values. With a handle it never changes, it always references your object.
    Imagine saving a state of a program (like in a game) - you wouldn't save out a pointer location to data and later 
    import the data again and try to get that address in memory. You can however save out a Handle with your data, 
    and import the data and handle.*/
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void OcultarCursor(){
    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.dwSize = 1;
    lpCursor.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &lpCursor);
}

int main(){
    int x = 10 , y = 10;
    bool pressed = false;
    OcultarCursor();
    gotoXY(x, y);
    std::cout<<"*";
    char keyPressed = 0;
    while(keyPressed != 'q'){
        if (pressed) {
            system("@cls");
            gotoXY(x, y);
            std::cout<<"*";
        }
        if(kbhit()){
            keyPressed = getch();
            switch(keyPressed){
                case 'w': y--; break;
                case 's': y++; break;
                case 'a': x--; break;
                case 'd': x++; break;
                case 'q': break;
            }
            pressed = true;
        }else pressed = false;
    }
    return 0;
}