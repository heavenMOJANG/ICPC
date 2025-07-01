n, q = map(int, input().split())
a = [i + 1 for i in range(n)]
s = 0
for testcase in range(n):
    query = list(map(int, input().split()))
    match query[0]:
        case 1:
            p, x = map(int, query[1:3])
            a[(s + p) % n] = x