#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>
#include <unistd.h> // for close


int main() {
    // open a file to serve
    FILE *html_data = fopen("index.html", "r");
    
    char response_data[1024];
    fgets(response_data, 1024, html_data);
    
    char http_header [2048] = "HTTP/1.1 200 OK\r\n\n";
    strcat(http_header, response_data);
    
    // create a socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    // define the server address;
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8001);
    server_address.sin_addr.s_addr = INADDR_ANY;
    
    // Bind the server socket with the server_adress
    bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address));
    
    // listen for connections
    listen(server_socket, 5);
    
    // Start accepting connections from the client and respond to them
    int client_socket;
    while (1)
    {
        client_socket = accept(server_socket, NULL, NULL);
        send(client_socket, http_header, sizeof(http_header), 0);
        close(client_socket);
    }
    
    return 0;
}