# 失败：只尝试使用sorted，发现并没有这么灵活
# 这里必须判断"32">"321", 而key是基于元素，而不是比较结果（不像qsort()），导致s1+s2>s2+s1无法使用（也许还有我不知道的方法）
n = int(input())
l = input().split()
l = sorted(l, key = lambda x: (x, -len(x)), reverse = True)
print(l)
sum = ""
for s in l:
    sum += s
print(sum)