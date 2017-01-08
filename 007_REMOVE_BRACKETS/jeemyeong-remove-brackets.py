# https://www.acmicpc.net/problem/2800



# # this makes overflow
# def recursiveRemove(inputStr):
# 	solution = []
# 	openIdx = inputStr.find("(")
# 	closeIdx = inputStr.rfind(")") - len(inputStr)
# 	if openIdx == -1:
# 		return [inputStr]
# 	remainStr = inputStr[0:openIdx] + inputStr[openIdx+1:closeIdx] + inputStr[len(inputStr)+closeIdx+1:len(inputStr)]
# 	for i in recursiveRemove(remainStr):
# 		solution.append(i)
# 		assembled = i[0:openIdx] + "(" + i[openIdx:len(i)+closeIdx+1] + ")" + i[len(i)+closeIdx+1:len(i)]
# 		solution.append(assembled)
# 	return solution

# def removeBrackets(inputStr):
# 	solution = recursiveRemove(inputStr)
# 	solution.remove(inputStr)
# 	for i in solution:
# 		try:
# 			if int(i) != int(inputStr):
# 				solution.remove(inputStr)
# 		except ValueError as e:
# 			pass
# 	solution.sort()
# 	return solution


def removeBrackets(inputStr):
	cnt = inputStr.count("(")
	info = [None]*(2**(cnt+1)-2)
	info[0] = removeNthBrackets(inputStr, 0)
	info[1] = inputStr
	i = 2
	depth = 1
	q = [info[0], info[1]]
	while depth < cnt:
		depth += 1
	for _ in range(cnt-1):
		for _ in range(len(q)):
			openIdx = -1
			closeIdx = -1
			info[i] = removeNthBrackets(info[(i-2)//2], i)
			q.append(info[i])
			i+=1
			info[i] = info[(i-2)//2]
			q.append(info[i])
			i+=1
			q.pop(0)
	solution = info[-(2**cnt):-1]
	solution = sorted(set(solution))
	return solution


def removeNthBrackets(inputStr, infoIdx):
	nth = 1
	while infoIdx>0:
		if (infoIdx-2)%2 == 1:
			nth += 1
		infoIdx = (infoIdx-2)//2
	for i in range(len(inputStr)):
		if inputStr[i]=="(":
			nth-=1
		if nth==0:
			openIdx = i
			break
	stack = []
	for i in range(len(inputStr[openIdx:])):
		if inputStr[openIdx+i]=="(":
			stack.append("(")
		if inputStr[openIdx+i]==")":
			stack.pop()
		if len(stack) == 0:
			closeIdx = openIdx + i
			break
	if openIdx == -1 or closeIdx == -1:
		raise Exception
	newStr = inputStr[0:openIdx] + inputStr[openIdx+1:closeIdx] + inputStr[closeIdx+1:len(inputStr)]
	return newStr

def run():
	inputStr = input()
	print("\n".join(removeBrackets(inputStr)))

run() 

def testRun():
	inputStr = "((0/(0)*(8)))"
	print("\n".join(removeBrackets(inputStr)))



# Belows are my reference solution
new_expressions = []
def generate_expression(cur_expr, expr, paren_added_list):
	for i in range(len(expr)):
		c = expr[i]
		if c == '(':
			generate_expression(cur_expr, expr[i + 1:],
								paren_added_list + [False])
			generate_expression(cur_expr + '(', expr[i + 1:],
								paren_added_list + [True])
			return
		elif c == ')':
			if paren_added_list.pop():
				cur_expr += ')'
		else:
			cur_expr += c
	new_expressions.append(cur_expr)

def runWithSolution():
	expression = input()
	generate_expression('', expression, [])
	for new_expression in sorted(set(new_expressions)):
		if new_expression != expression:
			print(new_expression)

# test with other solution
def compareWithSolution():
	inputStr = "((0/(0)*(8)))"
	test = removeBrackets(inputStr)
	test2 = []
	expression = inputStr
	generate_expression('', expression, [])
	for new_expression in sorted(set(new_expressions)):
		if new_expression != expression:
			test2.append(new_expression)
	for i in range(len(test)):
		if test[i] != test2[i]:
			print("ERROR")
			return
	if len(test[i])!=len(test2[i]):
		print("ERROR")

compareWithSolution()
