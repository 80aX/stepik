// Стек с поддержкой максимума

// Реализовать стек с поддержкой операций push, pop и max.
// Вход. Последовательность запросов push, pop и max.
// Выход. Для каждого запроса max вывести максимальное число, находящее на стеке.


#include <iostream>
#include <vector>


int main()
{
    std::vector<int> stack;
    std::vector<int> stackmax;
    
    int n = 0;
    std::cin >> n;
    
    for (int i = 0; i < n; ++i) {
        int value;
        std::string cmd;
        std::cin >> cmd;
        
        if (cmd == "push") {
            std::cin >> value;
            stack.push_back(value);
            if (stackmax.empty()) {
                stackmax.push_back(value);
            } else {
                stackmax.push_back(std::max(stackmax.back(), value));
            }
        } else if (cmd == "pop") {
            stack.pop_back();
            stackmax.pop_back();
        } else if (cmd == "max") {
            std::cout << stackmax.back() << std::endl;
        }
    }
    
    return 0;
}
