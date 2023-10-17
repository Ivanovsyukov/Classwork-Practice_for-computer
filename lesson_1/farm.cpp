#include <iostream>
int main(){
    int n;
    std::cout << "Input n:";
    std::cin >> n;
    std::cout << "We have " << 2*n << " legs" << std::endl;
    int count_cow=0, count_chiken=0;
    int leg_cow=0, leg_chiken=0, legs=2*n;
    int k=0;
    for (int count_cow=0; count_cow<(((legs)/4+1)/2+1);++count_cow){
        leg_cow=count_cow*4;
        leg_chiken=legs-leg_cow;
        count_chiken=leg_chiken/2;
        k+=1;
        std::cout << "We have " << count_cow << " cow and " << count_chiken << " chiken." << std::endl;
        if ((count_cow<((legs)/4+1)/2)&&(count_chiken%2==0)){
            std::cout << "We have " << count_chiken/2 << " cow and " << count_cow*2 << " chiken." << std::endl;
        }
    }
    std::cout << "We have " << k << " loop" << std::endl;
    return 0;
}