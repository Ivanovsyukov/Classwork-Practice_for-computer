#include <iostream>
#include <fstream>

int main(int argc, char* argv[]){
    if (argc!=2){
        std::cout << "Не то число элементов" << std::endl;
        return 1;
    }
    std::fstream fs;
    fs.open(argv[1]);
    char buffer[64];
    fs.read(buffer, sizeof(buffer));
    int on=16;
    int tw=32;
    char s;
    for(int i=0; i<16; ++i){
        char s=buffer[i+on];
        buffer[i+on]=buffer[i+on+tw];
        buffer[i+on+tw]=s;
    }
    fs.seekp(0, std::ios_base::beg);
    fs.write(buffer, sizeof(buffer));
    fs.close();
    return 0;
}