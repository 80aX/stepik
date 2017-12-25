# Задача на программирование: покрыть отрезки точками

# По данным nn отрезкам необходимо найти множество точек минимального размера, для которого 
# каждый из отрезков содержит хотя бы одну из точек.

# В первой строке дано число 1≤n≤100 отрезков. Каждая из последующих nn строк содержит 
# по два числа 0≤l≤r≤10^9, задающих начало и конец отрезка. Выведите оптимальное число 
# mm точек и сами mm точек. Если таких множеств точек несколько, выведите любое из них.

# Sample Input 1:
# 3
# 1 3
# 2 5
# 3 6

# Sample Output 1:
# 1
# 3 

# Sample Input 2:
# 4
# 4 7
# 1 3
# 2 5
# 5 6

# Sample Output 2:
# 2
# 3 6 


res = []


def s_fnc(m):
    global res
    tmp = m[0]
    for i in range(1, len(m)):
        if m[i][0] <= tmp[1]:
            tmp = [m[i][0], min(tmp[1], m[i][1])]
        else:
            res.append(tmp)
            tmp = m[i]
    res.append(tmp)


def main():
    m = []
    n = int(input())
    for i in range(0, n):
        m.append(list(int(k) for k in input().split()))
    m = sorted(m)
    s_fnc(m)
    print(len(res))
    for i in range(0, len(res)):
        print(res[i][0], end = ' ')


if __name__ == "__main__":
    main()
