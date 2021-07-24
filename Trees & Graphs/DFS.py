
class Node:
    def __init__(self, data):
        self.left    = None
        self.right   = None
        self.data    = data
        self.visited = False

    def insert(self, data):
        if self.data:
            if data < self.data:
                if self.left is None:
                    self.left = Node(data)
                else:
                    self.left.insert(data)
            elif data > self.data:
                if self.right is None:
                    self.right = Node(data)
                else:
                    self.right.insert(data)
        else:
            self.data = data

    def PrintTree(self):
        if self.left:
            self.left.PrintTree()
        print( self.data)
        if self.right:
            self.right.PrintTree()

root = Node(1)
root.insert(2)
root.insert(3)
root.insert(4)
root.insert(5)
root.insert(6)
root.insert(7)
root.insert(8)
root.insert(9)
root.insert(10)
root.insert(11)
root.insert(12)
root.insert(13)
root.insert(14)
root.insert(15)
root.insert(16)
root.insert(17)
root.insert(18)
root.insert(19)
root.insert(20)

def DFS(root,value):
	stack = []
	found = {}
	steps = {}

	while(root):
		steps[root.data] = -1
		if(root == value):
			found['Found after steps'] = steps[value]
			break		
		stack.append(root)
		root.visited = True
		root = root.left

	for n in stack:
				print("Before Popped",n.data)
	print("Now")
	
	while(stack):
		node = stack.pop()
		if(node.data ==  value):
			found['Found after steps'] = steps[value]
			break

		if((node.left) and (node.left.visited == False)):
			steps[node.left.data] = steps[node.data] + 1
			print("found a node in left that is :: " , node.left.data)
			node.left.visited = True
			stack.append(node.left)
		else:
			print("No root in left")

		if((node.right) and (node.right.visited == False)):
			steps[node.right.data] = steps[node.data] + 1
			print("node found in right that is ::",node.right.data)
			node.right.visited = True
			stack.append(node.right)
		else:
			print("no nodes in right")

	if(found):
		print(found)
	else:
		print("value not found")

DFS(root,17)
