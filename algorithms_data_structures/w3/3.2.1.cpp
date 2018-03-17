// Телефонная книга

// Реализовать структуру данных, эффективно обрабатывающую запросы вида add number name, 
// del number и find number.
// Вход. Последовательность запросов вида add number name, del number и find number, 
// где number — телефонный номер, содержащий не более семи знаков, а name — короткая строка.
// Выход. Для каждого запроса find number выведите соответствующее имя или сообщите, 
// что такой записи нет.


#include <iostream>
#include <unordered_map>


class phonebook
{
    private:
        int n;
        std::unordered_map<int, std::string> pbook;
        
    public:
        phonebook(int n_) {
            n = n_;
        }
        
        void add_(int key, std::string name) {
            if (pbook.find(key) == pbook.end()) {
                pbook.insert(std::make_pair(key, name));
            } else {
                pbook[key] = name;
            }
        }
        
        void del_(int key) {
            if (pbook.find(key) != pbook.end()) {
                pbook.erase(key);
            }
        }
        
        void find_(int key) {
            if (pbook.find(key) == pbook.end()) {
                std::cout << "not found" << std::endl;
            } else {
                std::cout << pbook[key] << std::endl;
            }
        }
        
        void processing() {
            for (int i = 0; i < n; ++i) {
                int number;
                std::string cmd;
                std::cin >> cmd;
                
                if (cmd == "add") {
                    std::string name;
                    std::cin >> number >> name;
                    add_(number, name);
                } else if (cmd == "del") {
                    std::cin >> number;
                    del_(number);
                } else if (cmd == "find") {
                    std::cin >> number;
                    find_(number);
                }
            }
        }
};


int main()
{
    int n;
    std::cin >> n;
    
    phonebook test(n);
    test.processing();
    
    return 0;
}
