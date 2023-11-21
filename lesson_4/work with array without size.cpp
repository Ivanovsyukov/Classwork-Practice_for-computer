#include <iostream>
#include <fstream>

int main(){
    std::fstream fs;
    fs.open("D:\\program\\Git\\Classwork-Practice_for-computer\\lesson_4\\array.txt", std::ios_base::in);
    if (!fs.is_open()){
        std::cout << "File array.txt can not open." << std::endl;
        return 1;
    }
    char* c=nullptr;
    size_t len_c=0;
    char sym;
    while(true){
        fs.get(sym);
        if(fs.eof()) break;
        if (sym=='\n'){
            sym=' ';
        }
        char *tmp=new char[len_c+1];
        for(size_t k=0; k<len_c; ++k){
            tmp[k]=c[k];
        }
        tmp[len_c]=sym;
        len_c+=1;
        delete[] c;
        c=tmp;
    }
    std::cout << c << std::endl;
    fs.close();
    return 0;
}