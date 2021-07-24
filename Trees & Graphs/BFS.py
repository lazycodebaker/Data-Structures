 
class Node:
	def __init__(self,data):
		self.data  = data
		self.left  = None
		self.right = None
		self.parent = None

def insertNode(root,d):
	if(root == None):
		root = Node(d)
	else:
		if(d < root.data):
			insertNode(root.left,d)
		else:
			insertNode(root.right,d)

def printTree(root):
	if(root):
		printTree(root.left)
		print(root.data)
		printTree(root.right)



root 	= Node(1)
insertNode(root,2)
insertNode(root,3)
insertNode(root,4)
insertNode(root,5)
insertNode(root,6)
insertNode(root,7)
insertNode(root,8)
insertNode(root,9)
insertNode(root,10)

printTree(root)

def BFS(root):
	queue 	= []
	parent  = {}

	level = {}

	if(root):
		level[root.data] = 0
		queue.append(root)

		while (queue):
			node = queue.pop(0)		
			print(node.data)

			if(node.left):
				level[node.left.data] =level[node.data] + 1 
				parent[node.left.data] = node.data 
				queue.append(node.left)
			if(node.right):
				level[node.right.data] = level[node.data] +1 
				parent[node.right.data] = node.data
				queue.append(node.right)

	print("parent \n",parent)
	print("Level \n",level)



