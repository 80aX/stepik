// Автоматический анализ программ
// При автоматическом анализе программ возникает такая задача.

// Система равенств и неравенств
// Проверить, можно ли присвоить переменным целые значения, чтобы выполнить заданные 
// равенства вида x i = x j и неравенства вида x p 6 = x q.
// Вход. Число переменных n, а также список равенств вида x i = x j и неравенства 
// вида x p 6 = x q. Выход. Проверить, выполнима ли данная система.


#include <iostream>
#include <vector>


class disjointset
{
    private:
        int n, e, d;
        std::vector<int> parent;
        
    public:
        disjointset(int n_, int e_, int d_) {
            n = n_;
            e = e_;
            d = d_;
            parent.resize(n);
        }
        
        void makeset(int i) {
            parent[i] = i;
        }
        
        int find(int i) {
            if (i != parent[i]) {
                parent[i] = find(parent[i]);
            }
            return parent[i];
        }
        
        void union1(int i, int j) {
            int i_id = find(i);
            int j_id = find(j);
            
            if (i_id == j_id) {
                return;
            }
            
            parent[j_id] = i_id;
        }
        
        // void printVector(std::vector<int>& vec)
        // {
            // for (int a : vec) {
                // std::cout << a << " ";
            // }
            // std::cout << std::endl;
        // }
        
        int checkunion1(int i, int j) {
            int i_id = find(i);
            int j_id = find(j);
            
            if (i_id == j_id) {
                return 0;
            }
            
            return 1;
        }
        
        void processing() {
            
            for (int k = 0; k < n; ++k) {
                makeset(k);
            }
            
            for (int k = 0; k < e; ++k) {
                int i, j;
                std::cin >> i >> j;
                
                union1(i - 1, j - 1);
            }
            
            for (int k = 0; k < d; ++k) {
                int i, j, result;
                std::cin >> i >> j;
                result = checkunion1(i - 1, j - 1);
                
                if (result == 0) {
                    std::cout << '0' << std::endl;
                    return;
                }
            }
            
            std::cout << '1' << std::endl;
        }
};


int main()
{
    int n, e, d;
    std::cin >> n >> e >> d;
    
    disjointset test(n, e, d);
    
    test.processing();
    
    return 0;
}
