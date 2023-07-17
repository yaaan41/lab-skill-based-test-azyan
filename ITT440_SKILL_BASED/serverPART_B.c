#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {
  int serverSocket, clientSocket;
  struct sockaddr_in server_addr, client_addr;
  int sinSize;
  int randomNumber;

  // Create a socket
  serverSocket = socket(AF_INET, SOCK_STREAM, 0);
  if (serverSocket < 0) {
    perror("Error creating socket");
    exit(1);
  }

  // Bind socket to a port
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(8080);
  server_addr.sin_addr.s_addr = INADDR_ANY;
  sinSize = sizeof(server_addr);
  if (bind(serverSocket, (struct sockaddr *)&server_addr, sinSize) < 0) {
    perror("Error binding socket");
    exit(1);
  }

  // Listen for connections
  listen(serverSocket, 5);

  // Accept a connection
  clientSocket = accept(serverSocket, (struct sockaddr *)&client_addr, &sinSize);
  if (clientSocket < 0) {
    perror("Error accepting connection");
    exit(1);
  }

  // Generate a random number
  randomNumber = rand() % 30000 + 50000;

  // Send the random number to the client
  send(clientSocket, &randomNumber, sizeof(randomNumber), 0);

  // Close the sockets
  close(serverSocket);
  close(clientSocket);

  return 0;
}
