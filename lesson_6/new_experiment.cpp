#include <iostream>
#include <iomanip>
#include <fstream>
#include <chrono>

int main(){
    std::ifstream ifs;
    ifs.open("D:\\program\\Git\\Classwork-Practice_for-computer\\lesson_6\\file.bin", std::ios_base::in | std::ios_base::binary);
    if (!ifs.is_open()){
        std::cout << "File " << "D:\\program\\Git\\Classwork-Practice_for-computer\\lesson_6\\file.bin" << " can not open." << std::endl;
        return 2;
    }
    std::fstream ofs;
    ofs.open("D:\\program\\Git\\Classwork-Practice_for-computer\\lesson_6\\file.txt", std::ios_base::out | std::ios_base::binary);
    if (!ofs.is_open()){
        ofs.close();
        ifs.close();
        std::cout << "File " << "D:\\program\\Git\\Classwork-Practice_for-computer\\lesson_6\\file.txt" << " can not open." << std::endl;
        return 3;
    }
    double value=0.0;
    double s=0.0;
    size_t count=0;
    const auto start{std::chrono::steady_clock::now()};
    while(true){
        //fs.read((char*)(&value), sizeof(value));
        ifs.read(reinterpret_cast<char*>(&value), sizeof(value));
        std::cout << ifs.gcount() << " bites read" << std::endl;
        if (ifs.gcount() < sizeof(value)){
            /*
            for (size_t k=0; k<fs.gcount(); ++k){
                std::cout << buffer[k];
            }
            */
            ofs<<std::setprecision(16.3)<<value;
            s+=value;
            break;
        }
        /*
        for (size_t k=0; k<sizeof(buffer); ++k){
            std::cout << buffer[k];
        }
        */
        ++count;
        ofs<<std::setprecision(16.3)<<value<<" "; //увеличение точности
        s+=value;
    }
    std::cout << s << std::endl;
    const auto end{std::chrono::steady_clock::now()};
    const auto duration =std::chrono::duration_cast<std::chrono::milliseconds>(end-start);
    std::cout << "File read in " << duration.count() << " milliseconds" << std::endl;
    std::cout << "Value: " << count << " was read" << std::endl;
    ifs.close();
    ofs.close();
    return 0;
}