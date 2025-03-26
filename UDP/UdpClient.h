#ifndef UDP_CLIENT
#define UDP_CLIENT

#define PORT 8080 
#define BUFFER_SIZE 1024

#include <bits/stdc++.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h>

class UdpClient {
    public:
        explicit UdpClient();
        void initiateComms();
        void closeComms();

    private:
        bool sendData = false;
        int socketFileDescriptor;
        char dataBuffer[BUFFER_SIZE];
        struct sockaddr_in serverAddress, clientAddress;
        const char* message = "hello";
        int messageLength;
        socklen_t length; 
};

#endif