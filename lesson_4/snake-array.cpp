#include <iostream>

int main(){
    int c, r;
    std::cout << "Input rows: ";
    std::cin >> r;
    std::cout << "Input colows: ";
    std::cin >> c;
    int** w=new int*[r];
    for (size_t k=0; k<r; ++k){
        w[k]=new int[c];
    }
    int num=1;
    for (size_t k=0; k<r; ++k){
        for (size_t j=0; j<c; ++j){
            if (k%2==0){
                w[k][j]=num;
            } else {
                w[k][c-j-1]=num;
            }
            num++;
        }
    }
    for (size_t k=0; k<r; ++k){
        for (size_t j=0; j<c; ++j){
            std::cout << w[k][j] << " ";
        }
        std::cout << std::endl;
    }
    for (size_t k=0; k<r; ++k){
        delete[] w[k];
    }
    delete[] w;
    return 0;
}