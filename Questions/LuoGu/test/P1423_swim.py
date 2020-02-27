n = float(input())
s = 0
rate = 2.0
i = 0
while s <= n:
    s += rate
    rate *= 0.98
    i += 1
print(i)