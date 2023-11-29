#include <iostream>
#include <fstream>
#include <istream>

int main(int argc, char* argv[]){
    if (argc<3){
        std::cout << "Misstake" << std::endl;
        return 1;
    }
    std::ifstream ifs;
    ifs.open(argv[1] , std::ios_base::in | std::ios_base::binary);
    if (!ifs.is_open()){
        std::cout << "File " << argv[1] << " can not open." << std::endl;
        return 2;
    }
    std::fstream ofs;
    ofs.open(argv[2], std::ios_base::out | std::ios_base::binary);
    if (!ofs.is_open()){
        ofs.close();
        ifs.close();
        std::cout << "File " << argv[2] << " can not open." << std::endl;
        return 3;
    }
    char sym;
    int smesh=0;
    int gorisontal=64;
    int vertical=32;
    int i=0;
    int k=1;
    int all=0;
    bool p=true;
    while(!ifs.fail()){
        all+=1;
        ifs.read(reinterpret_cast<char*>(&sym), sizeof(sym));
        if (all>18 && all<=26){
            ofs.seekg(4, std::ios_base::cur);
            for (int i=0; i<4; ++i){
                ifs.read(reinterpret_cast<char*>(&sym), sizeof(sym));
                ofs.write(reinterpret_cast<char*>(&sym), sizeof(sym));
            }
            all+=4;
            ofs.seekg(-8, std::ios_base::cur);
            for (int i=0; i<4; ++i){
                ifs.read(reinterpret_cast<char*>(&sym), sizeof(sym));
                ofs.write(reinterpret_cast<char*>(&sym), sizeof(sym));
            }
            all+=4;
            ofs.seekg(8, std::ios_base::cur);
        } else {
            ofs.write(reinterpret_cast<char*>(&sym), sizeof(sym));
        }
    }
    std::cout << "All" << std::endl;
    ofs.close();
    ifs.close();
    return 0;
}