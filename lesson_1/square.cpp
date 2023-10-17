#include <iostream>
#include <cstdlib>
#include <ctime>

int main(){
    srand(time(0));
    int r;
    int count_all, count_round=0, k=0;
    int rando_x, rando_y;
    std::cout << "Input line of square:";
    std::cin >> r;
    std::cout << "Input count point:";
    std::cin >> count_all;
    while (k<count_all){
        rando_x=rand();
        rando_y=rand();
        if ((rando_x<r)&&(rando_y<r)){
            k+=1;
            if ((rando_x*rando_x+rando_y*rando_y)<=(r*r)){
                count_round+=1;
            }
        }
    }
    double pi=(double)4*count_round/count_all;
    std::cout << "pi= " << pi << std::endl;
    return 0;
}