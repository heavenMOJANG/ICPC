n=int(input())
sum=0.0
if n>400:
    sum+=150*0.4463+250*0.4663+(n-400)*0.5663
elif 150<n<=400:
    sum+=150*0.4463+(n-150)*0.4663
else:
    sum+=n*0.4463
print("{:.1f}".format(sum))