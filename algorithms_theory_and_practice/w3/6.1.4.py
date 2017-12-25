Задача на программирование: двоичный поиск

В первой строке даны целое число 1≤n≤10^5 и массив A[1…n] из n различных 
натуральных чисел, не превышающих 10^9, в порядке возрастания, во второй — целое число 
1≤k≤10^5 и kk натуральных чисел b1,…,bk не превышающих 10^9. Для каждого 
i от 1 до k необходимо вывести индекс 1≤j≤n, для которого A[j]=bi, или −1, 
если такого j нет.

Sample Input:
5 1 5 8 12 13
5 8 1 23 1 11

Sample Output:
3 1 -1 1 -1


def binary_searching(a, key):
    left_index = 0
    right_index = (len(a) - 1)
    while left_index <= right_index:
        m = ((left_index + right_index) // 2)
        if a[m] == key:
            return m + 1
        elif a[m] > key:
            right_index = m - 1
        else:
            left_index = m + 1
    return -1


def main():
    len_a, *a = map(int, input().split())
    len_b, *b = map(int, input().split())
    for key in b:
        print(binary_searching(a, key), end=' ')


if __name__ == "__main__":
    main()
