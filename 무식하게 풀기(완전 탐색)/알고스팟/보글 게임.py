# 5x5 보드 위에서 특정 단어가 있는지를 판별하는 문제
"""
===입력 예제===
URLPM
XPRET
GIAET
XTNZY
XOQRS
6
PRETTY
GIRL
REPEAT
KARA
PANDORA
GIAZAPX
===출력 예제===
PRETTY YES
GIRL YES
REPEAT YES
KARA NO
PANDORA NO
GIAZAPX YES
"""
does_exist = False

def boggle(board, word_left, xco, yco):
	if word_left == "":
		global does_exist
		does_exist = True
		return True

	for x in range(-1, 2):
		for y in range(-1, 2):
			_x, _y = xco + x, yco + y

			if ((_x == -1 or _x == 5) or (_y == -1 or _y == 5)):
				continue

			if (x == 0 and y == 0):
				continue

			if (board[_y][_x] == word_left[0]):
				boggle(board, word_left[1:], _x, _y)

			


_board = [[] for i in range(5)]
for i in range(5):
	for j in input():
		_board[i].append(j)

words = []
for i in range(int(input())):
	words.append(input())

for wo in words:
	does_exist = False
	for x in range(5):
		for y in range(5):
			if _board[y][x] == wo[0]:
				exist = boggle(_board, wo[1:], x, y)

	if does_exist == True:
		print(wo + " Yes")

	else:
		print(wo + " No")


#