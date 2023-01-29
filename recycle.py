from sys import stdin; from sys import stdout
def put(): return stdin.readline().replace("\n", "")
def putint(): return int(stdin.readline().replace("\n", ""))
def out(arg): stdout.writelines(str(arg))
def newl(): stdout.writelines("\n")
def mapint(): return map(int, stdin.readline().split())