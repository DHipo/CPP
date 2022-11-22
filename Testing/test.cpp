#include <iostream>
#include <vector>
using namespace std;

class Persona{
    private:         
        string _nombre;
        int _num;
    public:
        Persona * next;
        Persona(string &nombre, int &num){
            _nombre = nombre;
            _num = num;
        };
        void Show(void){
            cout<<"\nNombre ingresado: "<<_nombre<<"\nNum ingresado: "<<_num<<endl;
        };
};

class l{
    public:
        bool hasGirlfriend = false; 
}Lucho;

class w{
    public:
        void end(){};
}World;

int main(){
    if (Lucho.hasGirlfriend == true){
        World.end();
    }
    vector<Persona> ArrPersona;
    int c;
    cout<<"Cuantas personas quiere ingresar: "<<endl;
    cin>>c;

    for (int i = 0; i < c; i++){
        string nombre;
        int num;
        cout<<"Ingrese nombre y num: \n";
        cin>>nombre>>num;
        ArrPersona.push_back(Persona(nombre, num));
    }
    cout<<"Mostrando las personas ingresadas: "<<endl;
    return 0;
}