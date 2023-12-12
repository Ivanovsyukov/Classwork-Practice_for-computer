#include <iostream>
#include <fstream>

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
    char buffer1[16];
    char buffer2[16];
    fs.seekg(16, std::ios_base::cur);
    fs.read(buffer1, sizeof(buffer1));
    fs.seekg(16, std::ios_base::cur);
    fs.read(buffer2, sizeof(buffer2));
    fs.seekp(16, std::ios_base::beg);
    fs.write(buffer2, sizeof(buffer1));
    fs.seekp(16, std::ios_base::cur);
    fs.write(buffer1, sizeof(buffer2));
    fs.close();
    return 0;
}