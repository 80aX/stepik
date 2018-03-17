// Скобки в коде

// Проверить, правильно ли расставлены скобки в данном коде.
// Вход. Исходный код программы.
// Выход. Проверить, верно ли расставлены скобки. Если нет, выдать индекс первой ошибки.


#include <iostream>
#include <vector>
#include <map>
#include <cstring>


int isbalanced(const char* str, size_t str_size)
{
    int counter = 1;
    std::vector<std::map<int, char> > stack;
    
    for (int i = 0; i < str_size; ++i) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            std::map<int, char> onst = {{i, str[i]}};
            stack.push_back(onst);
        } else if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
            if (stack.empty())
                return counter;
            std::map<int, char> lst = stack.back();
            char top = lst.begin()->second;
            if ((top == '(' && str[i] != ')') ||
                (top == '[' && str[i] != ']') || 
                (top == '{' && str[i] != '}'))
                return counter;
            stack.pop_back();
        }
        counter++;
    }
    if (stack.empty()) {
        return -1;
    } else {
        std::map<int, char> lst = stack.back();
        return (lst.begin() -> first) + 1;
    }
}


int main() 
{
    // const char *tests[] = {
        // "([](){([])})",     // Success
        // "()[]}",            // 5
        // "{{[()]]",          // 7
        // "{{{[][][]",        // 3
        // "{{",               // 2
        // "{}",               // Success
        // "",                 // Success
        // "}",                // 1
        // "s{}",              // Success
        // "{{{ss[][][]",      // 3
        // "()({}",            // 3
        // "[]([]",            // 3
        // "([]",              // 1
        // "[]",               // Success
        // "{}[]",             // Success
        // "[()]",             // Success
        // "(())",             // Success
        // "{[]}()",           // Success
        // "{",                // 1
        // "{[}",              // 3
        // "foo(bar)",         // Success
        // "foo(bar[i)",       // 10
        
        // "(((((((((())))",   // 6 !!!
        // "((()"              // 2
    // };
    
    // for (int j = 0; j < 24; ++j) {
        // int result = isbalanced(tests[j], strlen(tests[j]));
        // if (result != -1) {
            // std::cout << result << std::endl;
        // } else {
            // std::cout << "Success" << std::endl;
        // }
    // }
    
    char inp[100000];
    std::cin >> inp;
    
    int result = isbalanced(inp, strlen(inp));
    if (result != -1) {
        std::cout << result << std::endl;
    } else {
        std::cout << "Success" << std::endl;
    }
    
    return 0;
}
