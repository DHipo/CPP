#include <bits/stdc++.h>

int main(){
    unsigned long int n;

    std::cin>>n;
    std::cout<<n<<" ";
    while(n != 1){
        if(n%2) n = n * 3 + 1;
        else n /= 2;
        std::cout<<n<<" ";
    }
}
