#include <stdio.h>

int main(){
    FILE * PF = fopen("input.txt", "a+");

    if(ftell(PF)) printf("a");

    return 0;
}