#include <iostream>
#include <fstream>

int main(){
    std::fstream fs;
    fs.open("D:\\program\\Git\\Classwork-Practice_for-computer\\lesson_5\\file.txt", std::ios_base::in);
    if (!fs.is_open()){
        std::cout << "File array.txt can not open." << std::endl;
        return 1;
    }
    int a=0;
    char c;
    size_t counter=0;
    char buffer[8];
    while(true){
        fs.read(buffer, sizeof(buffer));
        std::cout << fs.gcount() << " bites read" << std::endl;
        if (fs.gcount() < sizeof(buffer)){
            for (size_t k=0; k<fs.gcount(); ++k){
                std::cout << buffer[k] << std::endl;
            }
            break;
        }
        for (size_t k=0; k<sizeof(buffer); ++k){
            std::cout << buffer[k] << std::endl;
        }
    }
    fs.close();
    return 0;
}