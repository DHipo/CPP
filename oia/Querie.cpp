#include <iostream>
#include <vector>

int main(){
    int cn, cq;
    std::cin>>cn>>cq;

    std::vector<long int> n(cn);
    std::vector<long int> results;

    for(long int &v : n) std::cin>>v;

    for(int i=0; i<cq; i++){
        long int r=0, a,b;
        std::cin>>a>>b;
        for(long int x = a-1; x<b; x++) r += n[x];
        results.push_back(r);
    }

    for(long int &v : results) std::cout<<v<<std::endl;

    return 0;
}
