#include <iostream>
const int n=2048;
long long int a[n], b[n], c[n], d[n];
//Первый массив - числа от 1 до n, второй - сумма предыдущей и следующей, третьи - квадраты чисел

int LenNumber(long long int f){
    int t=0;
    while(f!=0){
        t+=1;
        f/=10;
    }
    return t;
}

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
    long long int prom, max=0;
    for (int i=0; i<n; ++i){
        prom =c[i];
        d[i]=0;
        while(prom!=0){
            d[i]+=prom%2;
            prom/=2;
        }
        if (max<d[i]){
            max=d[i];
        }
    }
    printArray(d, n, "Count bit of number in third array");
    long long int len_m=LenNumber(max);
    for (int i=0; i<n; ++i){
        for (int j=0; j<(len_m-LenNumber(d[i])); ++j){
            std::cout << " ";
        }
        std::cout << d[i] << std::endl;
    }
    return 0;
}