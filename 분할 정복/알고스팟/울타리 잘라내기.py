from sys import stdin; from sys import stdout

def put(): return stdin.readline().replace("\n", "")
def putint(): return int(stdin.readline().replace("\n", ""))
def putfloat(): return float(stdin.readline().replace("\n", ""))
def putfor(times: int):
	ret = []
	for i in range(times):
		ret.append(stdin.readline().replace("\n", ""))
	return ret
def putintfor(times: int):
	ret = []
	for i in range(times):
		ret.append(int(stdin.readline().replace("\n", "")))
	return ret
def putfloatfor(times: int):
	ret = []
	for i in range(times):
		ret.append(float(stdin.readline().replace("\n", "")))
	return ret
def mapint(arg: str = " "): return map(int, stdin.readline().split(arg))
def mapfloat(arg: str = " "): return map(float, stdin.readline().split(arg))
def mapintfor(times: int, arg: str = " "):
	ret = []
	for i in range(times):
		_ = stdin.readline().replace("\n", "")
		if len(_) == 1:
			ret.append(int(_))
		else:
			ret.append(map(int, _.split(arg)))
	return ret
def mapfloatfor(times: int, arg: str = " "):
	ret = []
	for i in range(times):
		_ = stdin.readline().replace("\n", "")
		if len(_) == 1:
			ret.append(int(_))
		else:
			ret.append(map(float, _.split(arg)))
	return ret
def out(arg): stdout.writelines(str(arg))
def newl(): stdout.writelines("\n")


def exhaustive_search(fences):
	def Contiguous(fences, loc, nof, hei):
		cnt = 0
		ind = loc
		while (True):
			if (ind == -1):
				break

			if (fences[ind] >= hei):
				cnt += 1
				ind -= 1

			else:
				break

		ind = loc + 1
		while (True):
			if (ind == nof):
				break

			if (fences[ind] >= hei):
				cnt += 1
				ind += 1

			else:
				break
			
		return hei * cnt
	nof = len(fences)
	for j in range(nof):
		hei = fences[j]
		if j != 0:
			if (last != hei):
				max_square = max(Contiguous(fences, j, nof, hei), max_square)

		else:
			last = 0
			max_square = Contiguous(fences, j, nof, hei)
	return max_square

def divide_and_conquer(fences):
	def contiguous(fences, loc, nof):
		h = min(fences[loc], fences[loc + 1])
		cnt = 2
		ind = loc - 1
		while True:
			if (ind == -1):
				break
			if (fences[ind] >= h):
				cnt += 1
				ind -= 1
			else:
				break
		ind = loc + 2
		while True:
			if (ind == nof):
				break
			if (fences[ind] >= h):
				cnt += 1
				ind += 1
			else:
				break
		return h * cnt
	def _divede_and_conquer(fences, length):
		if (length == 1):
			return fences[0]

		half = length // 2
		ls = fences[:half]; rs = fences[half:]
		a, b, c = _divede_and_conquer(ls, half), _divede_and_conquer(rs, length - half), contiguous(fences, half - 1, length)
		return max(a, b, c)
	return _divede_and_conquer(fences, len(fences))


for i in range(putint()):
	put()
	fences = list(mapint())
	# out(exhaustive_search(fences)); newl()
	out(divide_and_conquer(fences)); newl()