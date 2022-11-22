#include <iostream>
#include <vector>

using namespace std;

void helloworld(){
    cout<<"Hello World!"<<endl;
}

void foreach(const vector<int> & arr, void(*func)(int)){
    for(int value : arr)
        func(value);
}

vector<int> MyArr = {1,102,232,23,454};

int main(){
    void(*function)() = helloworld;
    function();

    foreach(MyArr, [](int value){
        cout<<"Value: "<<value<<endl;
    });

    return 0;
}
