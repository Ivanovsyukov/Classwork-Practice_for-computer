#include <iostream>

template<typename T>
T * add(T* arr, size_t *size, T newelen){
    T *tmp=new T[*size+1];
    for(size_t k=0; k<*size; ++k){
        tmp[k]=arr[k];
    }
    tmp[*size]=newelen;
    delete[] arr;
    ++(*size);
    return tmp;
}

void stacksample(int a, int *pb, int c){
    std::cout << "a= " << a << std::endl;
    std::cout << "pb= " << pb << std::endl;
    std::cout << "*pb= " << *pb << std::endl;
    std::cout << "c= " << c << std::endl;
    std::cout << "&a= " << &a << std::endl;
    std::cout << "&pb= " << &pb << std::endl;
    std::cout << "&c= " << &c << std::endl;
}

int main(){
    int* num=nullptr;
    size_t len_num=0;
    int number;
    std::cin >> number;
    while(number!=0){
        num=add(num, &len_num, number);
        std::cin >> number;
    }
    if (num){
        char* rep=nullptr;
        size_t len_rep=0;
        size_t start=0, end=1;
        while(end!=len_num+1){
            while(end!=len_num && (num[end]-num[end-1]==1)){
                ++end;
            }
            char buffer[32];
            if ((end-start)==1){
                snprintf(buffer, sizeof(buffer), "%d", num[start]);
                for(size_t j=0; j<sizeof(buffer) && buffer[j]!='\0';++j){
                    rep=add(rep, &len_rep, buffer[j]);
                }
            }
            else{
                snprintf(buffer, sizeof(buffer), "%d", num[start]);
                for(size_t j=0; j<sizeof(buffer) && buffer[j]!='\0';++j){
                    rep=add(rep, &len_rep, buffer[j]);
                }
                rep=add(rep, &len_rep, '-');
                snprintf(buffer, sizeof(buffer), "%d", num[end-1]);
                for(size_t j=0; j<sizeof(buffer) && buffer[j]!='\0';++j){
                    rep=add(rep, &len_rep, buffer[j]);
                }
            }
            if (end!=len_num){
                rep=add(rep, &len_rep, ',');
            }
            start=end;
            end+=1;
        }
        std::cout << rep << std::endl;
    }
    /*
    for(size_t i=0; i<len_num; ++i){
        std::cout << num[i] << " ";
    }
    */
    return 0;
}