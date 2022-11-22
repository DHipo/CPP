#include <iostream>
#include <vector>

const int g = 10;

class Map{
    private:
        std::vector<std::vector<int>> * map;
        int height;
        int width;
        char character;
    public:
        
        Map(int w, int h){
            this->height = h;
            this->width = w;
            this->character = 'x';
            
            this->map = new std::vector<std::vector<int>>(this->height, std::vector<int>(this->width));
            
            std::cout<<"Created Map at: "<<this->map;
        };
        
        Map(int w, int h, char c){
            this->height = h;
            this->width = w;
            this->character = c;
            
            this->map = new std::vector<std::vector<int>>(this->height, std::vector<int>(this->width));
            
            std::cout<<"Created Map at: "<<this->map;
        };
        
        
        Map(){
            this->height = 9;
            this->width = 9;
            this->character = 'x';
            this->map = new std::vector<std::vector<int>>(this->height, std::vector<int>(this->width));
            
            std::cout<<"Created Map at: "<<this->map;
        };
        
        ~Map(){
            delete this->map;
            std::cout<<"Deleted Map";
        }
        
        void Delete (){
            delete this->map;
            std::cout<<"Deleted!";
        }
        
        void Display(){
            std::cout<<std::endl;
            for(auto v : (*map)){
                for(auto c : v){
                    if(c >= 1)std::cout<<this->character;
                        else std::cout<<' ';
                }
            std::cout<<std::endl;
            }    
        }
        
        void setValues(std::vector<std::vector<int>> a){
            for(int f = 0; f<this->height; f++){
                for(int c = 0; c<this->width; c++){
                    (*map)[f][c] = a[f][c];
                }
            }
        }
};

class Entity{
    protected:
        static int EntityC;
        int mass;
    public:
        Entity(int m){
            EntityC++;
            this->mass = m;
        }
        
        ~Entity(){
            EntityC--;
            std::cout<<"drestroyed!"<<std::endl;
        }
};

int Entity::EntityC = 0;

class Sand : public Entity{
    private:
        int volume;
        std::string name;
    public:
        Sand(std::string n, int m) : Entity(m){
            this->name = n;
        }
        
        void ShowMass(){
            std::cout<<"The mass of "<<this->name<<this->EntityC<<" is: "<<this->mass<<std::endl;
        }
        
        void Update(){
            std::cout<<this->name<<this->EntityC<<std::endl;
        }
};

int main(){
    Map * mapa = new Map(3,5);
    std::vector<Sand> * sand = new std::vector<Sand>{Sand("Sand", 11), Sand("Sand", 12), Sand("Sand", 13)};
    
    mapa->setValues(
        std::vector<std::vector<int>>{
            {1,0,0},{1,0,0},{1,1,0},{1,1,0},{1,2,3}
            /*,{0,1,0},{0,0,1},{1,0,0},{1,0,0},{0,1,0},{0,1,0}*/
        });
    mapa->Display();
    
    for(auto v : * sand) v.Update();
    return 0;
}