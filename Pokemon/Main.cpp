#include "..\dhi.hpp"

//Pokemon Main

class Pokemon{
    public:
        std::string name;
        int hp;
        int damage;
        int TotalHP;
        Pokemon(std::string n, int d, int h){
            this->name = n;
            this->damage = d;
            this->hp= h;
            this->TotalHP = h;
        };
        Pokemon(void){
            this->name = "";
            this->damage = 0;
            this->hp= 0;
            this->TotalHP = 0;
        };
};

class Player{
    public:
        std::string name;
        Pokemon pokemon;
        Vector2 pos;
        char CharacterP;
        Vector2 antpos;
        Player(std::string name, char c, Pokemon p, Vector2 po){
            this->name = name;
            this->pokemon = p;
            this->pos = po;
            this->CharacterP = c;
        };
        Player(void){
            this->name = "";
            this->pokemon = Pokemon();
        };

        void Draw(void){
            dhi::GotoXY(this->pos.x, this->pos.y);
            std::cout<<this->CharacterP;
        };

        void Update(){
            this->Draw();
        };
};

void menuFight(Player &player){
    CONSOLE_SIZE conSize;
    dhi::GetConsoleSize(conSize);
    dhi::GotoXY(10,10);
    std::cout<<player.name<<" has "<<player.pokemon.name<<std::endl;
}

Player player("Player", 'x',Pokemon("Pikachu", 10, 10), Vector2{10,10});

int main(int argc, char* argv[]){
    
    dhi::ClearConsole();
    player.Update();
    dhi::GetConsoleSize(conSize);
    std::cout<<conSize<<std::endl;

    while(1){
        if(GetAsyncKeyState(VK_ESCAPE)) break;

        if(kbhit()){
            char keypressed = getch();
            switch (keypressed){
                case 'w': player.pos.y--; break;
                case 's': player.pos.y++; break;
                case 'a': player.pos.x--; break;
                case 'd': player.pos.x++; break;
                default: break;
            }
        }

        dhi::ClearConsole();
        player.Update();
    }

    return 0;
}