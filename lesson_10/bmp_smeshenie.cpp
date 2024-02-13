#include <iostream>
#include <fstream>

int main(){
    std::ifstream one;
    one.open("D:\\program\\Git\\Classwork-Practice_for-computer\\lesson_10\\pic_1.bmp", std::ios_base::in | std::ios_base::binary);
    if (!one.is_open()){
        std::cout << "one is not read" << std::endl;
        return 1;
    }
    std::ifstream two;
    two.open("D:\\program\\Git\\Classwork-Practice_for-computer\\lesson_10\\pic_2.bmp", std::ios_base::in | std::ios_base::binary);
    if (!two.is_open()){
        one.close();
        std::cout << "two is not read" << std::endl;
        return 1;
    }
    one.seekg(10);
    two.seekg(10);
    int on=0, tw=0;
    char buffer[4];
    one.read(reinterpret_cast<char*>(&on), 4);
    two.read(reinterpret_cast<char*>(&tw), 4);
    std::cout << "one: " << on <<std::endl;
    std::cout << "two: " << tw <<std::endl;
    one.close();
    two.close();
    return 0;
}