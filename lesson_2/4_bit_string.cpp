#include <iostream>

int main(){
    unsigned short int r;
    std::cout << "Input your unsigned short integer number: ";
    std::cin >> r;
    unsigned short int top_r;
    for (int i=0; i<=12; i=i+4){
        top_r=r<<(i);
        top_r=top_r>>(12);
        std::cout << top_r << std::endl;
    }
    return 0;
}