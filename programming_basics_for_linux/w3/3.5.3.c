// Подсчет числа процессов с заданным именем

// Разработать программу solution, которая осуществляет поиск и подсчет числа процессов с 
// именем genenv в системе Linux на которой выполняется программа. 

// Пример вызова

// ./solution
// 13

// Представление решения

// Решение предоставляется в виде файла solution.c, содержащего исходный код Вашего приложения.

// Вывод

// Программа выводит в стандартный поток вывода число в отдельную строку( вывод должен
// оканчиваться на символ перевода строки \n).


#include <stdio.h>
#include <dirent.h>
#include <ctype.h>
#include <string.h>


int main(int argc, char * argv[])
{   
    DIR *d = opendir("/proc");
    struct dirent *entry;
    char path[0x100], pname[0x100];
    int count = 0;
    FILE *f;
    
    while ((entry = readdir(d)) != NULL) {
        if (!isdigit(*entry -> d_name))
            continue;
        
        sprintf(path, "/proc/%s/comm", entry -> d_name);
        f = fopen(path, "r");
        fgets(pname, 7, f);
        
        if (strcmp(pname, "genenv") == 0) {
            count++;
        }
    }
    printf("%i\n", count);
    fclose(f);
    closedir(d);
    return 0;
}
