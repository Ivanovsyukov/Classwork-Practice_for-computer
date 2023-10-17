#include <iostream>
int main(){
    int num;
    std::cout << "Input number:";
    std::cin >> num;
    int sum=0;
    while (num>9){
        while(num!=0){
            sum+=num%10;
            num/=10;
        }
        num=sum;
        sum=0;
    }
    std::cout << "Your sum number - " << num << std::endl;
    return 0;
}