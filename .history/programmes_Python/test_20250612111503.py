w, h, v = map(int, input().split())
for i in range(w):
    for j in range(h):
        print('Q', end = '')
    print()
for i in range(w + v):
    for j in range(w):
        print('Q', end = '')
    print()