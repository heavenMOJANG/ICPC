n, q = map(int, input().split())
a = [i + 1 for i in range(n)]
s = 0
for testcase in range(q):
    query = list(map(int, input().split()))
    match query[0]:
        case 1:
            p, x = map(int, query[1:3])
            a[(s + p - 1) % n] = x
        case 2:
            p = query[1]
            print(a[(s + p - 1) % n])
        case 3:
            k = query[1]
            s = (s + k) % n