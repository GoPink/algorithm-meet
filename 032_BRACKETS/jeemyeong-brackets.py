import unittest
import random

# 기존에 만들었던 알고리즘 # 오답으로 판명
# 가장 처음에 오는 ( 과 [ 를 찾고 각각의 depth에 해당하는 ) 와 ] 를 찾음. 그 속에 있는 str의 count와 오른쪽에 있는 str의 count를 더하고 2를 더한 후 dict에 저장
# )[]][[[([)()][ 등의 반례가 존재
def brackets(StrOfBrackets):
    if len(StrOfBrackets)==0:
        return 0
    if StrOfBrackets in memo.keys():
        return memo[StrOfBrackets]
    sbDepth = 0
    bbDepth = 0
    sbRunningStart = False
    sbRunningEnd = False
    bbRunningStart = False
    bbRunningEnd = False
    sbFromIdx = 0
    sbToIdx = 0
    bbFromIdx = 0
    bbToIdx = 0
    i = 0
    while (not sbRunningEnd or not bbRunningEnd) and i<len(StrOfBrackets):
        if StrOfBrackets[i]=="(" and sbRunningStart == True:
            sbDepth += 1
        if StrOfBrackets[i]=="(" and sbRunningStart == False:
            sbDepth += 1
            sbFromIdx = i
            sbRunningStart = True
        if StrOfBrackets[i]==")" and sbDepth==1 and not sbRunningEnd:
            sbDepth -= 1
            sbToIdx = i
            sbRunningEnd = True
        if StrOfBrackets[i]==")" and sbDepth>1 and not sbRunningEnd:
            sbDepth -= 1

        if StrOfBrackets[i]=="[" and bbRunningStart == True:
            bbDepth += 1
        if StrOfBrackets[i]=="[" and bbRunningStart == False:
            bbDepth += 1
            bbFromIdx = i
            bbRunningStart = True
        if StrOfBrackets[i]=="]" and bbDepth==1 and not bbRunningEnd:
            bbDepth -= 1
            bbToIdx = i
            bbRunningEnd = True
        if StrOfBrackets[i]=="]" and bbDepth>1 and not bbRunningEnd:
            bbDepth -= 1
        i+=1

    sbLength = 0
    bbLength = 0
    if sbRunningEnd:
        sbLength = 2 + brackets(StrOfBrackets[sbFromIdx+1:sbToIdx]) + brackets(StrOfBrackets[sbToIdx+1:])
    if bbRunningEnd:
        bbLength = 2 + brackets(StrOfBrackets[bbFromIdx+1:bbToIdx]) + brackets(StrOfBrackets[bbToIdx+1:])
    count = max(sbLength, bbLength, brackets(StrOfBrackets[1:]))
    memo[StrOfBrackets] = count
    return count


# http://aaalab.tistory.com/19 에서의 c++알고리즘을 파이썬으로 작성
# 가장 처음에오는 여는 괄호 ( or [를 찾고 그 이후에 가장 먼저 오는 해당하는 괄호부터 모든 괄호를 찾는다.
# 그리고 그속에 있는 str에 대한 count, 그 바깥쪽의 str의 count에 2를 더한다.
# 그리고 그 처음의 오는 괄호를 제외한 str으로 다시 반복한다.
def brackets2(StrOfBrackets):
    if StrOfBrackets == "":
        return 0
    if StrOfBrackets in memo2.keys():
        return memo2[StrOfBrackets]
    count = 0
    if StrOfBrackets[0] == "(" or StrOfBrackets[0] == "[":
        if StrOfBrackets[0] == "(":
            closer = ")"
        else:
            closer = "]"
        start = 1
        while True:
            if StrOfBrackets[start:].find(closer) == -1:
                break
            last = StrOfBrackets[start:].find(closer) + start
            print(StrOfBrackets, start, count, last)
            temp = 2 + brackets2(StrOfBrackets[1:last]) + brackets2(StrOfBrackets[last+1:])
            count = max(count, temp)
            start = last + 1
        count = max(count, brackets2(StrOfBrackets[1:]))
    else:
        count = brackets2(StrOfBrackets[1:])
    memo2[StrOfBrackets] = count
    return count

# 각각의 dict
memo = {}
memo2 = {}

# test코드들
class equalityTest(unittest.TestCase):
	def test_equal(self):
	    self.assertEqual(brackets("[[(((]])))"),6)
	    self.assertEqual(brackets("((()))"),6)
	    self.assertEqual(brackets("()()()"),6)
	    self.assertEqual(brackets("([]])"),4)
	    self.assertEqual(brackets(")[)("),0)
	    self.assertEqual(brackets("([][][)"),6)
	    self.assertEqual(brackets(")()()("),4)
	    self.assertEqual(brackets("())[(])()()([("),8)
	    self.assertEqual(brackets("((())"),4)
	    self.assertEqual(brackets("(()"),2)
	    self.assertEqual(brackets("(((][])("),4)
def testRunning():
	if __name__ == '__main__':
	    unittest.main()

# 난수를 생성하여 비교
def randomCompare():
    for i in range(100):
        StrOfBrackets = makeRandomStrOfBrackets()
        testTwoMethod(StrOfBrackets)

def makeRandomStrOfBrackets():
    StrOfBrackets = ""
    randint = random.randint(0,268435456)
    for i in range(14):
        if randint % 4 == 0:
            StrOfBrackets += "("
        if randint % 4 == 1:
            StrOfBrackets += ")"
        if randint % 4 == 2:
            StrOfBrackets += "["
        if randint % 4 == 3:
            StrOfBrackets += "]"
        randint //= 4
    return StrOfBrackets

def testTwoMethod(StrOfBrackets):
    if brackets(StrOfBrackets) != brackets2(StrOfBrackets):
        print("ERROR", StrOfBrackets, brackets(StrOfBrackets), ":", brackets2(StrOfBrackets))

# 실제 제출용 method
def run():
    inputBrackets = input()
    while(inputBrackets != "end"):
        print(brackets(inputBrackets))
        inputBrackets = input()

testRunning()
# randomCompare()
# run()
