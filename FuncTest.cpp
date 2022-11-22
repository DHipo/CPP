#include "dhi.hpp"

struct Nodo{
    char caract;
    bool state;
    Vector2 pos;
    std::vector<Vector2> NP;
};

void CheckA(std::vector<std::vector<Nodo>>);
void MakePath(std::vector<std::vector<Nodo>>&);
std::vector<Vector2> GetN(std::vector<std::vector<Nodo>> &, Vector2&);
int nodo=5, aris;

std::string map[] ={"#####",
                    "#..A#",
                    "#.#.#",
                    "#.B.#",
                    "#####"};

int main(void){

    std::vector<std::vector<Nodo>> Arr(nodo, std::vector<Nodo>(nodo, {'o'}));
/*
    std::cout<<"Ingrese nodos y aristas:\n-->";
    std::cin>>nodo>>aris;

    for(int i = 0; i<aris; i++){
        int x,y;
        std::cout<<"Ingrese las aristas:\n--->";
        std::cin>>x>>y;
    }
*/
    for(int i = 0; i<nodo; i++){
        int x=0;
        for(char c : map[i]){
            Arr[i][x].pos = {x, i};
            Arr[i][x].caract = c;
            if(Arr[i][x].caract == '.' || Arr[i][x].caract == 'B' || Arr[i][x].caract == 'A') Arr[i][x].state = true;
            x++;
        }
    }

    std::cout<<"------------------------------------------------"<<std::endl;

    std::cout<<"\t\t\tAristas"<<std::endl;

    for(int x=0; x<nodo; x++){
        std::cout<<"\tNodos"<<x<<":\t";
        for(int y=0; y<nodo; y++){
            std::cout<<"\t"<<Arr[x][y].caract<<" state:"<<Arr[x][y].state;
        }
        std::cout<<"\n";
    }


    //CheckA(Arr);

    MakePath(Arr);

    return 0;
}

void CheckA(std::vector<std::vector<Nodo>> arr){
    std::cout<<"------------------------------------------------"<<std::endl;
    std::cout<<"\t\t\tNode Connection"<<std::endl;
    for(int x=0; x<nodo; x++){
        std::cout<<"\tNodo "<<x<<".";
        for(int y=0; y<nodo; y++){
            if(arr[x][y].caract == '.') std::cout<<"\t"<<y;
        }
        std::cout<<"\n";
    }
}

void MakePath(std::vector<std::vector<Nodo>> &arr){
    
    Vector2 A = {0,0}, B = {0,0}, D = {0,0}; 

    //Getting the positions
    for(std::vector<Nodo> ar : arr){
        for(Nodo n : ar){
            if(n.caract == 'A') A = {n.pos.x, n.pos.y};
            if(n.caract == 'B') B = {n.pos.x, n.pos.y};
        }
    }
    
    //Getting the neightbours
    D = B - A;
    std::cout<<"A: "<<A<<" B: "<<B<<" D: "<<D<<std::endl;
    int ctn=0;
    while(ctn != 3){
        std::vector<Vector2> np = GetN(arr, A);
        for(Vector2 n : np){
            //Si va a la izquierda
            if(n.x < A.x && A.x != B.x && D.x<0) {
                //std::cout<<n<<std::endl;
                //std::cout<<"Can move left"<<std::endl;
                if((B.x - (A.x - 1) ) > D.x){
                    if(!arr[A.y][n.x].state){
                        if(B.y > A.y && arr[(A.y+1)][A.x].state) {std::cout<<"D"<<std::endl;A.y = n.y;}
                        if(B.y < A.y && arr[(A.y-1)][A.x].state) {std::cout<<"U"<<std::endl;A.y = n.y;}
                    }
                    std::cout<<"L"<<std::endl;
                    A.x = n.x;
                }
            }
            
            //Si va a la derecha
            if(n.x > A.x && A.x != B.x && D.x>0) {
                //std::cout<<n<<std::endl;
                //std::cout<<"Can move right"<<std::endl;
                if((B.x - (A.x + 1)) < D.x){
                    if(!arr[A.y][n.x].state){
                        if(B.y > A.y && arr[(A.y+1)][A.x].state) {std::cout<<"D"<<std::endl; A.y = n.y;}
                        if(B.y < A.y && arr[(A.y-1)][A.x].state) {std::cout<<"U"<<std::endl; A.y = n.y;}
                    }
                    std::cout<<"R"<<std::endl;
                    //std::cout<<n;
                    A.x = n.x;
                }
            }
            
            //Si va arriba en el index
            if(n.y > A.y && A.y != B.y && D.y>0){
                //std::cout<<n<<std::endl;
                //std::cout<<"Can move down"<<std::endl;
                if((B.y - (A.y + 1) ) < D.y){
                    if(!arr[n.y][A.x].state){
                        //significa que se va a chocar
                        std::cout<<"Se choca"<<"N: "<<n;
                        //B esta a la izquierda
                        if((B.x < A.x || B.x == A.x)&& arr[A.y][(A.x-1)].state) {std::cout<<"L"<<std::endl; A.x = n.x;}
                        //B esta a la derecha
                        if(B.x > A.x && arr[A.y][(A.x+1)].state) {std::cout<<"R"<<std::endl; A.x = n.x;}
                        /*if(n.x < A.x && arr[A.y][(A.x-1)].state /*&& -(B.x - (A.x-1)) <= D.x) {std::cout<<"L"<<std::endl; A.x = n.x;}
                        if(n.x > A.x && arr[A.y][(A.x+1)].state /*&& -(B.x - (A.x+1)) <= D.x) {std::cout<<"R"<<std::endl; A.x = n.x;}*/
                    }
                    std::cout<<"D"<<std::endl;
                    A.y = n.y;
                    //std::cout<<"A: "<<A<<" B: "<<B<<" D: "<<D<<std::endl;
                }
            }
            
            //Si va abajo en el index
            if(n.y < A.y && A.y != B.y&& D.y<0){
                //std::cout<<n<<std::endl;
                //std::cout<<"Can move up"<<std::endl;
                if((B.y - (A.y - 1) ) > D.y){
                    if(!arr[n.y][A.x].state){
                        if(B.x < A.x && arr[A.y][(A.x-1)].state) {std::cout<<"L"<<std::endl; A.x = n.x;}
                        if(B.x > A.x && arr[A.y][(A.x+1)].state) {std::cout<<"R"<<std::endl; A.x = n.x;}
                    }
                    std::cout<<"U"<<std::endl;
                    A.y = n.y;
                    //std::cout<<"A: "<<A<<" B: "<<B<<" D: "<<D<<std::endl;
                }
            }
        }
        ctn++;np = GetN(arr, A);D = B-A;
    }
    
    std::cout<<"\n";

    

    std::cout<<"A: "<<A<<" B: "<<B<<" D: "<<D<<std::endl;

    if((B.x - A.x) == 0 && (B.y - A.y) == 0) std::cout<<"LLegaste";
}

std::vector<Vector2> GetN(std::vector<std::vector<Nodo>> &arr, Vector2&A){
    std::vector<Vector2> np;
    for(int i=0; i<arr.size(); i++){
        for(int x=0; x<arr[0].size(); x++){
            if( (arr[i][x].pos.x == (A.x-1) || arr[i][x].pos.x == (A.x+1) || arr[i][x].pos.x == A.x) && 
                (arr[i][x].pos.y == (A.y-1) || arr[i][x].pos.y == (A.y+1) || arr[i][x].pos.y == A.y) && 
                arr[i][x].state) np.push_back(Vector2{arr[i][x].pos});
        }
    }
    //for(Vector2 n: np) std::cout<<n;
    return np;
}