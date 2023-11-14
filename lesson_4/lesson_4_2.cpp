#include <iostream>

template <typename T>
T getElement(T *p, size_t r, size_t c, size_t rowlen){
    return p[r*rowlen+c];
}
template <typename T>
T setElement(T newvalue, T *p, size_t r, size_t c, size_t rowlen){
    return p[r*rowlen+c];
}

int main(){
    int a[2][3]={{1, 2, 3}, {4, 5, 6}};
    for (size_t r=0; r<2; ++r){
        for (size_t c=0; c<3; ++c){
            std::cout << a[r][c] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "Sizeof(a) " << sizeof(a) << std::endl;
    int *b[2];
    for (size_t r=0; r<2; ++r){
        b[r]=new int[3];
    }
    for (size_t r=0; r<2; ++r){
        for (size_t c=0; c<3; ++c){
            std::cout << b[r][c] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "Sizeof(b) " << sizeof(b) << std::endl;
    int **w=new int*[2];
    for (size_t r=0; r<2; ++r){
        w[r]=new int[3];
    }
    for (size_t r=0; r<2; ++r){
        for (size_t c=0; c<3; ++c){
            std::cout << w[r][c] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "Sizeof(w) " << sizeof(w) << std::endl;
    for (size_t r=0; r<2; ++r){
        for (size_t c=0; c<3; ++c){
            std::cout << getElement(w, r, c, 2) << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}