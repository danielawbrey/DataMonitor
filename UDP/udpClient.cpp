#include <bits/stdc++.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 
   
#define PORT 8080 
#define BUFFER_SIZE 1024

int main() {
    int socketFileDescriptor;
    char dataBuffer[BUFFER_SIZE];
    struct sockaddr_in serverAddress, clientAddress;
    const char* message = "hello";

    if((socketFileDescriptor = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket creation failed"); 
        exit(EXIT_FAILURE);
    }

    memset(&serverAddress, 0, sizeof(serverAddress));

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(PORT);

    int messageLength;
    socklen_t length; 
       
    sendto(socketFileDescriptor, (const char *)message, strlen(message), MSG_CONFIRM, (const struct sockaddr *) &serverAddress, sizeof(serverAddress)); 
    std::cout<<"Hello message sent."<<std::endl; 
           
    messageLength = recvfrom(socketFileDescriptor, (char *)dataBuffer, BUFFER_SIZE, MSG_WAITALL, (struct sockaddr *) &serverAddress, &length); 
    dataBuffer[messageLength] = '\0'; 
    std::cout<<"Server: " << dataBuffer << std::endl; 

    close(socketFileDescriptor);

    return 0;
}