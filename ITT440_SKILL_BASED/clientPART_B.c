#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {
  int clientSocket;
  struct sockaddr_in server_addr;
  int sinSize;
  int randomNumber;

  // Create a socket
  clientSocket = socket(AF_INET, SOCK_STREAM, 0);
  if (clientSocket < 0) {
    perror("Socket Creation Error");
    exit(1);
  }

  // Connect to the server
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(8080);
  server_addr.sin_addr.s_addr = INADDR_ANY;
  sinSize = sizeof(server_addr);
  if (connect(clientSocket, (struct sockaddr *)&server_addr, sinSize) < 0) {
    perror("Server Connection Error");
    exit(1);
  }

  // Receive random number from server
  recv(clientSocket, &randomNumber, sizeof(randomNumber), 0);

  // Print random num
  printf("Random number generated: %d\n", randomNumber);

  //Close socket
  close(clientSocket);

  return 0;
}
