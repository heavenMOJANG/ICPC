import time

start = time.time()
number = 0
for i in range(100000000):
    number += i
    
print(f"Ellapsed time: {time.time() - start} s")