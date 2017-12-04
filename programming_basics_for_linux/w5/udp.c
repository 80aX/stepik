#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <arpa/inet.h>

// заводим структуру под адрес ip сети,
// которая будет олицетворять локальный адрес
struct sockaddr_in local;

int main(int argc, char *argv[])
{
    // создаём сокет с параметрами,
    // AF_INET - для сетей ipv4, SOCK_DGRAM - тип соединения для UDP
    // и последний параметр - протокол в семействе адресов 0 - не требуется
    int s = socket(AF_INET, SOCK_DGRAM, 0);
    // выводим значение сокета
    printf("socket = %d\n", s);
    
    // настраиваем структуру sockaddr_in,
    // преобразовываем адрес локальной машины в бинарную - &local.sin_addr
    inet_aton("127.0.0.1", &local.sin_addr);
    // устанавливаем порт в значение 1234, фукция htons - для преобразования.
    local.sin_port = htons(1234);
    local.sin_family = AF_INET;
    
    // делаем bind, передаём сокет, адрес и размер.
    int result = bind(s, (struct sockaddr*) &local, sizeof(local));
    // выводим результат
    printf("%d\n", result);
    
    char buf[BUFSIZ];
    // пытаемся прочитать из сокета и печатаем на экран
    read(s, buf, 5);
    printf("%s, end\n", buf);
}
