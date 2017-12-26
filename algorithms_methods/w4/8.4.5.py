# Задача на программирование: рюкзак

# Первая строка входа содержит целые числа 1≤W≤10^4 и 1≤n≤300 — вместимость 
# рюкзака и число золотых слитков. Следующая строка содержит nn целых чисел 0≤w1,…,wn≤10^5, 
# задающих веса слитков. Найдите максимальный вес золота, который можно унести в рюкзаке.

# Sample Input:
# 10 3
# 1 4 8

# Sample Output:
# 9


def KnapsackWithoutRespBU(w, n, weights):
    if w == 0 or n == 0:
        return 0

    d = [[0 for j in range(w + 1)] for i in range(n + 1)]
    
    for i in range(1, n + 1):
        for j in range(1, w + 1):
            d[i][j] = d[i - 1][j]
            if weights[i - 1] <= j:
                d[i][j] = max(d[i][j], d[i - 1][j - weights[i - 1]] + weights[i - 1])
    
    return d[n][w]


def main():
    w, n = map(int, input().split())
    weights = list(int(i) for i in input().split())
    
    # w, n = 10, 3
    # weights = [1, 4, 8]
    
    print(KnapsackWithoutRespBU(w, n, weights))


if __name__ == "__main__":
    main()
