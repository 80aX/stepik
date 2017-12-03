// Добавьте в класс String реализацию конструктора копирования. Инвариант класса остается 
// тем же (в size хранится размер строки без завершающего 0 символа, str указывает на C-style 
// строку, т. е. с завершающим нулевым символом). 

// Требования к реализации: вы можете заводить любые вспомогательные методы или функции, но 
// не реализуйте заново методы из предыдущих заданий — они уже реализованы. При реализации не 
// нужно вводить или выводить что-либо. Реализовывать main не нужно. Не используйте функции из 
// cstdlib (malloc, calloc, realloc и free).


#include <algorithm>
#include <cstddef>
#include <cstring>


struct String 
{
    String(const char *str = "");
    String(size_t n, char c);
    String(const String &other);
    ~String();
    
    String &operator = (const String &other) {
        
        if (this != &other)
            String(other).swap(*this);
        
        return *this;
    }
    void swap(String & a) {
        size_t const tmp1 = size;
        size = a.size;
        a.size = tmp1;
        char * const tmp2 = str;
        str = a.str;
        a.str = tmp2;
    }
    void append(const String &other);

    size_t size;
    char *str;
};


int main(void) 
{
    String s1("Hello,");
    String s2(" world!");
    return 0;
}
