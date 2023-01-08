# n과 m이 주어질 때 차례대로 정렬된 n 미만의 m 개의 수 나열을 전부 출력하는 문제 (0, ..., m-1) ~ (n - m - 2, ..., n-1)
# ex) 7, 4 -> (0, 1, 2, 3) ~ (3, 4, 5, 6)

#재귀 함수
def combination(n, comb):
	#종료 조건
	if comb[-1] != 0:
		print(comb)
		return

	#0이 아닌 마지막 인덱스
	ind = 0
	for i in range(len(comb)):
		if comb[i] != 0:
			ind = i

	#0이 아닌 수 바로 다음을 (그 수 + 1) ~ (n - 1)까지 대입
	for j in range(comb[ind] + 1, n):
		comb[ind + 1] = j

		#나머지 뒤쪽 칸 0으로 초기화
		for i in range(len(comb) - (ind + 2)):
			comb[len(comb) - i - 1] = 0

		#바꾼 리스트를 전달
		combination(n, comb)


n, m = map(int, input().split())
combs = [0 for i in range(m)]


for i in range(n - m + 1):
	combs = [0 for i in range(m)]
	combs[0] = i

	combination(n, combs)