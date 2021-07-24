
class Graph:
	def __init__(self,vertices):
		self.V     = vertices
		self.graph = []

	def addEdge(self,s,d,w):
		self.graph.append([s,d,w])

	def find(self,parent,node):
		if (parent[node] == node):
			print("parent",parent)
			return node
		return self.find(parent,parent[node])

	def union(self, parent, rank, x, y):
		xroot = self.find(parent, x)
		yroot = self.find(parent, y)

		print("XRoot::",x," " , "YRoot ",yroot)

		print("rankX::",rank[xroot]," ","ranky",rank[yroot])

		if rank[xroot] < rank[yroot]:
			parent[xroot] = yroot
		elif rank[xroot] > rank[yroot]:
			parent[yroot] = xroot

		else:
			parent[yroot] = xroot
			rank[xroot] += 1

	def KruskalMST(self):
		result       = []
		index_edges  = 0
		index_result = 0

		self.graph = sorted(self.graph,key=lambda item:item[2])

		parent = []
		rank   = []

		for node in range(self.V):
			parent.append(node)
			rank.append(0)

		while index_edges < self.V :
			s,d,w = self.graph[index_edges]

			index_edges += 1

			print("S::",s," ","D::",d)

			x = self.find(parent,s)
			y = self.find(parent,d) 

			print("X::",x)
			print("Y::",y)

			if (x != y):
				index_result += 1
				result.append([s,d,w])
				print("Rank :: ",rank)
				self.union(parent,rank,x,y)

		minCost = 0
		print("edges in MST")

		for s,d,w in result:
			minCost += w

			print("%d --> %d == %d "%(s,d,w))

		print("Min Cost is :: ",minCost)

'''0 ->Alam
   1-> amina
   2-> hazrat
   3->gomti
'''
g = Graph(4)
g.addEdge(0, 1, 21)
g.addEdge(0, 2, 27)
g.addEdge(0, 3, 35)
g.addEdge(1, 3, 33)
g.addEdge(2, 3, 22)
 
# Function call
g.KruskalMST()