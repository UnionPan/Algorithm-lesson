import networkx as nx
import numpy as np 
import matplotlib.pyplot as plt

G = nx.MultiDiGraph()
nodes = [1,2,3,4,5,6]
G.add_nodes_from(nodes)

edges = [(2,1,1), (4,1,-4), (1,5,-1), (4,5,3), (2,4,2), (5,2,7), (3,2,2), (6,2,5), (6,3,10), (3,6,-8)]

G.add_weighted_edges_from(edges)
#print(G.edges())
#print(G[1][5][0]['weight'])

def Floyed_Warshall(G):
    n = len(G.nodes)
    k = 0
    D = np.empty((n,n))
    P = np.empty((n,n))
    for i in range(n):
        for j in range(n):
            if (i == j):
                D[i,j] = 0
                P[i,j] = None
            elif (i+1, j+1) in [(u, v) for (u, v) in G.edges()]:
                D[i, j] = G[i+1][j+1][0]['weight']
                P[i, j] = i+1
            else:
                D[i, j] = 999
                P[i, j] = None


    while k<= 5:
        D_new = np.copy(D)
        P_new = np.copy(P)
        for i in range(n):
            for j in range(n):
                if D[i, k] + D[k, j]< D[i, j]:
                    D_new[i, j] = D[i, k] + D[k, j]
                    P_new[i, j] = k+1
        k += 1
        D = D_new
        P = P_new
        print(k)
        print(D_new)
        print('\n')
        print(P_new)

Floyed_Warshall(G)


#plt.figure()
#nx.draw(G, pos=nx.planar_layout(G))
#plt.show()