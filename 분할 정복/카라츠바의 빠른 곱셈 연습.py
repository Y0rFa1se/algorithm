import time
# 자릿수가 2의 n승 이어야 함 + 두 수의 자릿수가 같아야 함

#카라츠바의 큰 수의 빠른 곱셈 알고리즘
def karatsuba(n: int, m: int) -> int:
	n, m = str(n), str(m)
	n_len = len(n)

	if (n_len <= 10):
		return int(n) * int(m)

	n1_len = n_len // 2
	n1, n2 = int(n[:n1_len]), int(n[n1_len:])
	m1, m2 = int(m[:n1_len]), int(m[n1_len:])

	z1, z2 = karatsuba(n1, m1), karatsuba(n2, m2)
	z3 = karatsuba(n1 + n2, m1 + m2) - z1 -  z2

	return (z1 * (10 ** (n1_len * 2))) + (z3 * (10 ** n1_len)) + z2

#초등수학 곱하기
def multiply(n: int, m: int) -> int:
	n_nums = [int(i) for i in str(n)]
	m_nums = [int(i) for i in str(m)]
	n_nums.reverse(); m_nums.reverse()

	ret = 0
	for n_ind in range(len(n_nums)):
		for m_ind in range(len(m_nums)):
			ret += n_nums[n_ind] * m_nums[m_ind] * (10 ** (n_ind + m_ind))

	return ret


n, m = map(int, input().split("x"))

print()
print("==============카라츠바 알고리즘==============")
start = time.time()
print(karatsuba(n, m))
end = time.time()
print()
print("걸린 시간: " + str(end - start))

print()
print("==============초등수학 알고리즘==============")
start = time.time()
print(multiply(n, m))
end = time.time()
print()
print("걸린 시간: " + str(end - start))