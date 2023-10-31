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
            b[i]=b[i-1]+i;
        } else{
            b[i]=i;
        }
        a[i]=i;
        c[i]=i*i;
    }
    printArray(a, n, "Count from 0 to n-1");
    printArray(b, n, "Sum number a");
    printArray(c, n, "Square of number from 0 to n-1");
    return 0;
}