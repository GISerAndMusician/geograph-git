import networkx as nx
import networkx.algorithms as algos
import matplotlib.pyplot as plt

def transform(nodes, edges):
    Narray = nodes.split(',')
    Earray = edges.split(',')

    N = [int(Narray[i]) for i in range(0, len(Narray), 1)]
    E = [(int(Earray[i]), int(Earray[i+1])) for i in range(0, len(Earray), 2)]
    
    G = nx.Graph()
    G.add_nodes_from(N)
    G.add_edges_from(E)

    return G

def run(nodes, edges):
    G = transform(nodes, edges)
    clusters = nx.clustering(G)
    I = 0
    for i in clusters.keys():
        k = G.degree[i]
        cc = clusters[i]
        I += k*cc
    print(I)
    return I