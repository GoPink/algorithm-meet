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

def findMaxAreaInHistogram(lst):
	maxArea = 0
	i=0
	s=StackClass()
	while(i<len(lst)):
		if(s.isEmpty() or lst[s.peek()] <= lst[i]):
			s.push(i)
			i+=1
		else:
			extract = s.pop()
			if(s.isEmpty()):
				area = lst[extract] * (i)
			else:
				area = lst[extract] * (i-s.peek()-1)
			if(maxArea<area):
				maxArea = area
	while(s.isEmpty()==False):
		extract = s.pop()
		if(s.isEmpty()):
			area = lst[extract] * (i)
		else:
			area = lst[extract] * (i-s.peek()-1)
		if(maxArea<area):
			maxArea = area
	return maxArea

test = []
for _ in range(int(input())):
	test.append(int(input()))
print(findMaxAreaInHistogram(test))