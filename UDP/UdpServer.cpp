#include "UdpServer.h"

UdpServer::UdpServer() {    
    if ((socketFileDescriptor = socket(AF_INET, SOCK_DGRAM, 0)) < 0) { 
        perror("socket creation failed"); 
        exit(EXIT_FAILURE); 
    } 
       
    memset(&serverAddress, 0, sizeof(serverAddress)); 
    memset(&clientAddress, 0, sizeof(clientAddress)); 
    
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY; 
    serverAddress.sin_port = htons(PORT); 

    if ( bind(socketFileDescriptor, (const struct sockaddr *)&serverAddress, sizeof(serverAddress)) < 0 ) 
    { 
        perror("bind failed"); 
        exit(EXIT_FAILURE); 
    } 

    length = sizeof(clientAddress);
}

void UdpServer::initiateComms() {
    sendData = true;
    while(sendData) {
        int n = recvfrom(socketFileDescriptor, (char *)dataBuffer, BUFFER_SIZE, MSG_WAITALL, (struct sockaddr*) &clientAddress, &length);
        dataBuffer[n] = '\0';
        std::cout << "Message received from client" << std::endl;

        sendto(socketFileDescriptor, message, strlen(message), MSG_CONFIRM, (const struct sockaddr*)&clientAddress, length);
        std::cout << "Message sent to client" << std::endl;

        // If condition
        //   sendData = false;
        //   close(socketFileDescriptor);
    }
}

void UdpServer::closeComms() {
    sendData = false;
    close(socketFileDescriptor);
}