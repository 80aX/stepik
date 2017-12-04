#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <arpa/inet.h>

struct sockaddr_in local;

int server()
{
    int ss = socket(AF_INET, SOCK_STREAM, 0);
    
    inet_aton("127.0.0.1", &local.sin_addr);
    local.sin_port = htons(1234);
    local.sin_family = AF_INET;
    
    bind(ss, (struct sockaddr*) &local, sizeof(local));
    // начинаем слушать входящие пакеты сокета ss
    listen(ss, 5);
    
    // принимаем соединение(возвращает новый сокет от клиента)
    int cs = accept(ss, NULL, NULL);

    char buf[BUFSIZ];
    // читаем из cs и печатаем на экран
    read(cs, buf, BUFSIZ);
    printf("%s\n", buf);
    close(cs);
}


int client()
{
    int s = socket(AF_INET, SOCK_STREAM, 0);

    inet_aton("127.0.0.1", &local.sin_addr);
    local.sin_port = htons(1234);
    local.sin_family = AF_INET;
    
    connect(s, (struct sockaddr*) &local, sizeof(local));
    
    char buf[BUFSIZ] = "Hello\n";
    write(s, buf, strlen(buf) + 1);
    close(s);
}


int main(int argc, char **argv)
{
    if (argc != 2) {
       printf("Use: [s|c]\n");
       return -1;
    }

    struct sockaddr_in local;

    if (argv[1][0] == 's')
        server();
    if (argv[1][0] == 'c')
        client();
    
    return 0;
}
