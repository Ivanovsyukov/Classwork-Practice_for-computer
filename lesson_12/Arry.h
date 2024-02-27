#ifndef MY_WORK
#define MY_WORK
template <typename T>
class ArrayforAnything{
    T* m_bytes;
    size_t size;
    size_t CountElement;
public:
    Arry(size_t size=1);
	void addElement(T elem);
	void removeElement(size_t pos);
	T getElement(size_t pos);
	void setElement(size_t pos, T value);
	void resize(size_t new_size);
	~Arry();
};
#endif