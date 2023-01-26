from sys import stdin; from sys import stdout
def put(): return stdin.readline().replace("\n", "")
def putint(): return int(stdin.readline().replace("\n", ""))
def out(arg): stdout.writelines(str(arg))
def newl(): stdout.writelines("\n")
def mapint(): return map(int, stdin.readline().split())

def reverse_quad_tree(quadTree: str) -> str:
	def cut_quad_tree(quadTree: str) -> tuple:
		abcd = ["", "", "", ""]
		ind = 0
		for i in range(4):
			cnt = 1
			while True:
				if (cnt == 0):
					break
				next = quadTree[ind]
				ind += 1
				if (next == "x"):
					cnt += 3
					abcd[i] += next
				else:
					cnt -= 1
					abcd[i] += next
		a, b, c, d = abcd
		return (a, b, c, d)
	if (len(quadTree) == 1):
		return quadTree

	quadTree = quadTree[1:]
	a, b, c, d = cut_quad_tree(quadTree)

	a = reverse_quad_tree(a)
	b = reverse_quad_tree(b)
	c = reverse_quad_tree(c)
	d = reverse_quad_tree(d)

	return "x" + c + d + a + b

for i in range(putint()):
	quadTree = put()
	out(reverse_quad_tree(quadTree)); newl()