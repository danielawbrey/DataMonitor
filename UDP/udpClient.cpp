#include <bits/stdc++.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 
   
#define PORT     8080 
#define MAXLINE 1024

int main() {
    int socketFileDescriptor;
    char dataBuffer[MAXLINE];
    struct sockaddr_in serverAddress, clientAddress;

    if((socketFileDescriptor = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        std::cout << "Failed to create socket" << std::endl;
        exit(EXIT_FAILURE);
    }

    memset(&serverAddress, 0, sizeof(serverAddress));

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(PORT);

    if(bind(socketFileDescriptor, (const struct sockaddr*)&serverAddress, sizeof(serverAddress))) {
        std::cout << "Failed to bind to socket" << std::endl;
        exit(EXIT_FAILURE);
    }

    socklen_t length = sizeof(clientAddress);

    int n = recvfrom(socketFileDescriptor, (char *)dataBuffer, MAXLINE, MSG_WAITALL, (struct sockaddr*) &clientAddress, &length);
    dataBuffer[n] = '\0';
    std::cout << "Message received from server" << std::endl;

    const char* message = "hello";
    sendto(socketFileDescriptor, message, strlen(message), MSG_CONFIRM, (const struct sockaddr*)&clientAddress, length);
    std::cout << "Message sent to server" << std::endl;

    return 0;
}