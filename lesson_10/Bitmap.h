#ifndef MY_UTILS_FOR_HEXVIEW_16122023_Parteyeye_
#define MY_UTILS_FOR_HEXVIEW_16122023_Parteyeye_
#include <fstream>
#include "Array.h"
class BMP
{
private:
    Array *m_arry;
/*
    unsigned char* m_bytes;
    unsigned int weight;
    unsigned int height;
    unsigned int size;
    const unsigned int size_main=62;
*/
public:
    BMP(unsigned int weight=64, unsigned int height=64);
    void setPixelColor(unsigned int row, unsigned int col, bool color);
    bool getPixelColor(unsigned int row, unsigned int col) const;
    void save(const char* filename) const;
    unsigned int get_Weight() const;
    unsigned int get_Height() const;
    ~BMP();
};
#endif