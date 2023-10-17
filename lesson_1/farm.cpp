#include <iostream>
int main(){
    int n;
    std::cout << "Input n:";
    std::cin >> n;
    std::cout << "We have " << 2*n << " legs" << std::endl;
    int count_cow=0, count_chiken=0;
    int leg_cow=0, leg_chiken=0, legs=2*n;
    for (int count_cow=0; count_cow<((legs)/4+1);++count_cow){
        leg_cow=count_cow*4;
        leg_chiken=legs-leg_cow;
        count_chiken=leg_chiken/2;
        std::cout << "We have " << count_cow << " cow and " << count_chiken << " chiken." << std::endl; 
    }
    return 0;
}