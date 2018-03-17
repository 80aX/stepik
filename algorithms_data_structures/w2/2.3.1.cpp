// Построение кучи

// Переставить элементы заданного массива чисел так, чтобы он удовлетворял свойству мин-кучи.
// Вход. Массив чисел A[0 . . . n − 1].
// Выход. Переставить элементы массива так, чтобы выпол нялись неравенства A[i] ≤ A[2i + 1]
// и A[i] ≤ A[2i + 2] для всех i.


#include <iostream>
#include <math.h> 
#include <vector>


class minheap
{
    private:
        int size;
        int counter;
        std::vector<int> H;
        std::vector<std::pair<int, int> > exchange;
        
    public:
        minheap(int size_, std::vector<int> H_) {
            size = size_;
            H.swap(H_);
            counter = 0;
        }
        
        int get_parent(int i) {
            return (int)floor(i / 2);
        }
        
        int get_left_child(int i) {
            return 2 * i + 1;
        }
        
        int get_right_child(int i) {
            return 2 * i + 2;
        }
        
        void shift_up(int i) {
            while (i > 0 && H[get_parent(i)] > H[i]) {
                exchange.push_back(std::make_pair(get_parent(i), i));
                std::swap(H[get_parent(i)], H[i]);
                i = get_parent(i);
                counter++;
            }
        }
        
        void shift_down(int i) {
            int min_index = i;
            
            int l = get_left_child(i);
            if (l <= size - 1 && H[l] < H[min_index]) {
                min_index = l;
            }
                
            int r = get_right_child(i);
            if (r <= size - 1 && H[r] < H[min_index]) {
                min_index = r;
            }
                
            if (i != min_index) {
                exchange.push_back(std::make_pair(i, min_index));
                std::swap(H[i], H[min_index]);
                shift_down(min_index);
                counter++;
            }
        }
        
        void buid_heap() {
            for (int i = (int)floor((size - 2) / 2); i >= 0; --i) {
                shift_down(i);
            }
            std::cout << counter << std::endl;
            for (int j = 0; j < exchange.size(); ++j) {
                std::cout << exchange[j].first << ' ' << exchange[j].second << std::endl;
            }
        }
};

int main()
{
    int n;
    std::cin >> n;
    
    std::vector<int> V;
    for (int i = 0; i < n; ++i) {
        int value;
        std::cin >> value;
        V.push_back(value);
    }
    
    minheap test(n, V);
    test.buid_heap();
    
    return 0;
}
