# https://www.acmicpc.net/problem/1495

# # ORIGINAL SOURCE
# restriction = list(map(int, input().split()))
# inputList = list(map(int, input().split()))

# start = restriction[1]
# maximum = restriction[2]

# recentNumbers = [start]

# for i in inputList:
# 	newNumbers = []
# 	for j in recentNumbers:
# 		if 0 <= j-i:
# 			newNumbers.append(j-i)
# 		if j+i <= maximum:
# 			newNumbers.append(j+i)
# 	recentNumbers = set(newNumbers)
# 	if not recentNumbers:
# 		print("-1")
# 		break

# if recentNumbers:
# 	print(max(recentNumbers))

def guitarist(n,s,m,inputList):
	recent = [s]
	for i in range(n):
		dp = []
		for j in recent:
			if j - inputList[i] >= 0:
				dp.append(j-inputList[i])
			if j + inputList[i] <= m:
				dp.append(j+inputList[i])
		if not dp:
			return -1
		recent = set(dp)
	return (max(recent))

def run():
	n,s,m = map(int,input().split())
	inputList = list(map(int, input().split()))
	print(guitarist(n,s,m,inputList))

def testRun():
	n,s,m = [3,5,10]
	inputList = [5,3,7]
	print(guitarist(n,s,m,inputList)==10)

# testRun()
run()