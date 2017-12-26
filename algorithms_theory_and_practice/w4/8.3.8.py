# Задача на программирование: расстояние редактирования

# Вычислите расстояние редактирования двух данных непустых строк длины не более 10^2, 
# содержащих строчные буквы латинского алфавита.

# Sample Input 1:
# ab
# ab

# Sample Output 1:
# 0

# Sample Input 2:
# short
# ports

# Sample Output 2:
# 3


def edit_dist(s1, s2):
    dist_m = [[0 for j in range(len(s2) + 1)] for i in range(len(s1) + 1)]
    
    for i in range(len(s1) + 1):
        dist_m[i][0] = i
    for j in range(len(s2) + 1):
        dist_m[0][j] = j
    for i in range(1, len(s1) + 1):
        for j in range(1, len(s2) + 1):
            if s1[i-1] == s2[j-1]:
                dist_d = 0
            else:
                dist_d = 1
            dist_m[i][j] = min(dist_m[i-1][j] + 1, dist_m[i][j-1] + 1, dist_m[i-1][j-1] + dist_d)
    
    return dist_m[len(s1)][len(s2)]


def main():
    s1 = str(input())
    s2 = str(input())
    
    # s1 = 'short'
    # s2 = 'ports'
    
    print(edit_dist(s1, s2))


if __name__ == "__main__":
    main()
