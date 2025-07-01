w, h, v = map(int, input().split())
for i in range(h):
    for j in range(w):
        print('Q', end = '')
    print()
for i in range(w):
    for j in range(w + v):
        print('Q', end = '')
    print()