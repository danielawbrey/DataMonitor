#include "UdpClient.h"

UdpClient::UdpClient() {
    if((socketFileDescriptor = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket creation failed"); 
        exit(EXIT_FAILURE);
    }

    memset(&serverAddress, 0, sizeof(serverAddress));

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(PORT);
}

void UdpClient::initiateComms() {
    sendData = true;
    while(sendData) {
        sendto(socketFileDescriptor, (const char *)message, strlen(message), MSG_CONFIRM, (const struct sockaddr *) &serverAddress, sizeof(serverAddress)); 
        std::cout << "Message sent to server" << std::endl;

        messageLength = recvfrom(socketFileDescriptor, (char *)dataBuffer, BUFFER_SIZE, MSG_WAITALL, (struct sockaddr *) &serverAddress, &length); 
        dataBuffer[messageLength] = '\0'; 
        std::cout << "Message received from server" << std::endl;

        // If condition 
        //   sendData = false;
        //   close(socketFileDescriptor);
    }
}

void UdpClient::closeComms() {
    sendData = false;
    close(socketFileDescriptor);
}