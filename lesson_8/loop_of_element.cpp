#include <iostream>
#include <fstream>

struct Block{
    char data[15];
    unsigned char link;
};

int main(int argc, char* argv[]){
    if (argc!=2){
        std::cout << "Не то число элементов" << std::endl;
        return 1;
    }
    std::fstream fs;
    fs.open(argv[1]);
    if (!fs.is_open()){
        std::cout << "Не то число элементов12" << std::endl;
        return 2;
    }
    Block block;
    fs.read(reinterpret_cast<char*> (&block), sizeof(block));
    std::cout << "sizeof(block): " << sizeof(block) << std::endl;
    std::cout << block.link << std::endl;
    for(int i=0; i<15; ++i){
        std::cout << block.data[i] << " ";
    }
    std::cout << std::endl;
    fs.close();
    return 0;
}