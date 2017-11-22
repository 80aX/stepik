# Вам дана последовательность строк.
# Выведите строки, содержащие "cat" в качестве подстроки хотя бы два раза.

# Sample Input:
# catcat
# cat and cat
# catac
# cat
# ccaatt

# Sample Output:
# catcat
# cat and cat


import sys
import re

for line in sys.stdin:
    line = line.rstrip()
    if line.count('cat') >= 2:
        print(line)
