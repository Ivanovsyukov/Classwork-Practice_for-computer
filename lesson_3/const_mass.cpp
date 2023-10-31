#include <iostream>
const int n=15;
long long int a[n], b[n], c[n], d[n];
//Первый массив - числа от 1 до n, второй - сумма предыдущей и следующей, третьи - квадраты чисел
void printArray(long long int M[], int n, const char * name){
    std::cout << name << "--- ";
    for (int i=0; i<n; ++i){
        std::cout << M[i] << " ";
    }
    std::cout << std::endl;
}

int main(){
    for (int i=0; i<n; ++i){
        if (i>1){
            b[i]=b[i-1]+i+1;
        } else{
            b[i]=i+1;
        }
        a[i]=i+1;
        c[i]=(i+1)*(i+1);
    }
    printArray(a, n, "Count from 1 to n");
    printArray(b, n, "Sum number a");
    printArray(c, n, "Square of number from 1 to n");
    for (int i=0; i<n; ++i){
        std::cout << (double)c[i]/b[i] << " ";
    }
    std::cout << std::endl;
    long long int prom;
    for (int i=0; i<n; ++i){
        prom =c[i];
        d[i]=0;
        while(prom!=0){
            d[i]+=prom%2;
            prom/=2;
        }
    }
    printArray(d, n, "Count bit of number in third array");
    return 0;
}