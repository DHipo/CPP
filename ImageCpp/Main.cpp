#include <iostream>
#include <conio.h>
#include <cstdlib>
using namespace std;


class Matriz{
    public:
        int x,y;
        Matriz(int x, int y){
            this->x = x;
            this->y = y;
        };
};

Matriz Mat(3,3);

bool values[3][3];

int main(){
    system("@cls||clear");
    for(int y=0; y<Mat.y; y++){
        for (int x = 0; x < Mat.x; x++){
            cout<<"|\t-\t|";
        }
        cout<<"\n";
    }
    char aux = getche();
    cout<<aux;
    return 0;
}