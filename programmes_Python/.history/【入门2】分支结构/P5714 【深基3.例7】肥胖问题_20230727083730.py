m, h = map(float,input().split())
bmi = m / ( h ** 2 )
if bmi < 18.5:
    print("Underweight")
elif 18.5 <= bmi < 24:
    print("Normal")
else:
    print("{:.6g}\nOverweight".format(bmi))
