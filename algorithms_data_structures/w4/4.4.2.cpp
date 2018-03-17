// Проверка свойства дерева поиска

// Проверить, является ли данное двоичное дерево деревом поиска.
// Вход. Двоичное дерево.
// Выход. Проверить, является ли оно корректным деревом поиска: верно ли, что для любой 
// вершины дерева её ключ больше всех ключей в левом поддереве данной вершины и меньше 
// всех ключей в правом поддереве.


#include <iostream>
#include <vector>
#include <set>


class node
{
    private:
        int key;
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
        
        int get_key() {
            return key;
        }
        
        int set_key(int k) {
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
        bool result = true;
        std::vector<node *> tree_input;
        std::set<int> keys_set;
        
    public:
        bitree(int n_) {
            n = n_;
        }
        
        bool find_key(node *p, int k) {
            if (p == NULL)
                return false;
                
            if (k == p -> get_key())
                return true;
            
            if (k < p -> get_key())
                find_key(p -> get_left_child(), k);
            else
                find_key(p -> get_right_child(), k);
            
        }
        
        bool build() {
            for (int i = 0; i < n; ++i) {
                tree_input.push_back(new node);
            }
            
            for (node *nd : tree_input) {
                int k, l_index, r_index;
                std::cin >> k >> l_index >> r_index;
                
                if (keys_set.find(k) != keys_set.end())
                    result = false;
                
                keys_set.insert(k);
                nd -> set_key(k);
                if (l_index != -1)
                    nd -> set_left_pointer(tree_input[l_index]);
                
                if (r_index != -1)
                    nd -> set_rigth_pointer(tree_input[r_index]);
            }
            
            return result;
        }
        
        bool processing() {
            for (node *nd : tree_input) {
                result = find_key(tree_input[0], nd -> get_key());
                
                if (!result)
                    break;
            }
            
            return result;
        }
        
        void cleaning() {
            for (node *nd : tree_input) {
                delete nd;
            }
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
        
        if (test.build()) {
            if (test.processing()) {
                std::cout << "CORRECT" << std::endl;
                test.cleaning();
                return 0;
            }
        }
        
        test.cleaning();
        std::cout << "INCORRECT" << std::endl;
    }
    
    return 0;
}
