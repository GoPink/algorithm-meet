# 사탕 가게 # https://www.acmicpc.net/problem/4781

# # Original ver I solved
# def eval(dic, calAccumul, money):
# 	if money < min(dic, key = lambda t: t[0])[0]:
# 		return calAccumul
# 	caloList = set()
# 	caloList.add(calAccumul)
# 	for i in range(len(dic)):
# 		if money-dic[i][0] >=0:
# 			moneyLeft = money - dic[i][0]
# 			calAccumulRes = calAccumul + dic[i][1]
# 			z = eval(dic[i:], calAccumulRes, moneyLeft)
# 			caloList.add(z)
# 	return max(caloList)


def run():
	while True:
		inputLimit = input()
		if inputLimit =='0 0.00':
			break
		time, money = map(float,inputLimit.split())
		money = int(100 * money)
		candyDic = {}
		for _ in range(int(time)):
			c,p = map(float,input().split())
			candyDic[int(100*p)] = int(c)
		print(candyEval(candyDic, money))

def run2():
	while True:
	    inputLimit = input()
	    if inputLimit =='0 0.00':
	        break
	    time, money = map(float,inputLimit.split())
	    time = int(time)
	    cent = int(100 * money)
	    dp = [0] * (cent+1)
	    for _ in range(time):
	        calorie,price = map(float,input().split())
	        calorie = int(calorie)
	        price = int(100 * price)
	        for j in range(price,cent+1):
	            dp[j] = max(dp[j], dp[j-price]+calorie)
	    print(dp[cent])

def candyEval(candyDic, money):
	calDic = {0:0}
	for i in range(1,money+1):
		calDic[i] = calDic[i-1]
		for j in candyDic.keys():
			if i-j>=0 and calDic[i-j]+candyDic[j] > calDic[i]:
				calDic[i] = calDic[i-j] +candyDic[j]
	return calDic[money]

def candyEvalWithArray(candyDic, money):
	dp = [0] * (money+1)
	for price in candyDic.keys():
		calorie = candyDic[price]
		for j in range(price, money+1):
			dp[j] = max(dp[j], dp[j-price]+calorie)
	return dp[money]

def testRun(testSource):
	lines = testSource.split("\n")
	while True:
		firstLine = lines.pop(0)
		if firstLine == "0 0.00":
			break
		time, money = map(float,firstLine.split())
		money = int(100 * money)
		candyDic = {}
		for _ in range(int(time)):
			c,p = map(float,lines.pop(0).split())
			candyDic[int(100*p)] = int(c)
		print(candyEval(candyDic, money))


testSource = \
"""2 8.00
700 7.00
199 2.00
3 8.00
700 7.00
299 3.00
499 5.00
0 0.00"""

testRun(testSource)
# run()