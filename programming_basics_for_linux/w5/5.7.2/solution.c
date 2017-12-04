#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <arpa/inet.h>

struct sockaddr_in local;

int main(int argc, char *argv[]) 
{
    if (argc != 2) {
        printf("Enter arguments!\n");
        return -1;
    }
    
    int p = atoi(argv[1]);
    int s = socket(AF_INET, SOCK_DGRAM, 0);
    
    inet_aton("127.0.0.1", &local.sin_addr);
    local.sin_port = htons(p);
    local.sin_family = AF_INET;
    
    int result = bind(s, (struct sockaddr*) &local, sizeof(local));
    
    char buf[BUFSIZ];
    
    while (1) {
        for (int i = 0; i < BUFSIZ; i++)
            buf[i] = 0;
        
        read(s, buf, BUFSIZ);
        if (strncmp(buf, "OFF\n", 4) == 0) {
            return 0;
        } else {
            printf("%s\n", buf);
        }
    }
    
    return 0;
}
