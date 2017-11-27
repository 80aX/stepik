# Вам дана частичная выборка из датасета зафиксированных преступлений, совершенных в городе 
# Чикаго с 2001 года по настоящее время.

# Одним из атрибутов преступления является его тип – Primary Type.

# Вам необходимо узнать тип преступления, которое было зафиксировано максимальное число раз 
# в 2015 году.

# Файл с данными:
# Crimes.csv


import csv


d = {}


with open('crimes.csv', 'r') as inp:
    reader = csv.DictReader(inp)
    for row in reader:
        ddate = row['Date'].split()
        yyear = ddate[0].split('/')
        if yyear[2] == '2015':
            if row['Primary Type'] not in d:
                d[row['Primary Type']] = 0
            else:
                d[row['Primary Type']] += 1


print(max(d, key=d.get))  # Вывод ключа по максимальному значению в словаре
