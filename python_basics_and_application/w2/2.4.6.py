# Вам дана в архиве (ссылка) файловая структура, состоящая из директорий и файлов.

# Вам необходимо распаковать этот архив, и затем найти в данной в файловой структуре все 
# директории, в которых есть хотя бы один файл с расширением ".py". 

# Ответом на данную задачу будет являться файл со списком таких директорий, отсортированных 
# в лексикографическом порядке.


import os
import os.path
l = []


for current_dir, dirs, files in os.walk('main'):
    if list(filter(lambda x: x.endswith('.py'), files)):
        l.append(current_dir)


with open('outt.txt', 'w') as ott:
    for i in sorted(l):
        ott.write(i + '\n')
