def stock(n, inputList):
	start = False
	currentMax = 0
	sumToCurrent = 0
	for i in range(n-1,-1,-1):
		if not start:
			start = True
			currentMax = inputList[i]
			continue
		if currentMax >= inputList[i]:
			sumToCurrent += currentMax-inputList[i]
		else:
			currentMax = inputList[i]
	return sumToCurrent

def run():
	for _ in range(int(input())):
		n = int(input())
		inputList = list(map(int, input().split()))
		print(stock(n, inputList))

def testRun():
	n = 3
	inputList = [10,7,6]
	print(stock(n,inputList)==0)
	n = 3
	inputList = [3,5,9]
	print(stock(n,inputList)==10)
	n = 5
	inputList = [1,1,3,1,2]
	print(stock(n,inputList)==5)

run()