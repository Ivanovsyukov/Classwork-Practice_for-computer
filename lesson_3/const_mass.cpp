#include <iostream>
//Первый массив - числа от 1 до n, второй - сумма предыдущей и следующей, третьи - квадраты чисел
void printArray(int M[], int n, const char * name){
    std::cout << name << "--- ";
    for (int i=0; i<n; ++i){
        std::cout << M[i] << " ";
    }
    std::cout << std::endl;
}

int main(){
    const int n=15;
    int a[n], b[n], c[n];
    for (int i=0; i<n; ++i){
        if (i>1){
            b[i]=b[i]+i;
        } else{
            b[i]=i;
        }
        a[i]=i;
        c[i]=i*i;
    }
    printArray(a, n, "Count from 1 to n");
    printArray(b, n, "Sum number a");
    printArray(c, n, "square of number from 1 to n");
    return 0;
}