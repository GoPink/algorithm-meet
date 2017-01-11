# https://www.acmicpc.net/problem/2178
import collections

def bfs(n,m,maze):
	direct = [[0,1],[0,-1],[1,0],[-1,0]]
	visited =[]
	for i in range(n):
		visited.append([0]*m)
	queue = collections.deque()
	queue.append((0,0))
	while queue:
		if visited[n-1][m-1] == 1:
			break
		y,x = queue.popleft()
		visited[y][x] = 1
		for d in direct:
			dy = y + d[0]
			dx = x + d[1]
			if dy >= n or dy < 0 or dx >= m or dx < 0:
				continue
			if visited[dy][dx] == 0 and maze[dy][dx] ==1:
				maze[dy][dx] = maze[y][x] + 1
				queue.append((dy,dx))
	return maze[n-1][m-1]

testSource= \
"""4 6
101111
101010
101011
111011"""

testSource2 = \
"""4 6
110110
110110
111111
111101"""

def testRun(testSource):
	maze = testSource.split("\n")
	n,m = map(int,maze.pop(0).split())
	maze = [list(map(int,list(i))) for i in maze]
	print(bfs(n,m,maze))

def run():
	n,m = map(int,input().split())
	maze = []
	for i in range(n):
		maze.append(list(map(int,list(input()))))
	print(bfs(n,m,maze))

def pprint(maze):
	for i in maze:
		print(i)

# testRun(testSource)
run()