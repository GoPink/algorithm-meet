def cut(n,m):
	if n == 1 and m == 1:
		return 0
	if n >= m:
		return cut(n-int(n/2),m)+cut(int(n/2),m)+1
	else:
		return cut(n,m-int(m/2))+cut(n,int(m/2))+1

def run():
	n,m = map(int,input().split())
	print(cut(n,m))

def test():
	print(cut(2,2)==3)
	print(cut(1,1)==0)
	print(cut(2,3)==5)

run()
# test()