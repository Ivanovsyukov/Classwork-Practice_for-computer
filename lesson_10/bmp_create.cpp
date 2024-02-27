#include <iostream>
#include <fstream>
#include "Bitmap.h"

int main(int argc, char* argv){
    if (argc!=2){
        std::cout << "you work is bad" << std::endl;
        return 2;
    }
    unsigned int w, h;
    std::cout << "write weight and height: ";
    std::cin >> w >> h;
    
    return 0;
}