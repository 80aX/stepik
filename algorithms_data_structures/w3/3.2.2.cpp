// Хеширование цепочками

// Хеширование цепочками — один из наиболее популярных методов реализации хеш-таблиц на 
// практике. Ваша цель в данной задаче — реализовать такую схему, используя таблицу с m 
// ячейками и полиномиальной хеш-функцией.


#include <iostream>
#include <unordered_map>
#include <list>


class chainingHash
{
    private:
        int m, n;
        std::unordered_map<int, std::list<std::string> > HT;
        
    public:
        chainingHash(int m_, int n_) {
            m = m_;
            n = n_;
            HT.reserve(m_);
        }
        
        long long pow_(int base, int exp, long long p) {
            if (exp == 0)
                return 1;
                
            long long result = base;
            for (int i = 1; i < exp; ++i) {
                result = result % p * base % p;
            }
            
            return result;
        }
        
        int hash_function(std::string str) {
            int x = 263;
            long long h = 0, p = 1000000007;
            
            for (int i = 0; i < str.length(); ++i) {
                h += (str[i] * pow_(x, i, p));
                h %= p;
            }
            
            return h % m;
        }
        
        void add_(std::string str) {
            int key = hash_function(str);
            
            if (HT.find(key) != HT.end()) {
                if (!HT[key].empty()) {
                    for (std::string s : HT[key]) {
                        if (s == str) {
                            return;
                        }
                    }
                }
            }
            HT[key].push_front(str);
        }
        
        void del_(std::string str) {
            int key = hash_function(str);
            
            if (HT.find(key) != HT.end()) {
                if (!HT[key].empty()) {
                    HT[key].remove(str);
                }
            }
        }
        
        void find_(std::string str) {
            int key = hash_function(str);
            
            if (HT.find(key) != HT.end()) {
                if (!HT[key].empty()) {
                    for (auto &it : HT[key]) {
                        if (it == str) {
                            std::cout << "yes" << std::endl;
                            return;
                        }
                    }
                }
            }
            std::cout << "no" << std::endl;
        }
        
        void check_(int i) {
            if (HT.find(i) != HT.end()) {
                if (!HT[i].empty()) {
                    for (auto &it : HT[i]) {
                        std::cout << it << ' ';
                    }
                }
            }
            std::cout << std::endl;
        }
        
        void processing() {
            for (int k = 0; k < n; ++k) {
                std::string cmd;
                std::cin >> cmd;
                
                if (cmd == "add") {
                    std::string str;
                    std::cin >> str;
                    add_(str);
                } else if (cmd == "del") {
                    std::string str;
                    std::cin >> str;
                    del_(str);
                } else if (cmd == "find") {
                    std::string str;
                    std::cin >> str;
                    find_(str);
                } else if (cmd == "check") {
                    int i;
                    std::cin >> i;
                    check_(i);
                }
            }
        }
};


int main()
{
    int m, n;
    std::cin >> m;
    std::cin >> n;
    
    chainingHash test(m, n);
    test.processing();
    
    return 0;
}
