def brackets(StrOfBrackets):
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

        if (bbRunningStart == True and bbDepth == 0):
            bbToIdx = i-1
            bbRunningEnd = True
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
    return max(sbLength, bbLength)

def brackets2(StrOfBrackets):
    if StrOfBrackets == "":
        return 0
    if StrOfBrackets in memo.keys():
        return memo[StrOfBrackets]
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
            temp = 2 + brackets2(StrOfBrackets[1:last]) + brackets2(StrOfBrackets[last+1:]);
            count = max(count, temp)
            start = last + 1
        count = max(count, brackets2(StrOfBrackets[1:]))
    else:
        count = brackets2(StrOfBrackets[1:])
    memo[StrOfBrackets] = count
    return count

memo = {}

def testRunning():
    print("running...")
    test("[[(((]])))",6)
    test("((()))",6)
    test("()()()",6)
    test("([]])",4)
    test(")[)(",0)
    test("([][][)",6)
    test(")()()(",4)
    test("())[(])()()([(",8)
    print("End")

def test(StrOfBrackets, expectResult):
    if brackets2(StrOfBrackets) != expectResult:
        print("ERROR", StrOfBrackets, expectResult, "is expected, but result is", brackets2(StrOfBrackets))


def run():
    inputBrackets = input()
    while(inputBrackets != "end"):
        print(brackets2(inputBrackets))
        inputBrackets = input()

# testRunning()
run()


