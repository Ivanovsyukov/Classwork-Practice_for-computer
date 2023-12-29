#include <iostream>
#include <fstream>

struct change_array{
    unsigned char len;
    char* array;
};

int main(int argc, char* argv[]){
    if (argc!=4){
        std::cout << "Мало аргументов" << std::endl;
        return -1;
    }
    std::ifstream input(argv[2], std::ios_base::binary);
    if (!input){
        std::cout << "File " << argv[2] << " can not open." << std::endl;
        return 1;
    }
    std::ofstream output(argv[3], std::ios_base::binary);
    if (!output){
        input.close();
        std::cout << "File " << argv[3] << " can not open." << std::endl;
        return 1;
    }
    char s;
    char ost;
    unsigned char cnt=1;
    bool first=true;
    bool one_s=false;
    change_array for_o;
    for_o.len=0;
    for_o.array=nullptr;
    while(true){
        input.get(s);
        if (input.eof()) break;
        if (first){
            ost=s;
            first=false;
            continue;
        }
        if (s==ost){
            if (one_s){
                output<<for_o.len;
                for(unsigned char i=0; i<for_o.len; ++i){
                    output<<for_o.array[i];
                }
                delete[] for_o.array;
                for_o.len=0;
                for_o.array=nullptr;
                one_s=false;
            }
            cnt=(unsigned char)((int)(cnt)+1);
        } else {
            if ((int)(cnt)==1){
                one_s=true;
                char* tmp=new char[for_o.len+1];
                for(unsigned char i=0; i<for_o.len; ++i){
                    tmp[i]=for_o.array[i];
                }
                tmp[for_o.len]=ost;
                for_o.len++;
                delete[] for_o.array;
                for_o.array=tmp;
                if ((int)(for_o.len)==127){
                    output<<for_o.len-2;
                    for(unsigned char i=0; i<for_o.len; ++i){
                        output<<for_o.array[i];
                    }
                    delete[] for_o.array;
                    for_o.len=0;
                    for_o.array=nullptr;
                    one_s=false;
                }
            } else {
                output << (unsigned char)(0);
                output << ost;
                output << cnt;
            }
            ost=s;
            cnt=(unsigned char)(1);
        }
    }
    if (one_s){
        output<<for_o.len;
        for(unsigned char i=0; i<for_o.len; ++i){
            output<<for_o.array[i];
        }
        delete[] for_o.array;
        for_o.len=0;
        for_o.array=nullptr;
        one_s=false;
    }
    delete[] for_o.array;
    input.close();
    output.close();
    return 0;
}