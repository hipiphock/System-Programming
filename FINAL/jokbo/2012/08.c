#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main()
{
    int server_sockfd, client_sockfd;
    int server_len, client_len;
    char string[256];
    struct sockaddr_in server_address;
    struct sockaddr_in client_address;
    server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(9734);
    server_len = sizeof(server_address);
    bind(server_sockfd, (struct sockaddr*)&server_address, server_len);
    listen(server_sockfd, 5);
    while(1){
        printf("server waiting\n");
        client_sockfd = accept(server_sockfd, (struct sockaddr*)&client_address, &client_len);
        while(1){
            read(client_sockfd, string, 256);
            printf("from client = %s\n", string);
            write(client_sockfd, string, 256);
        }
    }
    return 0;
}
