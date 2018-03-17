// Системы непересекающихся множеств
// Объединение таблиц

// Ваша цель в данной задаче — реализовать симуляцию объединения таблиц в базе данных.
// В базе данных есть n таблиц, пронумерованных от 1 до n, над одним и тем же множеством 
// столбцов (атрибутов). Каждая таблица содержит либо реальные записи в таблице, либо 
// символьную ссылку на другую таблицу. Изначально все таблицы содержат реальные записи, 
// и i-я таблица содержит r i записей. Ваша цель — обработать m запросов типа (destination i,
// source i ):


#include <iostream>
#include <vector>


class disjointset
{
    private:
        int n, m;
        int current_max;
        std::vector<int> rank;
        std::vector<int> parent;
        
    public:
        disjointset(int n_, int m_, int current_max_, std::vector<int> rank_) {
            n = n_;
            m = m_;
            rank.swap(rank_);
            current_max = current_max_;
            parent.resize(n);
        }
        
        void makeset(int i) {
            parent[i] = i;
            // rank[i] = 0;
        }
        
        int find(int i) {
            if (i != parent[i]) {
                parent[i] = find(parent[i]);
            }
            return parent[i];
            
            // while (i != parent[i]) {
                // i = parent[i];
            // }
            // return i;
        }
        
        void union1(int i, int j) {
            int i_id = find(i);
            int j_id = find(j);
            
            if (i_id == j_id) {
                std::cout << current_max << std::endl;
                return;
            }
            
            parent[j_id] = i_id;
            rank[i_id] += rank[j_id];
            if (rank[i_id] > current_max) {
                current_max = rank[i_id];
            }
            std::cout << current_max << std::endl;
            
            // if (rank[i_id] > rank[j_id]) {
                // parent[j_id] = i_id;
            // } else {
                // parent[i_id] = j_id;
                // if (rank[i_id] == rank[j_id]) {
                    // rank[j_id] += 1;
                // }
            // }
        }
        
        void processing() {
            for (int i = 0; i < n; ++i) {
                makeset(i);
            }
            
            for (int i = 0; i < m; ++i) {
                int destination, source;
                std::cin >> destination >> source;
                
                union1(destination - 1, source - 1);
            }
        }
};


int main()
{
    int n, m;
    std::cin >> n >> m;
    
    int max_value = 0;
    std::vector<int> input;
    for (int i = 0; i < n; ++i) {
        int value;
        std::cin >> value;
        input.push_back(value);
        if (value > max_value) {
            max_value = value;
        }
    }
    
    disjointset test(n, m, max_value, input);
    
    test.processing();
    
    return 0;
}
