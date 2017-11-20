# Вашей программе на вход подаются две строки s и t, состоящие из строчных латинских букв.

# Выведите одно число – количество вхождений строки t в строку s.

# Sample Input 1:
# abababa
# aba
# Sample Output 1:
# 3

# Sample Input 2:
# abababa
# abc
# Sample Output 2:
# 0

# Sample Input 3:
# abc
# abc
# Sample Output 3:
# 1

# Sample Input 4:
# aaaaa
# a
# Sample Output 4:
# 5


n = 0
s = str(input())
t = str(input())

for i in range(len(s)):
    if s.startswith(t, i):
        n += 1
print(n)
