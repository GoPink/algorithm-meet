# https://www.acmicpc.net/problem/7576
import collections

def tomatoBfs(m,n,tomatoMap):
	queue = collections.deque()
	ripen = True
	for i in range(n):
		for j in range(m):
			if tomatoMap[i][j] == 0:
				ripen = False
			if tomatoMap[i][j] == 1:
				queue.append((i,j))
	if ripen:
		return 0
	visited = []
	for _ in range(n):
		visited.append([0]*m)
	day = -1
	while queue:
		listInThisDay = []
		for _ in range(len(queue)):
			y,x = queue.popleft()
			visited[y][x] = 1
			listInThisDay.append((y,x))
		for y, x in listInThisDay:
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

# UPDATE with reference
def tomatoBfs2(m,n,tomatoMap):
	direct = [[0, 1], [1, 0], [0, -1], [-1, 0]]
	queue = collections.deque()
	for i in range(n):
		for j in range(m):
			if tomatoMap[i][j] == 1:
				queue.append((i,j))
	while queue:
		y,x = queue.popleft()
		for d in direct:
			dy = y + d[0]
			dx = x + d[1]
			if dy<0 or dx<0 or dy>=n or dx>=m:
				continue
			if tomatoMap[dy][dx] == 0:
				queue.append((dy,dx))
				tomatoMap[dy][dx] = tomatoMap[y][x]+1
	max_num = 0
	for i in range(n):
		for j in range(m):
			if tomatoMap[i][j] == 0:
				return -1
			if max_num < tomatoMap[i][j]:
				max_num = tomatoMap[i][j]
	return max_num -1

# BELOW is reference
# 
# import collections

# def bfs():
#     direct = [[0, 1], [1, 0], [0, -1], [-1, 0]]
#     q = collections.deque()
#     for i in range(n):
#         for j in range(m):
#             if arr[i][j] == 1:
#                 q.append([i, j])

#     while q:
#         y, x = q.popleft()
#         for d in direct:
#             dy = y + d[0]
#             dx = x + d[1]
#             if dy < 0 or dx < 0 or dy >= n or dx >= m:
#                 continue
#             if arr[dy][dx] == 0:
#                 arr[dy][dx] = arr[y][x] + 1
#                 q.append([dy, dx])

#     max_num = 0
#     for i in range(n):
#         for j in range(m):
#             if arr[i][j] == 0:
#                 print(-1)
#                 return
#             if max_num < arr[i][j]:
#                 max_num = arr[i][j]
#     print(max_num - 1)


# m, n = map(int, input().split())
# arr = [[]] * n
# for i in range(n):
#     arr[i] = list(map(int, input().split()))

# bfs()

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