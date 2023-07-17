import socket

def isPrime(nombor):
    if nombor < 2:
        return False
    for s in range(2, int(nombor**0.5) + 1):
        if nombor % s == 0:
            return False
    return True

def handleRequest(client_socket):
    data = client_socket.recv(1024).decode()
    num = int(data)
    if isPrime(num):
        response = "It is a Prime number"
    else:
        response = "It is Not a Prime number"
    client_socket.send(response.encode())

def runServer():
    host = "127.0.0.1"
    port = 5000
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    server_socket.bind((host, port))
    print("Server listening on port", port)
    while True:
        client_socket, address = server_socket.recvfrom(1024)
        print("Received request from", address)
        handleRequest(client_socket)

if __name__ == "__main__":
    runServer()
