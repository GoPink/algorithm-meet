# https://www.acmicpc.net/problem/12798

testSource = \
"""1000 6
1 1 1 500
2 2 3
2 3 4
1 -1 -1 3
2 0 0
2 3 -1"""



def plusValue(x,y,r,combMap,N):
	for i in range(2*r+1):
		for j in range(2*r+1):
			if i-j < r+1 and j-i < r+1:
				combMap[N+y-r+i][N+x-r+j] += 1


# Original ver
def plusValue2(x,y,r,combMap,N):
	from collections import deque
	direct = [[1,1],[1,0],[0,-1],[0,1],[-1,0],[-1,-1]]
	visited = [[]]*(2*N+1)
	for i in range(2*N+1):
		visited[i] = [0]*(2*N+1)
	queue = deque()
	queue.append((N+y,N+x))
	combMap[N+y][N+x] +=1
	visited[N+y][N+x] = 1
	for i in range(r):
		for _ in range(len(queue)):
			py,px = queue.popleft()
			for dx,dy in direct:
				if visited[py+dy][px+dx] == 0:
					visited[py+dy][px+dx] = 1
					combMap[py+dy][px+dx] +=1
					queue.append((py+dy,px+dx))

def findValue(x,y,combMap,N):
	return combMap[N+y][N+x]

def pprint(combMap):
	for i in combMap:
		print(i)
	print()

def testRun(testSource):
	testSource = testSource.split("\n")
	N,Q = map(int,testSource.pop(0).split())
	combMap = [[]]*(2*N+1)
	for i in range(2*N+1):
		combMap[i] = [0]*(2*N+1)
	for _ in range(Q):
		operation = list(map(int,testSource.pop(0).split()))
		typeOfOperation = operation.pop(0)
		if typeOfOperation == 1:
			x,y,r = operation
			plusValue(x,y,r,combMap,N)
			# pprint(combMap)
		if typeOfOperation == 2:
			x,y = operation
			print(findValue(x,y,combMap,N))

def run():
	N,Q = map(int,input().split())
	combMap = [[]]*(2*N+1)
	for i in range(2*N+1):
		combMap[i] = [0]*(2*N+1)
	for _ in range(Q):
		operation = list(map(int,input().split()))
		typeOfOperation = operation.pop(0)
		if typeOfOperation == 1:
			x,y,r = operation
			plusValue(x,y,r,combMap,N)
		if typeOfOperation == 2:
			x,y = operation
			print(findValue(x,y,combMap,N))


testRun(testSource)
# run()