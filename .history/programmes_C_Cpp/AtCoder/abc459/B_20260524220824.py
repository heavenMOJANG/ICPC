N = eval(input())
S = list(map(str, input().split()))
C = ""
for Si in S:
    if Si[0] == 'a' or Si[0] == 'b' or Si[0] == 'c':
        C += '2'
    if Si[0] == 'd' or Si[0] == 'e' or Si[0] == 'f':
        C += '3'
    if Si[0] == 'g' or Si[0] == 'h' or Si[0] == 'i':
        C += '4'
    if Si[0] == 'j' or Si[0] == 'k' or Si[0] == 'l':
        C += '5'
    if Si[0] == 'm' or Si[0] == 'n' or Si[0] == 'o':
        C += '6'
    if Si[0] == 'p' or Si[0] == 'q' or Si[0] == 'r' or Si[0] == 's':
        C += '7'
    if Si[0] == 't' or Si[0] == 'u' or Si[0] == 'v':
        C += '8'
    if Si[0] == 'w' or Si[0] == 'x' or Si[0] == 'y' or Si[0] == 'z':
        C += '9'
print(C)