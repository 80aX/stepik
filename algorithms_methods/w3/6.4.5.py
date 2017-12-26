# Задача на программирование: число инверсий

# Первая строка содержит число 1≤n≤10^5, вторая — массив A[1…n], содержащий 
# натуральные числа, не превосходящие 10^9. Необходимо посчитать число пар индексов 
# 1≤i<j≤n, для которых A[i]>A[j]. (Такая пара элементов называется инверсией 
# массива. Количество инверсий в массиве является в некотором смысле его мерой неупорядоченности: 
# например, в упорядоченном по неубыванию массиве инверсий нет вообще, а в массиве, 
# упорядоченном по убыванию, инверсию образуют каждые два элемента.)

# Sample Input:
# 5
# 2 3 9 2 9

# Sample Output:
# 2


import sys


def merge_sort(array, left_index, right_index):
    middle = (left_index + right_index) // 2
    
    if left_index < right_index:
        sorted_left, inv_left = merge_sort(array, left_index, middle)
        sorted_right, inv_right = merge_sort(array, middle + 1, right_index)
        sorted_final, inv_final = merge(sorted_left, sorted_right)
        return sorted_final, (inv_left + inv_right + inv_final)
    else:
        return [array[middle]], 0


def merge(array_1, array_2):
    new_array = []
    i, j, inversions = 0, 0, 0
    
    while i < len(array_1) and j < len(array_2):
        if array_1[i] <= array_2[j]:
            new_array.append(array_1[i])
            i += 1
        else:
            inversions += len(array_1) - i
            new_array.append(array_2[j])
            j += 1

    new_array += array_1[i:]
    new_array += array_2[j:]
    return new_array, inversions


def main():
    input = sys.stdin.read()
    input = input.split("\n")
    n = int(input.pop(0))
    array = list(map(int, input.pop(0).split()))

    sorted_array, inv = merge_sort(array, 0, len(array) - 1)
    print(inv)


if __name__ == "__main__":
    main()
