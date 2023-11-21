#include <iostream>
#include <fstream>
#include <chrono>

int main(int argc, char* argv[]){
    if (argc<3){
        std::cout << "You have less argument" << std::endl;
        return 1;
    }
    char* fname=argv[1];
    std::cout << fname << std::endl;
    std::fstream fs;
    fs.open(fname, std::ios_base::in);
    if (!fs.is_open()){
        std::cout << "File array.txt can not open." << std::endl;
        return 2;
    }
    char buffer[atoi(argv[2])];
    const auto start{std::chrono::steady_clock::now()};
    while(true){
        fs.read(buffer, sizeof(buffer));
        //std::cout << fs.gcount() << " bites read" << std::endl;
        if (fs.gcount() < sizeof(buffer)){
            /*
            for (size_t k=0; k<fs.gcount(); ++k){
                std::cout << buffer[k];
            }
            */
            break;
        }
        /*
        for (size_t k=0; k<sizeof(buffer); ++k){
            std::cout << buffer[k];
        }
        */
    }
    const auto end{std::chrono::steady_clock::now()};
    const auto duration =std::chrono::duration_cast<std::chrono::milliseconds>(end-start);
    std::cout << "File read in " << duration.count() << " milliseconds" << std::endl;
    fs.close();
    return 0;
}