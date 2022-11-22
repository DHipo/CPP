#include <bits/stdc++.h>

int main(){
    int cn;

    std::cin>>cn;

    std::set<long int> n;

    for(int i=1; i<cn; ++i){
        int e;
        std::cin>>e;
        n.insert(e);
    }

    for(int i=1; i<=cn; i++)
        if(n.find(i) == n.end()) std::cout<<i;
}
