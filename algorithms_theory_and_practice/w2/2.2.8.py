# Задача на программирование повышенной сложности: огромное число Фибоначчи по модулю

# Даны целые числа 1≤n≤10^18 и 2≤m≤10^5, необходимо найти остаток от деления 
# n-го числа Фибоначчи на mm.

# Sample Input:
# 10 2

# Sample Output:
# 1


def fib_mod(n, m):
    last_mod = 1
    cur_mod = 0
    count = 0
    p = [0]
    while count < n:
        cur_mod_tmp = cur_mod
        cur_mod = (last_mod + cur_mod) % m
        last_mod = cur_mod_tmp
        p.append(cur_mod)
        count += 1
        if count > 2 and cur_mod == 1 and last_mod == 0:
            p = p[:-2]
            break
    return p[n % len(p)]


def main():
    n, m = map(int, input().split())
    print(fib_mod(n, m))


if __name__ == "__main__":
    main()

