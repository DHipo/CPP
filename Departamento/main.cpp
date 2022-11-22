#include "../dhi.h"

class Dep{
    public:
        int Id, price, m2, cBaños, cHabi;

        Dep(int i, int p, int m, int B, int H){
            this->Id = i;
            this->price = p;
            this->m2 = m;
            this->cBaños = B;
            this->cHabi = H;
        };

        Dep(int i, int p){
            this->Id = i;
            this->price = p;
            this->m2 = 0;
            this->cBaños = 0;
            this->cHabi = 0;
        };

        Dep(void){
            this->Id=0;
            this->price=0;
        };

        void InfoDep(void){
            std::cout<<"\n|id: "<<this->Id<<"\t|price: "<<this->price 
                        <<"\t|m2: "<<this->m2<<"\t|cBaños: "<<this->cBaños
                        <<"\t|cHabi: "<<this->cHabi;
        };
};

class Client{
    public:  
        std::string name;
        Dep depa;
        Client(std::string n, Dep de){
            this->name = n;
            this->depa = de;
        };
        
        Client(void){
            this->name = "(null)";
        };

        void ShowDep(void){
            std::cout<<"name: "<<this->name<< "\t| depa(ID): "<<this->depa.Id<<"\t| depa(price): "<<this->depa.price ;
        };
};

Dep dep1 (1, 2000);
Client pablo("pablo", dep1);

int main(){
    pablo.ShowDep();
    return 0;
}