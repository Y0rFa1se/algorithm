switchs = [
	[0, 1, 2],
	[3, 7, 9, 11],
	[4, 10, 14, 15],
	[0, 4, 5, 6, 7],
	[6, 7, 8, 10, 12],
	[0, 2, 14, 15],
	[3, 14, 15],
	[4, 5, 7, 14, 15],
	[1, 2, 3, 4, 5],
	[3, 4, 5, 9, 13]
]

def switch(clock, nos, times) -> list:
	if times == 0:
		return clock

	_clock = list(clock)
	for i in switchs[nos]:
		_clock[i] = (_clock[i] + (3 * times)) % 12

		if (_clock[i] == 0):
			_clock[i] = 12

	return _clock
	

def solve(clock, cnt = 0, nos = 0) -> int:
	if set(clock) == {12}:
		return cnt

	if nos == 10:
		return -1


	ans = []
	for times in range(4):
		_clock = switch(clock, nos, times)
		_cnt = cnt + times
		_nos = nos + 1
		ans.append(solve(_clock, _cnt, _nos))

	_ans = set(ans)
	if (_ans == {-1}):
		return -1
	
	else:
		_ans.discard(-1)
		_ans = list(_ans)
		min = _ans[0]
		for i in range(len(_ans) - 1):
			++i
			if min > _ans[i]:
				min = _ans[i]

		return min


for i in range(int(input())):
	clocks = list(map(int, input().split()))

	print(solve(clocks))