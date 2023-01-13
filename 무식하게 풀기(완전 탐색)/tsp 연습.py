def tsp(num_of_vil, bridges, left_vil, cur_pos = 0, path = [0], length = 0):
	if (left_vil == []):
		_path = list(path)
		_path.append(0)
		_len = int(length)
		_len += bridges[0][cur_pos]
		return (_len, _path)

	
	_path = list(path)
	_path.append(left_vil[0])
	_len = int(length)
	_len += bridges[left_vil[0]][cur_pos]
	_left = list(left_vil)
	del(_left[_left.index(left_vil[0])])

	low_len, low_path = tsp(num_of_vil, bridges, _left, left_vil[0], _path, _len)

	for i in range(len(left_vil) - 1):
		next_vil = left_vil[i + 1]
		_path = list(path)
		_path.append(next_vil)
		_len = int(length)
		_len += bridges[next_vil][cur_pos]
		_left = list(left_vil)
		del(_left[_left.index(next_vil)])

		temp_len, temp_path = tsp(num_of_vil, bridges, _left, next_vil, _path, _len)

		if temp_len < low_len:
			low_len = temp_len
			low_path = temp_path

	return (low_len, low_path)


n = int(input())
bridge = [[] for i in range(n)]

for i in range(n):
	bridge[i] = list(map(int, input().split()))


length, path = tsp(n, bridge, [(i + 1) for i in range(n - 1)])

print("=========답=========")
print(length)
print(path)