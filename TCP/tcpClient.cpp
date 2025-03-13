#include <arpa/inet.h> // inet_addr()
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h> // bzero()
#include <sys/socket.h>
#include <unistd.h>
#include <iostream>

#define PORT    8080 
#define BUFFER_SIZE 80

int main() {
    int socketFileDescriptor;
    struct sockaddr_in serverAddress, clientAddress;
    char buffer[BUFFER_SIZE] = {0};

    if((socketFileDescriptor = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        std::cout << "Failed to create socket" << std::endl;
        exit(EXIT_FAILURE);
    }

    bzero(&serverAddress, sizeof(serverAddress));

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");
    serverAddress.sin_port = htons(PORT);

    if(connect(socketFileDescriptor, (const struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) {
        std::cout << "Failed to connect to socket" << std::endl;
        exit(EXIT_FAILURE);
    }

    std::string hello = "Hello from client";
    send(socketFileDescriptor, hello.c_str(), hello.size(), 0);
    ssize_t valread = read(socketFileDescriptor, buffer, BUFFER_SIZE);
    std::cout << "Received: " << buffer << std::endl;

    close(socketFileDescriptor);

    return 0;
}