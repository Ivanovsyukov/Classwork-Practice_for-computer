#include <iostream>
#include <fstream>
#include <istream>

int main(int argc, char* argv[]){
    if (argc<2){
        std::cout << "Misstake" << std::endl;
        return 1;
    }
    std::ifstream ifs;
    ifs.open(argv[1] , std::ios_base::in | std::ios_base::binary);
    if (!ifs.is_open()){
        std::cout << "File " << argv[1] << " can not open." << std::endl;
        return 2;
    }
    char sym;
    int smesh;
    while(!ifs.fail()){
        ifs.read(reinterpret_cast<char*>(&sym), sizeof(sym));
        std::cout << sym << std::endl;
        smesh=static_cast<int>(sym);
        if (smesh%3==0){
            ifs.seekg(smesh, std::ios_base::beg);
        } else if(smesh%3==1){
            ifs.seekg(smesh, std::ios_base::end);
        } else {
            ifs.seekg(smesh, std::ios_base::cur);
        }
    }
    std::cout << "All" << std::endl;
    return 0;
}