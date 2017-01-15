# https://www.acmicpc.net/problem/1753
import heapq
from collections import deque
testSource = \
"""5 6
1
5 1 1
1 3 3
1 2 2
2 3 4
2 4 5
3 4 6"""

def queueTest():
	queue = []
	D = []
	for i in range(9,-1,-1):
		D.append([i,90+(i*10)])
		heapq.heappush(queue, D[9-i])
	for i in range(9):
		j = heapq.heappop(queue)
		print(j)


def dijkstra(vCnt,start,path):
	MAX_INT = 987654321
	visited = [MAX_INT] * (vCnt)
	visited[start-1] = 0
	q = deque()
	q.append((start-1, 0))
	while q:
		u, d = q.popleft()
		for v, w in path[u]:
			if d + w < visited[v]:
				visited[v] = d + w
				q.append((v, d+w))
	solution = []
	for i in visited:
		if i == MAX_INT:
			# print("INF")
			solution.append("INF")
		else:
			# print(i)
			solution.append(str(i))
	return solution

def dijkstra2(vCnt,start,path): # time error
	MAX_INT = 987654321
	visited = [0] * vCnt
	queue = []
	D = []
	for i in range(vCnt):
		if i == start-1:
			D.append([0, i])
		else:	
			D.append([MAX_INT, i])
		heapq.heappush(queue, D[i])
	while queue:
		d,u = heapq.heappop(queue)
		visited[u] = 1
		for v,w in path[u]:
			if visited[v] == 0 and (D[v][0] > D[u][0] + w ):
				D[v][0] = D[u][0] + w
		heapq.heapify(queue)

	solution = []
	for i in D:
		if i[0] == MAX_INT:
			# print("INF")
			solution.append("INF")
		else:
			# print(i[0])
			solution.append(str(i[0]))
	return solution

def run():
	vCnt, eCnt = list(map(int,input().split()))
	start = int(input())
	path = [[] for i in range(vCnt)]
	for i in range(eCnt):
		u,v,w = map(int,input().split())
		path[u-1].append((v-1,w))
	print("\n".join(dijkstra(vCnt,start,path)))


def testRun(testSource):
	source = testSource.split("\n")
	vCnt, eCnt = list(map(int,source.pop(0).split()))
	start = int(source.pop(0))
	path = [[] for i in range(vCnt)]
	for i in source:
		u,v,w = map(int,i.split())
		path[u-1].append((v-1,w))
	print("\n".join(dijkstra(vCnt,start,path)))

def testCompareTwoMethod(testSource):
	source = testSource.split("\n")
	vCnt, eCnt = list(map(int,source.pop(0).split()))
	start = int(source.pop(0))
	path = [[] for i in range(vCnt)]
	for i in source:
		u,v,w = map(int,i.split())
		path[u-1].append((v-1,w))
	print(dijkstra(vCnt,start,path) == dijkstra2(vCnt,start,path))
	

def randomCompare():
	time = 1
	for i in range(time):
		testSource = makeRandomSource()
		testCompareTwoMethod(testSource)

def makeRandomSource():
	import random
	vCnt = random.randint(1,20000)
	eCnt = random.randint(1,300000)
	start = random.randint(1,vCnt)
	source = str(vCnt) + " " + str(eCnt) + "\n" + str(start)
	for i in range(eCnt):
		u,v,w = random.randint(1,vCnt), random.randint(1,vCnt), random.randint(1,10)
		while u==v:
			v = random.randint(1,vCnt)
		source += "\n" + str(u) + " " + str(v) + " " + str(w)
	return source

def pprint(path):
	for i in path:
		print(i)
	print()
	
# queueTest()
# testRun(testSource)
run()
# randomCompare()