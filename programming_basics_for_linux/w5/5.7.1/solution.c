#include <netdb.h>
#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) 
{
    if (argc != 2) {
        printf("Enter error\n");
        return -1;
    }
    
    struct hostent *h;
    h = gethostbyname(argv[1]);
    
    if (h == NULL) {
        printf("Error get host by name\n");
        return -1;
    }
    
    for (int i = 0; h -> h_addr_list[i] != NULL; i++) {
        struct in_addr *a = (struct in_addr*) h -> h_addr_list[i];
        printf("%s\n", inet_ntoa(*a));
    }
    
    return 0;
}
