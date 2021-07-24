
'''shortest path algorithm - single source '''

INF = 9999999

class Graph:
	def __init__(self,vertices,graph):
		self.V = vertices
		self.graph = graph

	def Print(self,dist,parent):
		print("Vertex => Distance from Source")
		for node in range(self.V):
			print(node , '\t' , '::' , dist[node])

		print("Parent List :: ",parent)

	def minDist(self,dist,sptSet):
		min = INF

		for v in range(self.V):
			if (dist[v] < min and sptSet[v] == False):
				min       = dist[v]
				min_index = v
		return min_index

	
	def dijkstra(self,src):
		parent = {}
		dist      = [INF] * self.V
		dist[src] = 0
		sptSet    = [False] * self.V #Shortest path tree set

		for i in range(self.V):
			u = self.minDist(dist,sptSet)
			sptSet[u] = True
			
			for v in range(self.V):
				if(self.graph[u][v] > 0 and sptSet[v] == False and dist[v] > dist[u] + self.graph[u][v]):
					dist[v]   = dist[u] + self.graph[u][v]
					parent[v] = u

		self.Print(dist,parent)



graph = [
			[0, 4, 0, 0, 0, 0, 0, 8, 0],
	        [4, 0, 8, 0, 0, 0, 0, 11, 0],
	        [0, 8, 0, 7, 0, 4, 0, 0, 2],
	        [0, 0, 7, 0, 9, 14, 0, 0, 0],
	        [0, 0, 0, 9, 0, 10, 0, 0, 0],
	        [0, 0, 4, 14, 10, 0, 2, 0, 0],
	        [0, 0, 0, 0, 0, 2, 0, 1, 6],
	        [8, 11, 0, 0, 0, 0, 1, 0, 7],
	        [0, 0, 2, 0, 0, 0, 6, 7, 0]
]

g = Graph(9,graph)
  
g.dijkstra(0);
  

