// Мультиплексированный ввод

// В текущем каталоге есть 2 канала in1 in2, в которые в случайном порядке поступают числа, 
// которые необходимо просуммировать и вывести окончательную сумму на экран. Сумма выводится в 
// отдельной строке, завершающейся символом конца строки. Признаком окончания подачи символов в 
// каналы является закрытие этих каналов посылающей стороной.

// Подсказка: для неблокирующего чтения использовать select.
// Замечание: ﻿протокол обмена по каналу текстовый, то есть числа представлены строками
// Пример вызова

// ./solution 
// 795

// Представление решения

// Решение предоставляется в виде двух файлов solution.c и Makefile, в последнем предполагается 
// цель по умолчанию, которая приводит к сборке Вашего приложения. Бинарный файл вашего решения 
// должен иметь имя solution.

// Вывод

// Программа выводит в стандартный поток вывода число (в отдельной строке)


#include <stdio.h>
#include <sys/select.h>
#include <unistd.h>
#include <fcntl.h>

void read_and_report(int fd)
{   
    char buf[100];
    
    printf("FD %d is ready to read\n", fd);
    int bytes = read(fd, buf, 100);
    
    buf[bytes] = 0;
    
    printf("Get %d bytes from %d : %s\n", bytes, fd, buf);
}

int main()
{
    // заводим дескрипторы
    int f1 = open("./f1.fifo", O_RDWR);
    int f2 = open("./f2.fifo", O_RDWR);
    
    if (f1 == -1 || f2 == -1) {
        printf("Error with opening pipes\n");
        return 0;
    }
    
    printf("Descriptors: %d %d\n", f1, f2);
    
    // процедура опроса данных в файловых дескрипторах
    fd_set read_set;
    
    while (true) {
        // обнуляем сет
        FD_ZERO(&read_set);
        // ставим в список наблюдения ф1 ф2
        FD_SET(f1, &read_set);
        FD_SET(f2, &read_set);
        
        // вычисляем колво файлов для наблюдения
        int result = select(f2 + 1, &read_set, NULL, NULL, NULL);
        
        if (result) {
            printf("select returned %d\n", result);
            
            if (FD_ISSET(f1, &read_set))
                read_and_report(f1);
            if (FD_ISSET(f2, &read_set))
                read_and_report(f2);
        }
    }
    return 0;
}
