// Обход двоичного дерева

// Построить in-order, pre-order и post-order обходы данного двоичного дерева.
// Вход. Двоичное дерево.
// Выход. Все его вершины в трёх разных порядках: in-order, pre-order и post-order.


#include <iostream>
#include <vector>


// Обход двоичного дерева (Pre-order, In-order, Post-order)
class node
{
    private:
        int key;
        
        node* left_child;
        node* rigth_child;
        
    public:
        node() {
            key = 0;
            left_child = 0;
            rigth_child = 0;
        }
        
        node* get_left_child() {
            return left_child;
        }
        
        node* get_rigth_child() {
            return rigth_child;
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
            rigth_child = p;
        }
};


class bitree
{
    private:
        int n;
        std::vector<node *> v;
        
    public:
        bitree(int n_) {
            n = n_;
        }
        
        void build() {
            for (int i = 0; i < n; ++i) {
                v.push_back(new node);
            }
            
            for (node *nd : v) {
                int k, l_index, r_index;
                std::cin >> k >> l_index >> r_index;
                
                nd -> set_key(k);
                if (l_index != -1)
                    nd -> set_left_pointer(v[l_index]);
                
                if (r_index != -1)
                    nd -> set_rigth_pointer(v[r_index]);
            }
        }
        
        void inorder(node *nd) {
            if (nd == NULL)
                return;
            inorder(nd -> get_left_child());
            std::cout << nd -> get_key() << ' ';
            inorder(nd -> get_rigth_child());
        }
        
        void preorder(node *nd) {
            if (nd == NULL)
                return;
            std::cout << nd -> get_key() << ' ';
            preorder(nd -> get_left_child());
            preorder(nd -> get_rigth_child());
        }
        
        void postorder(node *nd) {
            if (nd == NULL)
                return;
            postorder(nd -> get_left_child());
            postorder(nd -> get_rigth_child());
            std::cout << nd -> get_key() << ' ';
        }
        
        void processing() {            
            inorder(v[0]);
            std::cout << std::endl;
            
            preorder(v[0]);
            std::cout << std::endl;
            
            postorder(v[0]);
            std::cout << std::endl;
            
            for (node *nd : v) {
                delete nd;
            }
        }
};


int main()
{
    int n;
    std::cin >> n;
    
    bitree test(n);
    test.build();
    test.processing();
    
    return 0;
}
