#include <iostream>
#include <fstream>
#include <chrono>

int main(){
    std::ifstream ifs;
    ifs.open("D:\\program\\Git\\Classwork-Practice_for-computer\\lesson_6\\file.bin", std::ios_base::in);
    if (!ifs.is_open()){
        std::cout << "File " << "D:\\program\\Git\\Classwork-Practice_for-computer\\lesson_6\\file.bin" << " can not open." << std::endl;
        return 2;
    }
    char sym;
    ifs.seekg(-1);
    if (ifs.fail()){
        std::cout << "NO " << sym << std::endl;
        return 1; 
    }
    ifs>>sym;
    std::cout << sym << "|" << static_cast<int>(sym) << std::endl;
    return 0;
}