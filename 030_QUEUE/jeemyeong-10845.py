class Queue:
    def __init__(self):
        self.items = []

    def isEmpty(self):
        if self.size()==0:
        	return 1
        else:
        	return 0

    def push(self, item=0):
        self.items.append(item)

    def pop(self):
    	if self.size()>0:
        	return self.items.pop(0)
    	else:
        	return -1
    def front(self):
        if self.size()!=0:
        	return self.items[0]
        else:
        	return -1

    def back(self):
        if self.size()!=0:
	        return self.items[len(self.items)-1]
        else:
        	return -1

    def size(self):
        return len(self.items)

def run():
	queue = Queue()
	times = int(input())
	for i in range(0,times):
		cmd = input()
		if(cmd[:4]=="push"):
			cmd = cmd.split()
			queue.push(cmd[1])
		elif(cmd=="front"):
			print(queue.front())
		elif(cmd=="back"):
			print(queue.back())
		elif(cmd=="pop"):
			print(queue.pop())
		elif(cmd=="size"):
			print(queue.size())
		elif(cmd=="empty"):
			print(queue.isEmpty())

run()

