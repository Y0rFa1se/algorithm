#현재 위치에서 바로 다음 블록을 놓을 수 있는 칸
def next_xy(boards, height, width, xco = 0, yco = 0):
	_x, _y = -1, -1
	loop = True
	
	for y in range(height - yco):
		y += yco
		for x in range(width):

			if boards[y][x] == ".":
				_x, _y = x, y
				loop = False
				break

		if not (loop):
			break

	return (_x, _y)


def count_boardCover(boards, height, width, xco, yco):
	cnt = 0

	if ((xco, yco) == (-1, -1)):
		return 1

	if ((yco + 1) != height):
		if (xco != 0):
			if (boards[yco + 1][xco - 1] == "." and boards[yco + 1][xco] == "."): #┘
				boards[yco][xco], boards[yco + 1][xco - 1], boards[yco + 1][xco] = "#", "#", "#"
				_x, _y = next_xy(boards, height, width, xco, yco)
				cnt += count_boardCover(boards, height, width, _x, _y)
				boards[yco][xco], boards[yco + 1][xco - 1], boards[yco + 1][xco] = ".", ".", "."
		if ((xco + 1) != width):
			if (boards[yco][xco + 1] == "." and boards[yco + 1][xco] == "."): #┌
				boards[yco][xco], boards[yco][xco + 1], boards[yco + 1][xco] = "#", "#", "#"
				_x, _y = next_xy(boards, height, width, xco, yco)
				cnt += count_boardCover(boards, height, width, _x, _y)
				boards[yco][xco], boards[yco][xco + 1], boards[yco + 1][xco] = ".", ".", "."
			if (boards[yco + 1][xco] == "." and boards[yco + 1][xco + 1] == "."): #└
				boards[yco][xco], boards[yco + 1][xco], boards[yco + 1][xco + 1] = "#", "#", "#"
				_x, _y = next_xy(boards, height, width, xco, yco)
				cnt += count_boardCover(boards, height, width, _x, _y)
				boards[yco][xco], boards[yco + 1][xco], boards[yco + 1][xco + 1] = ".", ".", "."
			if (boards[yco][xco + 1] == "." and boards[yco + 1][xco + 1] == "."): #┐
				boards[yco][xco], boards[yco][xco + 1], boards[yco + 1][xco + 1] = "#", "#", "#"
				_x, _y = next_xy(boards, height, width, xco, yco)
				cnt += count_boardCover(boards, height, width, _x, _y)
				boards[yco][xco], boards[yco][xco + 1], boards[yco + 1][xco + 1] = ".", ".", "."

	return cnt


for i in range(int(input())):
	h, w = map(int, input().split())
	board = [[] for j in range(h)]

	for k in range(h):
		for l in input():
			board[k].append(l)

	x, y = next_xy(board, h, w)
	print(count_boardCover(board, h, w, x, y))