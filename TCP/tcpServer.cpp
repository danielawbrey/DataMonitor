#include <iostream>
#include <string>
#include <memory>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT    8080 
#define BUFFER_SIZE 1024

int main() {
    int serverFileDescriptor, connectionFileDescriptor;

    struct sockaddr_in serverAddress;
    int opt = 1;
    socklen_t addressLength = sizeof(serverAddress);
    char buffer[BUFFER_SIZE] = {0};

    if ((serverFileDescriptor = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(serverFileDescriptor, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(PORT);

    if(bind(serverFileDescriptor, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) {
        // std::cout << "Failed to bind to socket" << std::endl;
        perror("bind");
        exit(EXIT_FAILURE);
    }

    if(listen(serverFileDescriptor, 3) < 0) {
        // std::cout << "Failed to bind to socket" << std::endl;
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // socklen_t addressLength = sizeof(serverAddress);
    // connectionFileDescriptor = accept(serverFileDescriptor, (struct sockaddr*)&serverAddress, &addressLength);

    if ((connectionFileDescriptor = accept(serverFileDescriptor, (struct sockaddr*)&serverAddress, &addressLength)) < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    ssize_t valread = read(connectionFileDescriptor, buffer, BUFFER_SIZE);
    std::cout << "Received: " << buffer << std::endl;
    send(connectionFileDescriptor, buffer, valread, 0);
    std::cout << "Echo message sent" << std::endl;

    close(connectionFileDescriptor);
    close(serverFileDescriptor);

    return 0;
}