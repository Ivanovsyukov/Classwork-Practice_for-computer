#include <iostream>
int main(){
    short int one;
    short int two;
    std::cout << "Input two numbers with space:";
    std::cin >> one >> two;
    int one_m[16];
    int two_m[16];
    int three_m[32];
    for (int i=15; i>-1; --i){
        one_m[i]=one%2;
        one=one/2;
        two_m[i]=two%2;
        two=two/2;
    }
    for (int i=31; i>-1; i=i-2){
        
    }
    return 0;
}