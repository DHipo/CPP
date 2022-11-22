#include "..\dhi.hpp"


std::vector<int> distK, disf;

void actualiza(std::vector<int>&, std::vector<std::vector<int>>&, std::vector<int>, std::vector<int>);

int main(){
    int n, q;
    std::cin>>n>>q;
    std::vector<std::vector<int>> Q(q, std::vector<int>(4));
    
    std::vector<int> N(n);
    //Siempre hablar sobre la direccion de memoria, o sino se genera un copia dentro del ciclo for
    for(int &e : N){
        std::cin>>e;
    }

    for(std::vector<int> &v : Q){
        for(int &i : v){
            std::cin>>i;
        }
    }

    actualiza(N, Q, disf, distK);

    return 0;
}

void actualiza(std::vector<int> &N, std::vector<std::vector<int>> &Q, std::vector<int> dis, std::vector<int>dist){
    for(int i=0; i<Q.size(); i++){
        if (Q[i][0] == 1 && Q[i][3] == 0) {
            N[Q[i][1]] = Q[i][2];
        }
        if (Q[i][0] == 2) {
            dist.push_back(0);
            for(int v : N) 
                if(v != Q[i][3] && v < Q[i][3]) dist[i]++;
            dis.push_back(N[Q[i][2]-1] - N[Q[i][1]-1]);
            std::cout<<dis;std::cout<<"\n";std::cout<<dist;std::cout<<std::endl<<std::endl;
        }
    }
}