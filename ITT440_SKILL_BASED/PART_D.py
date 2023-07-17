import threading

class FibonacciThread(threading.Thread):
    def __init__(self):
        super().__init__()

    def run(self):
        for s in range(1, 10001):
            print(f"Fibonacci number for number {s}: {fibonacci(s)}")

def fibonacci(nombor):
    if nombor == 0:
        return 0
    elif nombor == 1:
        return 1
    else:
        return fibonacci(nombor - 1) + fibonacci(nombor - 2)

class SquareThread(threading.Thread):
    def __init__(self):
        super().__init__()

    def run(self):
        for t in range(1, 10001):
            print(f"Square number for number {t}: {t ** 2}")

class CubeThread(threading.Thread):
    def __init__(self):
        super().__init__()

    def run(self):
        for u in range(1, 10001):
            print(f"Cube number for number {u}: {u ** 3}")

def main():
    fibonacci_thread = FibonacciThread()
    square_thread = SquareThread()
    cube_thread = CubeThread()

    fibonacci_thread.start()
    square_thread.start()
    cube_thread.start()

    fibonacci_thread.join()
    square_thread.join()
    cube_thread.join()

if __name__ == "__main__":
    main()
