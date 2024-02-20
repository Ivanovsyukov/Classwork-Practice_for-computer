#include <iostream>
#include <fstream>
#include "bmp_function.h"

int main(int argc, char* argv[]){
    if (argc!=2){
        std::cout << "you work is bad" << std::endl;
        return 2;
    }
    int w, h;
    std::cout << "write weight and height: ";
    std::cin >> w >> h;
    unsigned char *bmp_ptr=create_bmp(w, h);
    if (bmp_ptr==nullptr){
        return 1;
    }
    //write_bmp(argv[1], bmp_ptr);
    std::cout << int(bmp_ptr[2])<< std::endl;
    write_bmp(argv[1], bmp_ptr);
    delete[] bmp_ptr;
    return 0;
}