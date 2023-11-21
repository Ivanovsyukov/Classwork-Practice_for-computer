#include <iostream>
#include <fstream>

int main(int argc, char* argv[]){
    if (argc<2){
        std::cout << "You have less argument" << std::endl;
        return 1;
    }
    std::fstream fs;
    fs.open("D:\\program\\Git\\Classwork-Practice_for-computer\\lesson_5\\file_generate.txt", std::ios_base::out | std::ios_base::binary);
    if (!fs.is_open()){
        std::cout << "File array.txt can not open." << std::endl;
        return 1;
    }
    srand(0);
    size_t filesize=atoi(argv[1]);
    for (size_t k=0; k<filesize; ++k){
        fs<<static_cast<char>(rand());
    }
    /*
    int mass;
    int randy;
    std::cout << "Input count bites of generate file: ";
    std::cin >> mass;
    while (mass!=0){
        randy=rand();
        if ((sizeof(randy)*2)<=mass){
            std::cout << sizeof(randy) << " " << mass << " " << randy << std::endl;
            mass-=2*sizeof(randy);
            std::cout << sizeof(randy) << " " << mass << std::endl;
            fs << randy;
        }
    }
    */
    fs.close();
    return 0;
}