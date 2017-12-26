# Задача на программирование: лестница

# Даны число 1≤n≤10^2 ступенек лестницы и целые числа −10^4≤a1,…,an≤10^4, 
# которыми помечены ступеньки. Найдите максимальную сумму, которую можно получить, идя по 
# лестнице снизу вверх (от нулевой до nn-й ступеньки), каждый раз поднимаясь на одну или две 
# ступеньки.

# Sample Input 1:
# 2
# 1 2

# Sample Output 1:
# 3

# Sample Input 2:
# 2
# 2 -1

# Sample Output 2:
# 1

# Sample Input 3:
# 3
# -1 2 1

# Sample Output 3:
# 3


def ladder(n, stairs):
    # if 1 <= n <= 2:
        # return max(max(stairs), sum(stairs))

    maxvalue = [int(0) for i in range(n)]
    
    for i in range(n):
        if i == 0:
            maxvalue[i] = stairs[i]
        elif i == 1:
            maxvalue[i] = max(maxvalue[i - 1], 0) + stairs[i]
        else:
            maxvalue[i] = max(maxvalue[i - 1], maxvalue[i - 2]) + stairs[i]

    return maxvalue[-1]


def main():
    n = int(input())
    stairs = list(int(i) for i in input().split())
    
    # n = 3
    # stairs = [-1, 2, 1]
    
    # n = 8
    # stairs = [3, 4, 10, 10, 0, -6, -10, 0]
    # 21
    
    # n = 6
    # stairs = [-5, 8, 10, 7, -2, 4] 
    # 29
    
    maxsum = ladder(n, stairs)
    print(maxsum)


if __name__ == "__main__":
    main()
