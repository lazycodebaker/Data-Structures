
import sys

class Graph:
 	def __init__(self,edges,nodes,verticesNum):
 		self.edges       = edges
 		self.nodes       = nodes
 		self.verticesNum = verticesNum
 		self.MST         = []

 	def print(self):
 		print("Edge :: Weight")
 		for s,d,w in self.MST:
 			print("%s --> %s : %s" % (s,d,w))

 	def primsAlgo(self):
 		visitedNodes    = [0]*self.verticesNum
 		edgeNum		    = 0
 		visitedNodes[0] = True

 		while edgeNum < self.verticesNum - 1:
 			min = sys.maxsize

 			for i in range(self.verticesNum):
 				if(visitedNodes[i]):
 					for j in range(self.verticesNum):
 						if((not visitedNodes[j]) and self.edges[i][j]):
 							if min > self.edges[i][j]:
 								min = self.edges[i][j]

 								s = i 
 								d = j

 			self.MST.append([self.nodes[s],self.nodes[d],self.edges[s][d]])

 			visitedNodes[d] = True
 			edgeNum += 1

 		self.print()


edges = [  
		   [0,  2,  2, 1,  4],
		   [2,  0,  5, 3,  3],
		   [2,  5,  0, 2,  4],
		   [1,  3,  2, 0,  8],
		   [4,  3,  4, 8,  0]
]

nodes = ["A","B","C","D","E"]

g = Graph(edges,nodes,5)
g.primsAlgo()
