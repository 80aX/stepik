// Реализуйте шаблонную версию класса Array. Список всех операций, которые должен поддерживать 
// класс Array, приведен в шаблоне кода.


#include <iostream>
#include <cstddef>


template <typename T>
class Array 
{
    private:
        size_t size_;
        T * data_;
    
    public:
        explicit Array(size_t size = 0, const T& value = T())
            : size_(size), data_(new T[size]) {
                
                for (size_t i = 0; i != size_; ++i)
                    data_[i] = value;
            }
            
        Array(const Array & tmp) 
            : size_(tmp.size_), data_(new T[tmp.size_]) {
                
                for (size_t i = 0; i != size_; ++i)
                    data_[i] = tmp.data_[i];
            }
        
        Array& operator=(const Array & tmp) {
            if (this != &tmp) {
                delete [] data_;
                size_ = tmp.size_;
                data_ = new T[size_];
                
                for (size_t i = 0; i != size_; ++i)
                    data_[i] = tmp.data_[i];
            }
            
            return *this;
        }
        
        ~Array() {delete [] data_;}
        
        size_t size() const {return size_;}
        T& operator[](size_t i) {return data_[i];}
        const T& operator[](size_t i) const {return data_[i];}
};


int main() 
{
    Array<int> *arr0 = new Array<int>();
    Array<int> *arr1 = new Array<int>(10,7);
    Array<float> *arr2 = new Array<float>(5,8.88f);
    Array<float> arr3 = Array<float>(*arr2);
    Array<float> arr4;
    arr4 = arr3;

    for (size_t i = 0; i < arr1->size(); i++)
        std::cout << "Value of " << i << " element is " << (*arr1)[i] << std::endl;

    std::cout << std::endl;

    for (size_t i = 0; i < arr4.size(); i++)
        std::cout << "Value of " << i << " element is " << arr4[i] << std::endl;

    return 0;
}
