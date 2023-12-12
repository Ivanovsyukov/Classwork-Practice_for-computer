#include <iostream>

void call(char* p1, const char* p2, char* const p3, const char* const p4){
    std::cout<<p1<<std::endl;
    p1[1]='C';
    std::cout<<p2<<std::endl;
    //p2[1]='C'; - not
    ++p2;
    std::cout<<p2<<std::endl;
    std::cout<<p3<<std::endl;
    p3[1]='D';
    //++p3; not
    std::cout<<p4<<std::endl;
    //p4[1]='C'; - not
    //++p4; not
    delete[] p1;
    delete[] p2;
    delete[] p3;
    delete[] p4;
}

int main(){
    char *p=new char[3];
    p[0]='A';
    p[1]='B';
    p[2]=0;
    call(p, p, p, p);
    return 0;
}