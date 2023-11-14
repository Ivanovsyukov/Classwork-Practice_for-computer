#include <iostream>
#include <fstream>

int main(){
    std::fstream fs;
    fs.open("D:\\program\\Git\\Classwork-Practice_for-computer\\lesson_4\\file.txt", std::ios_base::in);
    if (!fs.is_open()){
        std::cout << "File file.txt can not open." << std::endl;
        return 1;
    }
    int r, c, num;
    fs>>r>>c;
    //std::cout << r << c;
    int a[r][c];
    for(int i=0; i<r; ++i){
        for(int j=0; j<c; ++j){
            fs>>num;
            //std::cout << num;
            a[i][j]=num;
        }
    }
    for(int i=0; i<r; ++i){
        for(int j=0; j<c; ++j){
            std::cout << a[i][j] << " ";
        }
        std::cout << std::endl;
    }
    /*
    while(true){
        fs>>num;
        if (fs.eof()) break;
    }
    */
    fs.close();
    return 0;
}
