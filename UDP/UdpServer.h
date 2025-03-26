#ifndef UDP_SERVER
#define UDP_SERVER

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

class UdpServer {
    public:
        explicit UdpServer();
        void initiateComms();
        void closeComms();

    private:
        bool sendData = false;
        int socketFileDescriptor;
        char dataBuffer[BUFFER_SIZE];
        struct sockaddr_in serverAddress, clientAddress;
        const char* message = "hello";
        socklen_t length;
};

#endif