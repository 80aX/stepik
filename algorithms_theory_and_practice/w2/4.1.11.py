# Задача на программирование: различные слагаемые

# По данному числу 1≤n≤10^9 найдите максимальное число kk, для которого nn можно представить 
# как сумму kk различных натуральных слагаемых. Выведите в первой строке число kk, во второй — 
# kk слагаемых.

# Sample Input 1:
# 4

# Sample Output 1:
# 2
# 1 3 

# Sample Input 2:
# 6

# Sample Output 2:
# 3
# 1 2 3 


def various_summands(n):
    k = []
    crnt = n
    if n == 1 or n == 2:
        print(n)
        print(n)
    else:
        for i in range(1, n):
            k.append(i)
            crnt -= i
            if (crnt - (i + 1) <= i + 1):
                k.append(crnt)
                break
        print(len(k))
        for j in k:
            print(j, end = ' ')


def main():
    n = int(input())
    various_summands(n)


if __name__ == "__main__":
    main()
