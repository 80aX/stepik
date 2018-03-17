// Максимум в скользящем окне

// Найти максимум в каждом окне размера m данного массива чисел A[1 . . . n].
// Вход. Массив чисел A[1 . . . n] и число 1 ≤ m ≤ n.
// Выход. Максимум подмассива A[i . . . i + m − 1] для всех 1 ≤ i ≤ n − m + 1.


#include <iostream>
#include <vector>
#include <queue>


void max_in_window(int n, std::vector<int> array, int m)
{
    std::queue<std::pair<int, int> > stack_input;
    std::vector<std::pair<int, int> > stack_output;
    
    for (int i = 0; i < m - 1; ++i) {
        if (stack_input.empty()) {
            stack_input.push(std::make_pair(array[i], array[i]));
        } else {
            int current_max = stack_input.back().second;
            stack_input.push(std::make_pair(array[i], std::max(array[i], current_max)));
        }
    }
    
    for (int j = m - 1; j < n; ++j) {
        if (stack_output.empty()) {
            while (!stack_input.empty()) {
                stack_output.push_back(stack_input.front());
                stack_input.pop();
            }
        }
        if (stack_input.empty()) {
            stack_input.push(std::make_pair(array[j], array[j]));
        } else {
            int current_max = (stack_input.back()).second;
            stack_input.push(std::make_pair(array[j], std::max(array[j], current_max)));
        }
        
        std::cout << std::max(stack_input.back().second, stack_output.back().second) << ' ';
        stack_output.pop_back();
    }
}


int main()
{
    max_in_window(8, {2, 7, 3, 1, 5, 2, 6, 2}, 4);
    std::cout << std::endl;
    // max_in_window(3, {2, 1, 5}, 1);
    // std::cout << std::endl;
    max_in_window(3, {2, 3, 9}, 3);
    std::cout << std::endl;
    max_in_window(15, {73, 65, 24, 14, 44, 20, 65, 97, 27, 6, 42, 1, 6, 41, 16}, 7);
    std::cout << std::endl;
    max_in_window(15, {28, 7, 64, 40, 68, 86, 80, 93, 4, 53, 32, 56, 68, 18, 59}, 12);
    std::cout << std::endl;
    max_in_window(15, {16, 79, 20, 19, 43, 72, 78, 33, 40, 52, 70, 79, 66, 43, 60}, 12);
    std::cout << std::endl;
    max_in_window(15, {34, 51, 61, 90, 26, 84, 2, 25, 7, 8, 25, 78, 21, 47, 25}, 3);
    std::cout << std::endl;
    max_in_window(15, {27, 83, 29, 77, 6, 3, 48, 2, 16, 72, 46, 38, 55, 2, 58}, 5);
    std::cout << std::endl;
    
    // 7 7 5 6 6
    // 2 1 5
    // 9
    // 73 97 97 97 97 97 97 97 42
    // 93 93 93 93
    // 79 79 79 79
    // 61 90 90 90 84 84 25 25 25 78 78 78 47
    // 83 83 77 77 48 72 72 72 72 72 58
    
    
    // int n = 0;
    // std::cin >> n;
    // std::vector<int> array;
    
    // for (int i = 0; i < n; ++i) {
        // int value;
        // std::cin >> value;
        // array.push_back(value);
    // }
    
    // int m = 0;
    // std::cin >> m;
    
    // max_in_window(n, array, m);
    
    return 0;
}

