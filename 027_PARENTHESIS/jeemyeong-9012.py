class Stack:
    def __init__(self):
        self.items = []

    def isEmpty(self):
        return self.items == []

    def push(self, item):
        self.items.append(item)

    def pop(self):
        return self.items.pop()

    def peek(self):
    	if self.isEmpty():
    		return False
    	else:
        	return self.items[-1]

    def size(self):
        return len(self.items)

def run():
	cnt = int(input())
	for i in range(0,cnt):
		err = False
		testStack = Stack()
		parenthesis = input().replace(" ","")
		for i in parenthesis:
			if(i=="("):
				testStack.push(i)
			elif(i==")" and testStack.peek()=="("):
				testStack.pop()
			else:
				print("NO")
				err = True
				break
		if not testStack.isEmpty():
			print("NO")
			err = True
		if not err:
			print("YES")

run()