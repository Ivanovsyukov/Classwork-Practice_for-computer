#ifndef MY_UTILS_FOR_HEXVIEW_16122023_Parteye
#define MY_UTILS_FOR_HEXVIEW_16122023_Parteye
class Array
{
private:
    unsigned char* m_bytes;
public:
    Array(size_t size);
    void addElement(unsigned char ele);
    void removeElement(size_t pos);
    void setPixelColor(size_t pos, unsigned char value);
    unsigned char getPixelColor(size_t pos);
    void resize(size_t new_size);
    ~Array(){
        delete m_bytes;
    };
};
#endif