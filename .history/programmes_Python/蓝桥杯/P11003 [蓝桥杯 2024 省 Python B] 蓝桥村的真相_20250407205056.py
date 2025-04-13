import sys
data = list(map(int, sys.stdin.read().strip().split()))
for x in data[1:]:
    if x % 3 == 0:
        print(2 * x)
    else:
        print(x)