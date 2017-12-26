# Задача на программирование: небольшое число Фибоначчи

# Дано целое число 1≤n≤401≤n≤40, необходимо вычислить nn-е число Фибоначчи (напомним, что 
# F0=0, F1=1 и Fn=Fn−1+Fn−2 при n≥2).

# Sample Input:
# 3

# Sample Output:
# 2


def fib(n):
    f = [0, 1]
    if n <= 1:
        return n
    else:
        for i in range(2, n + 1):
            f.append(f[i - 1] + f[i - 2])
        return f[n]


def main():
    n = int(input())
    print(fib(n))


if __name__ == "__main__":
    main()
