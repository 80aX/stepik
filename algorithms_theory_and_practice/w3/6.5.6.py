# Задача на программирование: точки и отрезки

# В первой строке задано два целых числа 1≤n≤50000 и 1≤m≤50000 — 
# количество отрезков и точек на прямой, соответственно. Следующие nn строк содержат 
# по два целых числа ai и bi (ai≤bi) — координаты концов отрезков. Последняя 
# строка содержит mm целых чисел — координаты точек. Все координаты не превышают 10^8 
# по модулю. Точка считается принадлежащей отрезку, если она находится внутри него или на 
# границе. Для каждой точки в порядке появления во вводе выведите, скольким отрезкам она 
# принадлежит.

# Sample Input:
# 2 3
# 0 5
# 7 10
# 1 6 11

# Sample Output:
# 1 0 0


def belog_segment(segments, points):
    d = {}
    mass_points = []
    
    for seg in segments:
        mass_points.append({"num": 0, "val": seg[0]})
        mass_points.append({"num": 2, "val": seg[1]})
    
    for index, point in enumerate(points):
        mass_points.append({"num": 1, "val": point, "index": index})
    mass_points.sort(key=lambda point: (point["val"], point["num"]))
    inters = 0
    
    for point in mass_points:
        if point["num"] == 1:
            d[point["index"]] = inters
        elif point["num"] == 0:
            inters += 1
        elif point["num"] == 2:
            inters -= 1
    
    return d


def main():
    n, m = map(int, input().split())
    segments = []
    
    for i in range(n):
        segments.append(list(map(int, input().split())))
    points = [int(i) for i in input().split()]
    
    # segments = [[0, 5], [7, 10]]
    # points = [1, 6, 11]
    
    points_numbers = belog_segment(segments, points)
    
    print(' '.join([str(points_numbers[index]) for index, point in enumerate(points)]))


if __name__ == "__main__":
    main()
