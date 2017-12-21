# Задача на программирование: наибольший общий делитель

# По данным двум числам 1≤a,b≤2⋅10^9 найдите их наибольший общий делитель.

# Sample Input 1:
# 18 35

# Sample Output 1:
# 1

# Sample Input 2:
# 14159572 63967072

# Sample Output 2:
# 4


def evklid_nod(a, b):
    # вычисляем наибольший общий делитель a, b по алгоритму Евклида
    if a == 0 or b == 0:
        return a + b
    elif a >= b:
        return evklid_nod(a % b, b)
    elif b >= a:
        return evklid_nod(a, b % a)


def main():
    a, b = map(int, input().split())
    print(evklid_nod(a, b))


if __name__ == "__main__":
    main()
