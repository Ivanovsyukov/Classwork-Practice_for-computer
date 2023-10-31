#include <iostream>
int main(){
    char c='12';
    std::cout << "You have entered" << std::endl;
    std::cout << "in hex it is";
    if ('0' <= c && c<='9'){
        std::cout << (c-'0') << std::endl;
    } else {
        if ('A' <=c && c<='F'){
            std::cout << (c-'A'+10) << std::endl;
        }
    }
    return 0;
}