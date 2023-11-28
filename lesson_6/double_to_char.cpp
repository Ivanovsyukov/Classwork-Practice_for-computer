#include <iostream>
#include <fstream>
#include <chrono>

int main(){
    std::ifstream ifs;
    ifs.open("D:\\program\\Git\\Classwork-Practice_for-computer\\lesson_6\\file.txt", std::ios_base::in);
    if (!ifs.is_open()){
        std::cout << "File " << "D:\\program\\Git\\Classwork-Practice_for-computer\\lesson_6\\file.txt" << " can not open." << std::endl;
        return 2;
    }
    std::fstream ofs;
    ofs.open("D:\\program\\Git\\Classwork-Practice_for-computer\\lesson_6\\file_new.bin", std::ios_base::out | std::ios_base::binary);
    if (!ofs.is_open()){
        ofs.close();
        ifs.close();
        std::cout << "File " << "D:\\program\\Git\\Classwork-Practice_for-computer\\lesson_6\\file_new.bin" << " can not open." << std::endl;
        return 3;
    }
    double value=0.0;
    double s=0.0;
    size_t count=0;
    const auto start{std::chrono::steady_clock::now()};
    while(true){
        //fs.read((char*)(&value), sizeof(value));
        ifs>>value;
        if(ifs.eof()) break;
        ++count;
        ofs.write(reinterpret_cast<char*>(&value), sizeof(value));
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