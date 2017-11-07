n, k = map(int, input().split())

def cn(n, k):
    if k == 0:
        return 1
    elif n == 0 or k > n:
        return 0
    else:
        return cn(n - 1, k) + cn(n - 1, k - 1)

y = cn(n, k)
print(y)
