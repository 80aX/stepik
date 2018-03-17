// Высота дерева

// Вычислить высоту данного дерева.
// Вход. Корневое дерево с вершинами {0, . . . , n−1}, заданное как последовательность 
// parent 0 , . . . , parent n−1 , где parent i — родитель i-й вершины.
// Выход. Высота дерева.


#include <iostream>
#include <vector>
#include <map>


int tree_height(std::map<int, std::vector<int> >& tree, int r)
{   
    int height = 1;
    for (int c: tree[r]) {
        height = std::max(height, 1 + tree_height(tree, c));
    }
    
    return height;
}


int main() 
{
    // std::vector<std::map<int, std::vector<int> > > graph = {{{-1, {1}}, {1, {3, 4}}, {4, {0, 2}}},
                                                            // {{-1, {0}}, {0, {1, 3}}, {3, {4}}, {4, {2}}}};
                                                            
    // for (int i = 0; i < graph.size(); ++i) {
        // std::map<int, std::vector<int> > inmap = graph[i];
        // int result = tree_height(inmap, inmap[-1][0]);
        // std::cout << result << std::endl;
    // }
    
    int i, n = 0;
    std::cin >> n;
    std::map<int, std::vector<int> > graph;
    
    for (i = 0; i < n; ++i) {
        int v;
        std::cin >> v;
        graph[v].push_back(i);
    }
    
    int result = tree_height(graph, graph[-1][0]);
    std::cout << result << std::endl;
    
    // for (auto it = graph.begin(); it != graph.end(); ++it) {
        // std::cout << it -> first << std::endl;
        // std::vector<int> intvec = it -> second;
        // for (int v = 0; v < intvec.size(); ++v) {
            // std::cout << "chd: " << intvec[v] << std::endl;
        // }
    // }
    
    return 0;
}
