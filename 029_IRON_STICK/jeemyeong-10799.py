class StackClass:

    def __init__(self, itemlist=[]):
        self.items = itemlist

    def isEmpty(self):
        if self.items == []:
            return True
        else:
            return False

    def peek(self):
        return self.items[-1:][0]

    def pop(self):
        return self.items.pop()

    def push(self, item):
        self.items.append(item)
        return 0

def splitIron(str):
    s=StackClass()
    cnt=0
    lastCharIsOpen = False
    splitCnt=0
    for i in str:
        if i=="(":
            s.push(i)
            cnt+=1
            lastCharIsOpen = True
        elif i==")":
            cnt-=1
            if s.peek() == "(" and lastCharIsOpen == True:
                splitCnt+=cnt
                lastCharIsOpen = False
                s.pop()
            else:
                splitCnt+=1
                s.pop()
    return splitCnt

print(splitIron(input()))