#include <arpa/inet.h>
#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    
    int fd_server;
    int bind_sock;
    int len_addr;
    int listen_sock;
    int new_sock;
    long valread;
    char hello[] = "hey from server";
    
    if (( fd_server = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("cannot create socket");
        return(0);
    }

    struct sockaddr_in address;

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);

    len_addr = sizeof(address);

    if (bind(fd_server, (struct sockaddr *)&address, sizeof(address))<0)
    {
        perror("In bind");
        exit(1);
    }
    if (listen(fd_server, 10) < 0)
    {
        perror("In listen");
        exit(1);
    }
    while(1)
    {
        printf("\n waiting for connection\n");
        if((new_sock = accept(fd_server, (struct sockaddr *) &address, (socklen_t *)&len_addr)) < 0)
        {
            perror("In accept");
            return(0);
        }
        char buffer[30000] = {0};
        valread = read(new_sock, buffer, 30000);
        printf("%s\n", buffer);
        write(new_sock, hello, strlen(hello));

        printf("\n message sent\n");
        close(new_sock);
    }
    
}

 