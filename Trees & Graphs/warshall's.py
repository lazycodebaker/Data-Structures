
INF = 999999
V =  4

graph = [
          [0  ,5 ,INF,10],
          [INF,0 , 3 ,INF],
          [INF,INF,0 ,1  ],
          [INF,INF,INF,0]
        ]

def warshalls(graph):
    dist = graph

    for k in range(V):
        for i in range(V):
            for j in range(V):
                dist[i][j] = min(dist[i][j] , dist[i][k] + dist[k][j])
    
    print(dist)


warshalls(graph)