// Создание демона

// Разработать программу solution, которая при запуске себя "демонизирует" и остается в  памяти. 
// Перед закрытием стандартного потока вывода stdout унаследованного от родителя, программа 
// должна вывести в него Pid процесса-демона.

// Пример вызова

// ./solution
// 13221

// Представление решения

// Решение предоставляется в виде файла solution.c, содержащего исходный код Вашего приложения.

// Вывод

// Программа выводит в стандартный поток вывода число в отдельную строку (вывод должен оканчиваться 
// символом перевода строки \n) перед его закрытием.


#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

// 3.5.6

int daemonize()
{
    int pid;
    
    if (getppid() == 1) return 0; // это уже демон
    
    pid = fork(); // создаем потомка
    if (pid < 0) exit(1);
    else if (pid != 0) exit(0);
    
    // выводим pid демона перед закрытием стандартного потока вывода
    printf ("%d\n", (pid_t) getpid ());
    
    // создаём новый сеанс, чтобы не зависеть от родителя
    setsid();

    // переходим в корень диска.
    chdir("/");

    // закрываем дискрипторы ввода/вывода/ошибок
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
    return 0;
}


int main(int argc, char * argv[]) 
{
    daemonize();
    while (1) sleep(600);
}
