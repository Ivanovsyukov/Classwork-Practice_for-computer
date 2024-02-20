#include <iostream>
int twice(int x){
    if (x>1){
        twice(x/2);
    }
    std::cout << x%2;
    return 0;
}

int main(){
    int num;
    std::cout << "Input your number:";
    std::cin >> num;
    twice(num);
    return 0;
}