#include <iostream>
#include <fstream>
#include <chrono>

int main(int argc, char* argv[]){
    if (argc<3){
        std::cout << "You have less argument" << std::endl;
        return 1;
    }
    char* fname=argv[1];
    //std::cout << fname << std::endl;
    std::fstream fs;
    fs.open(fname, std::ios_base::in);
    if (!fs.is_open()){
        std::cout << "File " << fname << " can not open." << std::endl;
        return 2;
    }
    std::fstream outfs;
    outfs.open(argv[2], std::ios_base::out | std::ios_base::binary);
    if (!fs.is_open()){
        outfs.close();
        fs.close();
        std::cout << "File " << argv[2] << " can not open." << std::endl;
        return 3;
    }
    double value=0.0;
    double s=0.0;
    const auto start{std::chrono::steady_clock::now()};
    while(true){
        //fs.read((char*)(&value), sizeof(value));
        fs.read(reinterpret_cast<char*>(&value), sizeof(value));
        std::cout << fs.gcount() << " bites read" << std::endl;
        if (fs.gcount() < sizeof(value)){
            /*
            for (size_t k=0; k<fs.gcount(); ++k){
                std::cout << buffer[k];
            }
            */
            outfs<<value;
            s+=value;
            break;
        }
        /*
        for (size_t k=0; k<sizeof(buffer); ++k){
            std::cout << buffer[k];
        }
        */
        outfs<<value<<" ";
        s+=value;
    }
    std::cout << s << std::endl;
    const auto end{std::chrono::steady_clock::now()};
    const auto duration =std::chrono::duration_cast<std::chrono::milliseconds>(end-start);
    std::cout << "File read in " << duration.count() << " milliseconds" << std::endl;
    fs.close();
    outfs.close();
    return 0;
}