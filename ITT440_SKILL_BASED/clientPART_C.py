import socket

def getNumberFromUser():
    num = input("Enter a number: ")
    return int(num)

def sendNumberToServer(server_address, port):
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    client_socket.connect((server_address, port))
    num = getNumberFromUser()
    if not isinstance(num, int):
        print("Invalid data entered by user")
        return
    data = str(num).encode("utf-8")
    port = server_address[1]
    client_socket.sendto(data, server_address, port)

def receiveResponseFromServer(client_socket):
    response = client_socket.recv(1024).decode()
    return response

def main():
    server_address = ("127.0.0.1", 5000)
    port = 5000
    sendNumberToServer(server_address, port)
    response = receiveResponseFromServer()
    print("Response from the server:", response)

if __name__ == "__main__":
    main()
