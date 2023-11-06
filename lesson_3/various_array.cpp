#include <iostream>
typedef long long int arrty;
const size_t arrsize = 10000;

int main(){
    arrty arr1[arrsize]={ 1 };
    for (size_t k=0; k<arrsize; ++k){
        arr1[k]=rand();
    }
    int st=0, fin=0;
    int max=1, j=0;
    for (size_t i=1; i<arrsize; ++i){
        if (arr1[i]>arr1[i-1]){
            fin+=1;
        } else{
            if (max<fin){
                max=fin;
                j=st;
            }
            st=i;
            fin=0;
        }
    }
    std::cout << j << " " << max << std::endl;
    arrty arr2[arrsize]={ 1 };
    for (size_t i=0; i<arrsize; ++i){
        arr2[i]=i+1;
    }
    int col=3-1;
    arrty arr2uno[arrsize]={ 1 };
    int t=arrsize/col, d;
    for (size_t i=0; i<(arrsize-arrsize%col); i=i+2*col){
        d=arr2[i];
        arr2[i]=arr2[i+col];
        arr2[i+col]=d;
    }
    for (size_t i=0; i<arrsize; ++i){
        std::cout << arr2[i] << " ";
    }
    std::cout<<std::endl;
    return 0;
}
/*arrty* arr1=new arrty[arrsize];
    arrty* arr2=new arrty[arrsize];
    arrty* arr3=new arrty[arrsize];
    std::cout << sizeof(arr1) << std::endl;
    std::cout << sizeof(arr2) << std::endl;
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;*/