// Создание демона

// Разработать программу solution, которая при запуске себя "демонизирует" и остается в  памяти. 
// Перед закрытием стандартного потока вывода stdout унаследованного от родителя, программа должна 
// вывести в него Pid процесса-демона.

// Пример вызова

// ./solution
// 13221

// Представление решения

// Решение предоставляется в виде файла solution.c, содержащего исходный код Вашего приложения.

// Вывод

// Программа выводит в стандартный поток вывода число в отдельную строку (вывод должен оканчиваться 
// символом перевода строки \n) перед его закрытием.


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#define SEGSIZE 1000
#define COUNT 101


int main(int argc, char * argv[]) 
{
    if (argc != 2) {
        printf("Need 2 arguments!\n");
        return 0;
    }
    
    key_t key = ftok(argv[0], 1);
    key_t key_1 = atoi(argv[1]);
    key_t key_2 = atoi(argv[2]);
    
    int shmid, shmid1, shmid2;
    int *result, *arr_shmaddr1, *arr_shmaddr2;
    
    shmid1 = shmget(key_1, SEGSIZE, 0600);
    arr_shmaddr1 = shmat(shmid1, 0, 0);
    shmid2 = shmget(key_2, SEGSIZE, 0600);
    arr_shmaddr2 = shmat(shmid2, 0, 0);
    
    shmid = shmget(key, SEGSIZE, IPC_CREAT | 0666);
    result = shmat(shmid, 0, 0);

    for (int i = 0; i < COUNT; i++) {
        result[i] = arr_shmaddr1[i] + arr_shmaddr2[i];
    }

    shmdt(result);
    shmdt(arr_shmaddr1);
    shmdt(arr_shmaddr2);
    
    printf("%d\n", key);
    return 0;
}
