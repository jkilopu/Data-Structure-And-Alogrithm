# 生成素数！
def _odd_iter():
    n = 1
    while True:
        n = n + 2
        yield n


def _not_divisible(n):
    return lambda x: x % n > 0


def primes(n):
    yield 2
    it = _odd_iter()  # 初始序列
    i = 3
    while i < n:
        i = next(it)  # 返回序列的第一个数
        yield i
        it = filter(_not_divisible(i), it)  # 构造新序列


def verify_goldbach(odd, prime_l):
    for i in prime_l:
        for j in prime_l:
            for k in prime_l:
                if(i + j + k == odd):
                    print(i, j, k)
                    return

n = int(input())
l = list(primes(n))
verify_goldbach(n, l)