// Подсчет процессов в поддереве

// Разработать программу solution, которая по заданному pid, осуществляет поиск всех потомков 
// процесса с этим идентификатором и выводит их количество (включая процесс с заданным pid).

// Пример вызова


// ./solution 1233
// 76


// Представление решения

// Решение предоставляется в виде файла solution.c, содержащего исходный код Вашего приложения.

// Вывод

// Программа выводит в стандартный поток вывода число в отдельной строке( число должно оканчиваться 
// символом перевода строки \n)


#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <ctype.h>


int rec_searching(long int rec_pid)
{
    long int ppid;
    char path[0x100];
    FILE *f;
    
    sprintf(path, "/proc/%ld/stat", rec_pid);
    f = fopen(path, "r");
    fscanf(f, "%*d %*s %*c %ld", &ppid);
    
    fclose(f);
    return ppid;
}


long int child_count(long int main_pid)
{
    DIR *d = opendir("/proc");
    struct dirent *entry;
    long int count = 0, temp_count = 0, temp_pid = 0;
    
    
    while ((entry = readdir(d)) != NULL) {
        if (!isdigit(*entry -> d_name))
            continue;
        
        temp_pid = atoi(entry -> d_name);
        if (temp_pid > main_pid) {
            while (temp_pid > main_pid) {
                temp_pid = rec_searching(temp_pid);
                temp_count++;
                if (temp_pid == main_pid) {
                    count += temp_count;
                    break;
                }
            temp_count = 0;
            }
        }
    }
    
    closedir(d);
    return count + 1;
}


int main(int argc, char * argv[]) 
{
    if (argc <= 1) {
        printf("Enter arguments!\n");
        return 1;
    }
    
    long int parent_pid = atoi(argv[1]);
    
    printf("%ld\n", child_count(parent_pid));

    return 0;
}
