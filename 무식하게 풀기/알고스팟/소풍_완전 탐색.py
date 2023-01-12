import math

def pairs_of_friends(nos, students, friends):
	cnt = 0
	if (students == []):
		return 1

	for no_st1 in range(nos):
		for no_st2 in range(nos - (no_st1 + 1)):
			no_st2 += no_st1 + 1

			if ([students[no_st1], students[no_st2]] in friends):
				_students = list(students)
				del(_students[no_st1])
				del(_students[no_st2 - 1])

				_friends = list(friends)
				del(_friends[_friends.index([students[no_st1], students[no_st2]])])

				cnt += pairs_of_friends(nos - 2, _students, _friends)

	return cnt


for i in range(int(input())):
	studs, _ = map(int, input().split())
	pairs = []
	inp = list(map(int, input().split()))
	for j in range(len(inp) // 2):
		pairs.append([inp[2 * j], inp[(2 * j) + 1]])


	studs_list = [k for k in range(studs)]
	print(pairs_of_friends(studs, studs_list, pairs) // math.factorial(studs // 2))


#[1, 2], [0, 3]과 [0, 3], [2, 1] 을 중복해서 세는 문제를 해결하기 위해 최종 답안을 순서를 바꾸는 경우의 수로 나눔
# -> 해결책: 사전식 정렬로만 체크 p.159
# -> 남아 있는 아이들중 가장 앞선 아이부터 짝을 만들어줌