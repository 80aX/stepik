#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <arpa/inet.h>


struct sockaddr_in local;


int compare(const void * x1, const void * x2) 
{ 
    return (*(char*)x2 - *(char*)x1);
}


int server(int p)
{
    int ss = socket(AF_INET, SOCK_STREAM, 0);
    
    inet_aton("127.0.0.1", &local.sin_addr);
    local.sin_port = htons(p);
    local.sin_family = AF_INET;
    
    bind(ss, (struct sockaddr*) &local, sizeof(local));
    listen(ss, 5);
    
    int cs = accept(ss, NULL, NULL);

    char buf[BUFSIZ];
    
    while (1) {
        for (int i = 0; i < BUFSIZ; i++)
            buf[i] = 0;

        read(cs, buf, BUFSIZ);
        
        if (strncmp(buf, "OFF", 3) == 0) {
            close(cs);
            return 0;
        } else {
            qsort(buf, strlen(buf), 1, compare);
            send(cs, buf, BUFSIZ, 0);
        }
    }
}


int main(int argc, char *argv[]) 
{
    if (argc != 2) {
       printf("Enter arguments!\n");
       return -1;
    }
    
    int p = atoi(argv[1]);
    server(p);
    
    return 0;
}
