# 1. 巩固了dfs的用法
# 2. 学习了真二维数组的两种创建方法
#   （1）. list = [ [0] * m for i in range(n)]
#   （2）. 别人的方法：读入同时创建：a = [list(map(f, input().split()) for i in range(n)]
#   （3）. 引入numpy模块，使用array而不是list
# 3. 不知道为啥在oj上RE（想到的错误情况都考虑到了）
dir = [[1, 0], [0, 1], [-1, 0], [0, -1]]
n, m = input().split()
n, m = int(n), int(m)
array = [[0] * (m+2) for i in range(n+2)]

for i in range(1, n+1):
    array[i] = [0] + [int(j) for j in input()] + [0]

def dfs(y, x, array):
    # print("y = %d, x = %d" % (y, x))
    if(array[y][x] == 0):
        return
    array[y][x] = 0
    for i, j in dir:
        if(array[y + i][x + j] != 0):
            dfs(y + i, x + j, array)


sum = 0
for i in range(1, n+1):
    for j in range(1, m+1):
        if(array[i][j] != 0):
            dfs(i, j, array)
            sum += 1
print(sum)