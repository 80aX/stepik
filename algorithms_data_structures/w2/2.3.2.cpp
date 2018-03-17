// Параллельная обработка

// По данным n процессорам и m задач определите, для каждой из задач, каким процессором 
// она будет обработана.
// Вход. Число процессоров n и последовательность чисел t0 , . . . , t m−1 , где t i — 
// время, необходимое на обработку i-й задачи.
// Выход. Для каждой задачи определите, какой процессор и в какое время начнёт её 
// обрабатывать, предполагая, что каждая задача поступает на обработку первому освободив 
// шемуся процессору.


#include <iostream>
#include <math.h>
#include <vector>


class parallel_processing
{
    private:
        int n, m, size;
        std::vector<std::pair<long int, int> > H;
        
    public:
        parallel_processing(int n_, int m_) {
            n = n_;
            m = m_;
            size = n_ - 1;
        }
        
        int get_parent(int i) {
            return (int)floor((i - 1) / 2);
        }
        
        int get_left_child(int i) {
            return 2 * i + 1;
        }
        
        int get_right_child(int i) {
            return 2 * i + 2;
        }
        
        void shift_up(int i) {
            while (i > 0 && H[get_parent(i)].first > H[i].first) {
                std::swap(H[get_parent(i)], H[i]);
                i = get_parent(i);
            }
        }
        
        void shift_down(int i) {
            int min_index = i;
            
            int l = get_left_child(i);
            if (l <= size && H[l].first < H[min_index].first) {
                min_index = l;
            } else if (l <= size && H[l].first == H[min_index].first && H[l].second < H[min_index].second) {
                min_index = l;
            }
                
            int r = get_right_child(i);
            if (r <= size && H[r].first < H[min_index].first) {
                min_index = r;
            } else if (r <= size && H[r].first == H[min_index].first && H[r].second < H[min_index].second) {
                min_index = r;
            }
            
            if (i != min_index) {
                std::swap(H[i], H[min_index]);
                shift_down(min_index);
            }
        }
        
        void insert(long int priority, int processor) {
            H.push_back(std::make_pair(priority, processor));
            shift_up(H.size() - 1);
        }
        
        void change_priority(int i, long int new_priority) {
            long int old_priority = H[i].first;
            H[i].first = new_priority + old_priority;
            shift_down(i);
        }
        
        void processing() {
            int i, core;
            long int duration;
            
            for (i = 0, core = 0; core < n && core < m && i < m; ++i) {
                std::cin >> duration;
                
                std::cout << core << ' ' << 0 << std::endl;
                if (duration == 0) {
                    continue;
                }
                insert(duration, core);
                core++;
            }
            
            for (; i < m; ++i) {
                std::cin >> duration;
                
                std::cout << H[0].second << ' ' << H[0].first << std::endl;
                change_priority(0, duration);
            }
        }
};


int main()
{
    int n, m;
    std::cin >> n >> m;
    
    parallel_processing test(n, m);
    test.processing();
    
    return 0;
}
