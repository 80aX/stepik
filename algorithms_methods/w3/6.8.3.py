# Задача на программирование: сортировка подсчётом 

# Первая строка содержит число 1≤n≤10^4, вторая — nn натуральных чисел, не превышающих 10. 
# Выведите упорядоченную по неубыванию последовательность этих чисел.

# Sample Input:
# 5
# 2 3 9 2 9

# Sample Output:
# 2 2 3 9 9


def count_sort(n, array):
    M = 11
    sorted_array = [int(0) for i in range(n)]
    entry_count = [int(0) for i in range(M)]

    for j in range(n):
        entry_count[array[j]] += 1
    for i in range(2, M):
        entry_count[i] += entry_count[i - 1]
    for k in range(n - 1, -1, -1):
        sorted_array[entry_count[array[k]] - 1] = array[k]
        entry_count[array[k]] -= 1

    return sorted_array


def main():
    n = int(input())
    array = [int(i) for i in input().split()]
    
    # n = 5
    # array = [2, 3, 9, 2, 9]
    
    sorted_array = count_sort(n, array)
    for i in sorted_array:
        print(i, end=" ")


if __name__ == "__main__":
    main()
