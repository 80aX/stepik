// Поиск пути к init по заданному pid

// Разработать программу solution, которая по заданному pid, осуществляет поиск пути в дереве 
// процессов до процесса с идентификатором 1 (init). Для каждого найденного процесса печатается 
// в отдельной строке его идентификатор.

// Пример вызова

// ./solution 1766
// 1766
// 1299
// 465
// 1

// Представление решения

// Решение предоставляется в виде файла solution.c, содержащего исходный код Вашего приложения.

// Вывод

// Программа выводит в стандартный поток вывода числа (каждое число в отдельной строке)
// Задача на программирование в Linux — Напишите программу


#include <stdio.h>
#include <stdlib.h> 


int pid_searching(long int pid_number) 
{
    char path[0x100];
    long int ppid;
    
    sprintf(path, "/proc/%ld/stat", pid_number);
    FILE *f = fopen(path, "r");
    fscanf(f, "%*d %*s %*c %ld", &ppid);
    
    return ppid;
}


int main(int argc, char * argv[]) 
{
    if (argc <= 1) {
        printf("Enter arguments!\n");
        return 1;
    }
    
    long int result_pid = atoi(argv[1]);
    
    while (result_pid != 1) {
        printf("%ld\n", result_pid);
        result_pid = pid_searching(result_pid);
    }
    
    printf("%ld\n", result_pid);
    return 0;
}
