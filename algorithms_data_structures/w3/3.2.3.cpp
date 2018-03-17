// Поиск образца в тексте

// Найти все вхождения строки Pattern в строку Text.
// Вход. Строки Pattern и Text.
// Выход. Все индексы i строки Text, начиная с которых строка Pattern входит в Text: 
// Text[i..i + |Pattern| − 1] = Pattern.


#include <iostream>
#include <vector>


// Поиск образца в тексте (алгоритм Карпа – Рабина)
class rabinKarpSearch
{
    private:
        std::string pattern;
        std::string text;
        
        int patternlen = 0, textlen = 0;
        long long pattern_hash = 0, text_hash = 0, h = 0;
        std::vector<long long> hash_table;
        
    public:
        rabinKarpSearch(std::string p, std::string t) {
            pattern = p;
            text = t;
            patternlen = p.length();
            textlen = t.length();
        }
        
        long long pow_(int base, int exp, long long p) {
            long long result = 1;
            if (!exp) return 1;
            while (exp) {
                if (exp % 2 == 0) {
                    exp /= 2;
                    base = base % p * base % p;
                } else {
                    exp--;
                    result = result % p * base % p;
                }
            }
            return result % p;
        }
        
        long long hash_(long long prevHash, int pos) {
            int x = 263;
            long long p = 1000000007;
            
            if (h == 0) {
                h = pow_(x, patternlen - 1, p);
            }
            
            if (pattern_hash == 0) {
                for (int i = 0; i < patternlen; ++i) {
                    pattern_hash += (pattern[i] * pow_(x, i, p));
                    pattern_hash %= p;
                }
            }
            
            if (prevHash == 0) {
                for (int i = 0; i < patternlen; ++i) {
                    prevHash += (text[pos++] * pow_(x, i, p));
                    prevHash %= p;
                }
                if (prevHash < 0) {
                    prevHash = (prevHash + p) % p;
                }
                return prevHash;
            } else {
                long long newHash = ((prevHash - text[pos + patternlen] * h) * x + text[pos] * 1) % p;
                if (newHash < 0) {
                    newHash = (newHash + p) % p;
                }
                return newHash;
            }
        }

        void processing() {
            // вариант без проверки посимвольно, только сравнение хеша.
            for (int i = (textlen - patternlen); i >= 0; --i) {
                text_hash = hash_(text_hash, i);
                hash_table.push_back(text_hash);
            }
            
            for (int i = 0, k = (textlen - patternlen); i <= (textlen - patternlen); ++i, --k) {
                if (pattern_hash == hash_table[k]) {
                    std::cout << i << ' ';
                }
            }
            
            // вариант c проверкой посимвольно и сравнение хеша.
            // for (int i = (textlen - patternlen); i >= 0; --i) {
                // text_hash = hash_(text_hash, i);
                // hash_table.push_back(text_hash);
            // }
            
            // for (int i = 0, k = (textlen - patternlen); i <= (textlen - patternlen); ++i, --k) {
                // if (pattern_hash == hash_table[k]) {
                    // for (int j = 0; (j < patternlen) && (pattern[j] == text[i + j]); ++j) {
                        // if (j == (patternlen - 1)) {
                            // std::cout << i << ' ';
                        // }
                    // }
                // }
            // }
        }
};


int main()
{
    std::string p, t;
    std::cin >> p;
    std::cin >> t;
    
    rabinKarpSearch test(p, t);
    test.processing();
    
    return 0;
}
