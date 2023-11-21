#include <iostream>
#include <fstream>

int main(int argc, char* argv[]){
    if (argc<4){
        std::cout << "You have less argument" << std::endl;
        return 1;
    }
    std::fstream fs;
    fs.open(argv[1], std::ios_base::in);
    if (!fs.is_open()){
        std::cout << "File " << argv[1] << " can not open." << std::endl;
        return 1;
    }
    std::fstream outfs;
    outfs.open(argv[2], std::ios_base::out);
    if (!outfs.is_open()){
        outfs.close();
        fs.close();
        std::cout << "File " << argv[2] << " can not open." << std::endl;
        return 3;
    }
    double value=0.0;
    size_t filesize=atoi(argv[3]);
    for (size_t k=0; k<filesize/sizeof(value); ++k){
        fs>>value;
        outfs.write(reinterpret_cast<const char*>(&value), sizeof(value));
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
    outfs.close();
    return 0;
}