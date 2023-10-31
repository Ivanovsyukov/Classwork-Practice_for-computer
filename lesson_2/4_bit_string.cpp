#include <iostream>

int main(){
    short int r;
    std::cout << "Input your number: ";
    std::cin >> r;
    int l=sizeof(r)*8;
    unsigned short int top_r, tops_r;
    if (r<0){
        tops_r=0+r;
    }
    else{
        tops_r=r;
    }
    for (int i=l-4; i>=0; i=i-4){
        top_r=tops_r>>i;
        top_r%=16;
        std::cout << top_r << std::endl;
    }
    return 0;
}