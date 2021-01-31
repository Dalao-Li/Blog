import time

def decorator(func):
    def wrapper(*args, **kwargs):
        start_time = time.time()
        func()
        end_time = time.time()
        print(end_time - start_time)
    return wrapper


@decorator
def func():
    num = 0
    for i in range(1234356):
        num += i
    print(num)


if __name__ == "__main__":
    func()
