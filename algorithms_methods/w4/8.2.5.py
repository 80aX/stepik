# Задача на программирование: наибольшая последовательнократная подпоследовательность
# Дано целое число 1≤n≤10^3 и массив A[1…n] натуральных чисел, не превосходящих 
# 2⋅10^9. Выведите максимальное 1≤k≤n, для которого найдётся подпоследовательность 
# 1≤i1<i2<…<ik≤n длины k, в которой каждый элемент делится на предыдущий 
# (формально: для  всех 1≤j<k, A[ij]|A[ij+1]).

# Sample Input:
# 4
# 3 6 7 12

# Sample Output:
# 3


def greatest_subsequence(n, array):
    subs_length = [int(0) for i in range(n)]
    
    for i in range(n):
        subs_length[i] = 1
        for j in range(i):
            if array[i] >= array[j] and array[i] % array[j] == 0 and subs_length[j] + 1 > subs_length[i]:
                subs_length[i] = subs_length[j] + 1
    
    max_sub = max(subs_length)
    return max_sub


def main():
    n = int(input())
    array = [int(i) for i in input().split()]
    
    # n = 4
    # array = [3, 6, 7, 12]
    
    max_sub_length = greatest_subsequence(n, array)
    print(max_sub_length)


if __name__ == "__main__":
    main()
