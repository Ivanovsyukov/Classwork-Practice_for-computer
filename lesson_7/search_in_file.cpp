#include <iostream>
#include <fstream>

int main(int argc, char* argv[]){
    if (argc<4){
        std::cout << "Misstake" << std::endl;
        return 1;
    }
    std::ifstream ifs;
    ifs.open(argv[1], std::ios_base::in);
    if (!ifs.is_open()){
        std::cout << "File " << argv[1] << " can not open." << std::endl;
        return 2;
    }
    std::ofstream ofs;
    ofs.open(argv[2], std::ios_base::out);
    if (!ofs.is_open()){
        ifs.close();
        std::cout << "File " << argv[2] << " can not open." << std::endl;
        return 2;
    }
    const char* f=argv[3];
    int len_stec=0;
    char s=f[len_stec++];
    while(s!=0){
        s=f[len_stec++];
    }
    len_stec--;
    char* c=nullptr;
    size_t len_c=0;
    char sym;
    int count_str=0;
    int count_word=0;
    int test_len=0;
    bool search=false;
    bool end=false;
    while(true){
        ifs.get(sym);
        //std::cout << sym << std::endl;
        if (ifs.eof()) break;
        if (sym=='\n'){
            if (search){
                if (end){
                    ofs<<std::endl;
                }
                //std::cout << len_c << std::endl;
                //std::cout << c << std::endl;
                for(size_t i=0; i<len_c; ++i){
                    ofs<<c[i];
                }
                search=false;
                end=true;
                count_str++;
            }
            len_c=0;
            char* c=nullptr;
        } else {
            if (sym==f[test_len]){
                ++test_len;
            } else {
                test_len=0;
                if (sym==f[test_len]){
                    test_len++;
                }
            }
            if (test_len==len_stec){
                search=true;
                count_word++;
            }
            char *tmp=new char[len_c+1];
            for(size_t k=0; k<len_c; ++k){
                tmp[k]=c[k];
            }
            tmp[len_c]=sym;
            len_c++;
            c=tmp;
            //std::cout << c << std::endl;
        }
    }
    if (test_len==len_stec){
        search=true;
        count_word++;
        //std::cout << "Привет";
    }
    if (search){
        if(end){
            ofs<<std::endl;
        }
        for(size_t i=0; i<len_c; ++i){
            ofs<<c[i];
        }
        count_str++;
    }
    ifs.close();
    ofs.close();
    delete[] c;
    std::cout << count_str << " " << count_word << std::endl;
    return 0;
}
/*С конца. Если совпадают ок. Нет - проверка на наличие. Есть сдвигаем до него. Нет - сдвигаем всю*/