// Проверка более общего свойства дерева поиска

// Данная задача полностью аналогична предыдущей, но проверять теперь нужно более общее
// свойство. Дереву разрешается содержать равные ключи, но они всегда должны находиться
// в правом поддереве. Формально, двоичное дерево называется деревом поиска, если для
// любой вершины её ключ больше всех ключей из её левого поддерева и не меньше всех
// ключей из правого поддерева.


#include <iostream>
#include <vector>
#include <limits>
#define CMIN std::numeric_limits<long long>::min()
#define CMAX std::numeric_limits<long long>::max()


class node
{
    private:
        long long key;
        node* left_child;
        node* right_child;
    
    public:
        node() {
            key = 0;
            left_child = 0;
            right_child = 0;
        }
        
        node* get_left_child() {
            return left_child;
        }
        
        node* get_right_child() {
            return right_child;
        }
        
        long long get_key() {
            return key;
        }
        
        long long set_key(int k) {
            key = k;
        }
        
        void set_left_pointer(node *p) {
            left_child = p;
        }
        
        void set_rigth_pointer(node *p) {
            right_child = p;
        }
};


class bitree
{
    private:
        int n;
        std::vector<node *> tree_input;
        
    public:
        bitree(int n_) {
            n = n_;
        }
        
        void build() {
            for (int i = 0; i < n; ++i)
                tree_input.push_back(new node);
            
            
            for (node *nd : tree_input) {
                long long k;
                int l_index, r_index;
                std::cin >> k >> l_index >> r_index;
                
                nd -> set_key(k);
                if (l_index != -1)
                    nd -> set_left_pointer(tree_input[l_index]);
                
                if (r_index != -1)
                    nd -> set_rigth_pointer(tree_input[r_index]);
            }
        }
        
        bool check_tree(node *p, long long l_key, long long r_key) {
            if (l_key <= p -> get_key() && r_key > p -> get_key() 
            
                && (!p -> get_left_child() || (p -> get_left_child() 
                    && check_tree(p -> get_left_child(), l_key, p -> get_key()))) 
                    
                && (!p -> get_right_child() || (p -> get_right_child() 
                    && check_tree(p -> get_right_child(), p -> get_key(), r_key)))) {
                
                return true;
            }
            return false;
        }
        
        bool processing() {
            return check_tree(tree_input[0], CMIN, CMAX);
        }
        
        void cleaning() {
            for (node *nd : tree_input)
                delete nd;
        }
};


int main()
{
    int n;
    std::cin >> n;
    
    if (n == 0) {
        std::cout << "CORRECT" << std::endl;
    } else {
        bitree test(n);
        test.build();
            
        if (test.processing())
            std::cout << "CORRECT" << std::endl;
        else
            std::cout << "INCORRECT" << std::endl;
        
        test.cleaning();
    }
    
    return 0;
}
