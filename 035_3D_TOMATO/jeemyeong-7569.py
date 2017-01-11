# https://www.acmicpc.net/problem/7569
import collections

def tomatoBfs(m,n,h,tomatoMap):
	queue = collections.deque()
	ripen = True
	for i in range(h):
		for j in range(n):
			for k in range(m):
				if tomatoMap[i][j][k] == 0:
					ripen = False
				if tomatoMap[i][j][k] == 1:
					queue.append((i,j,k))
	if ripen:
		return 0
	visited = []
	for _ in range(h):
		temp = []
		for _ in range(n):
			temp.append([0]*m)
		visited.append(temp)
	day = -1
	while queue:
		listInThisDay = []
		for _ in range(len(queue)):
			z,y,x = queue.popleft()
			visited[z][y][x] = 1
			listInThisDay.append((z,y,x))
		for z,y,x in listInThisDay:
			if z-1>=0 and (visited[z-1][y][x] == 0) and tomatoMap[z-1][y][x] == 0:
				queue.append((z-1,y,x))
				tomatoMap[z-1][y][x] = 1
			if z+1<h and (visited[z+1][y][x] == 0) and tomatoMap[z+1][y][x] == 0:
				queue.append((z+1,y,x))
				tomatoMap[z+1][y][x] = 1
			if y-1>=0 and (visited[z][y-1][x] == 0) and tomatoMap[z][y-1][x] == 0:
				queue.append((z,y-1,x))
				tomatoMap[z][y-1][x] = 1
			if y+1<n and (visited[z][y+1][x] == 0) and tomatoMap[z][y+1][x] == 0:
				queue.append((z,y+1,x))
				tomatoMap[z][y+1][x] = 1
			if x-1>=0 and (visited[z][y][x-1] == 0) and tomatoMap[z][y][x-1] == 0:
				queue.append((z,y,x-1))
				tomatoMap[z][y][x-1] = 1
			if x+1<m and (visited[z][y][x+1] == 0) and tomatoMap[z][y][x+1] == 0:
				queue.append((z,y,x+1))
				tomatoMap[z][y][x+1] = 1
		day+=1
	for i in tomatoMap:
		for j in i:
			if 0 in j:
				return -1
	return day

def pprint(tomatoMap):
	for i in tomatoMap:
		for j in i:
			print(j)
		print()

testSource = \
"""5 3 1
0 -1 0 0 0
-1 -1 0 1 1
0 0 0 1 1"""

def testRun(testSource):
	lines = testSource.split("\n")
	m,n,h = map(int, lines.pop(0).split())
	tomatoMap = []
	for i in range(h):
		tomatoMap.append([])
	cnt = 0
	while cnt<n*h:
		tomatoMap[cnt//n].append(list(map(int,lines[cnt].split())))
		cnt+=1
	print(tomatoBfs(m,n,h,tomatoMap))

def run():
	m,n,h = map(int, input().split())
	tomatoMap = []
	for i in range(h):
		tomatoMap.append([])
	cnt = 0
	while cnt<n*h:
		tomatoMap[cnt//n].append(list(map(int,input().split())))
		cnt+=1
	print(tomatoBfs(m,n,h,tomatoMap))

# run()
testRun(testSource) 
