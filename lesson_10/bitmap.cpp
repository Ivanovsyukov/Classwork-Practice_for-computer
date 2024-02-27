#include <iostream>
#include <fstream>
#include "Bitmap.h"

BMP::BMP(unsigned int weight, unsigned int height){
    size=int((weight+31)/32)*4*height;
    m_bytes=new unsigned char[size+size_main];
    std::ifstream temp("D:\\program\\Git\\Classwork-Practice_for-computer\\lesson_10\\template.bmp", std::ios_base::in | std::ios_base::binary);
    if (!temp.is_open()){
        std::cout << "temp is not read" << std::endl;
    }
    char s;
    for (int i=0; i<(size+size_main); ++i){
        if (i<62){
            temp >> s;
            if (i==2){
                m_bytes[i++]=(((size+size_main)&0xFF));
                m_bytes[i++]=(((size+size_main)&0xFF00)>>8);
                m_bytes[i++]=(((size+size_main)&0xFF0000)>>16);
                m_bytes[i]=((size+size_main)>>24);
                temp.seekg(3, std::ios_base::cur);
            }
            else if (i==18){
                m_bytes[i++]=char((weight&0xFF));
                m_bytes[i++]=char((weight&0xFF00)>>8);
                m_bytes[i++]=char((weight&0xFF0000)>>16);
                m_bytes[i]=char(weight>>24);
                temp.seekg(3, std::ios_base::cur);
            } else if (i==22) {
                m_bytes[i++]=char((height&0xFF));
                m_bytes[i++]=char((height&0xFF00)>>8);
                m_bytes[i++]=char((height&0xFF0000)>>16);
                m_bytes[i]=char(height>>24);
                temp.seekg(3, std::ios_base::cur);
            }else if (i==34){
                m_bytes[i++]=char((size&0xFF));
                m_bytes[i++]=char((size&0xFF00)>>8);
                m_bytes[i++]=char((size&0xFF0000)>>16);
                m_bytes[i]=char(size>>24);
                temp.seekg(3, std::ios_base::cur);
            } else {
                m_bytes[i]=s;
            }
        } else {
            m_bytes[i]=0;
        }
    }
    temp.close();
}

unsigned int BMP::get_Height() const{
    return height;
}

unsigned int BMP::get_Weight() const{
    return weight;
}

void BMP::save(const char* filename) const{
    std::ofstream temp1(filename, std::ios_base::out | std::ios_base::binary);
    if (!temp1.is_open()){
        std::cout << "temp1 is not read" << std::endl;
        return;
    }
    for(int i=0; i<size; ++i){
        temp1 << m_bytes[i];
    }
    temp1.close();
}

void BMP::setPixelColor(unsigned int row, unsigned int col, bool color){

}

bool BMP::getPixelColor(unsigned int row, unsigned int col) const{
    return true;
}

BMP::~BMP(){
    delete[] m_bytes;
}
