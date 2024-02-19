#include <iostream>
#include <fstream>

int main(){
    std::ifstream one;
    one.open("D:\\program\\Git\\Classwork-Practice_for-computer\\lesson_10\\pic_1.bmp", std::ios_base::in | std::ios_base::binary);
    if (!one.is_open()){
        std::cout << "one is not read" << std::endl;
        return 1;
    }
    std::ofstream out;
    out.open("D:\\program\\Git\\Classwork-Practice_for-computer\\lesson_10\\template.bmp", std::ios_base::out | std::ios_base::binary);
    if (!out.is_open()){
        one.close();
        std::cout << "out is not read" << std::endl;
        return 1;
    }
    char s;
    for(int i=0; i<62; ++i){
        one >> s;
        out << s;
    }
    one.close();
    out.close();
    return 0;
}