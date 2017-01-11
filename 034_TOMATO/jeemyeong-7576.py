# https://www.acmicpc.net/problem/7576
def tomatoBfs(m,n,tomatoMap):
	queue = []
	for i in range(n):
		for j in range(m):
			if tomatoMap[i][j] == 1:
				queue.append((i,j))
	if len(queue) == n*m:
		return 0
	visited = []
	for _ in range(n):
		visited.append([0]*m)
	day = -1
	while len(queue)>0:
		listInThisDay = []
		for _ in range(len(queue)):
			node = queue.pop(0)
			y = node[0]
			x = node[1]
			visited[y][x] = 1
			listInThisDay.append(node)
		for node in listInThisDay:
			y = node[0]
			x = node[1]
			if y-1>=0 and (visited[y-1][x] == 0) and tomatoMap[y-1][x] == 0:
				queue.append((y-1,x))
				tomatoMap[y-1][x] = 1
			if y+1<n and (visited[y+1][x] == 0) and tomatoMap[y+1][x] == 0:
				queue.append((y+1,x))
				tomatoMap[y+1][x] = 1
			if x-1>=0 and (visited[y][x-1] == 0) and tomatoMap[y][x-1] == 0:
				queue.append((y,x-1))
				tomatoMap[y][x-1] = 1
			if x+1<m and (visited[y][x+1] == 0) and tomatoMap[y][x+1] == 0:
				queue.append((y,x+1))
				tomatoMap[y][x+1] = 1
		day+=1

	for i in tomatoMap:
		if 0 in i:
			return -1
	return day

def pprint(tomatoMap):
	for i in tomatoMap:
		print(i)

testSource = \
"""6 4
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 1"""

def testRun(testSource):
	lines = testSource.split("\n")
	m,n = map(int, lines.pop(0).split())
	tomatoMap = []
	for i in lines:
		tomatoMap.append(list(map(int,i.split())))
	print(tomatoBfs(m,n,tomatoMap))

def run():
	m,n = map(int, input().split())
	tomatoMap = []
	for _ in range(n):
		tomatoMap.append(list(map(int,input().split())))
	print(tomatoBfs(m,n,tomatoMap))

run()
# testRun(testSource)