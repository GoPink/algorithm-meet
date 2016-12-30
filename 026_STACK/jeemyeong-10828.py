class Stack:
	def __init__(self):
		self.items = []

	def isEmpty(self):
		if self.size()==0:
			return 1
		return 0

	def push(self, item):
		self.items.append(item)

	def pop(self):
		if self.isEmpty() == 1:
			return -1
		return self.items.pop()

	def peek(self):
		if self.isEmpty() == 1:
			return -1
		return self.items[len(self.items)-1]

	def size(self):
		return len(self.items)

def run():
	stack = Stack()
	times = int(input())
	for i in range(0,times):
		cmd = input()
		if(cmd[:4]=="push"):
			cmd = cmd.split()
			stack.push(cmd[1])
		elif(cmd=="top"):
			print(stack.peek())
		elif(cmd=="pop"):
			print(stack.pop())
		elif(cmd=="size"):
			print(stack.size())
		elif(cmd=="empty"):
			print(stack.isEmpty())

run()

