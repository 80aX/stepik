// "Правильный" демон

// В задании требуется доработать демон, разработанный ранее в задании 6 модуля 3.5. 
// Задача -- снабдить демон обработчиком сигнала SIGURG, по приходу которого демон должен 
// завершать свою работу.

// Пример вызова

// ./solution
// 13336

// Представление решения

// Решение предоставляется в виде двух файлов solution.c и Makefile, в последнем предполагается 
// цель по умолчанию, которая приводит к сборке Вашего приложения. Бинарный файл вашего решения
// должен иметь имя solution.

// Вывод

// Программа выводит в стандартный поток PID созданного демона. (Строка завершается символом 
// конца строки)


#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>


void hndlr(int sig)
{
    exit(0);
}

int daemonize()
{
    int pid;
    
    if (getppid() == 1) return 0;
    
    // создаем потомка
    pid = fork();
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
    
    signal(SIGURG, hndlr);
    return 0;
}


int main(int argc, char * argv[]) 
{
    daemonize();
    while (1) sleep(600);
}
