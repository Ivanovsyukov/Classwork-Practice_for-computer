#include <iostream>
#include <fstream>

int main(){
    std::ifstream one;
    one.open("pic_1.bmp", std::ios_base::binary);
    if (!one.is_open()){
        std::cout << "one is not read" << std::endl;
        return 1;
    }
    std::ifstream two;
    two.open("pic_2.bmp", std::ios_base::binary);
    if (!two.is_open()){
        one.close();
        std::cout << "two is not read" << std::endl;
        return 1;
    }
    one.close();
    two.close();
    return 0;
}