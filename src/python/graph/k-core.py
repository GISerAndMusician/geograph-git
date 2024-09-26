import networkx as nx
import networkx.algorithms as algos
import matplotlib.pyplot as plt

'''
G = nx.read_gml('D:/Workspace/igraph-0.10.8/examples/simple/karate.gml', label='id')

max_core_number = max(algos.core_number(G).values())

for i in range(max_core_number + 1):
    sub_G = algos.k_core(G, i)
    print(f'{i}-core:{sub_G}')
    nx.draw(sub_G)
    plt.show()
'''

def transform(nodes, edges):
    Narray = nodes.split(',')
    Earray = edges.split(',')

    N = [int(Narray[i]) for i in range(0, len(Narray), 1)]
    E = [(int(Earray[i]), int(Earray[i+1])) for i in range(0, len(Earray), 2)]
    
    G = nx.Graph()
    G.add_nodes_from(N)
    G.add_edges_from(E)

    return G

def getMaxCoreNumber(nodes, edges):
    G = transform(nodes, edges)
    max_core_number = max(algos.core_number(G).values())
    return max_core_number

def run(nodes, edges, k):
    G = transform(nodes, edges)
    sub_G = algos.k_core(G, k)
    return (list(sub_G.nodes()), list(sub_G.edges))

    '''
    for i in range(max_core_number + 1):
        plt.subplot(int(max_core_number/2) + 1, 2, i+1)
        sub_G = algos.k_core(G, i)
        print(f'{i}-core:{sub_G}')
        nx.draw(sub_G)
        plt.title(f'{i}-core:{sub_G}')
        plt.axis('on')
        plt.xticks([])
        plt.yticks([])
    
    plt.show()
    '''
if __name__ == '__main__':    
    nodes = '''111,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35'''
    edges = '''6,7,111,6,111,7,111,8,1,10,111,11,1,13,111,15,111,17,111,18,111,20,111,21,111,32,1,35'''
    ns, es = run(nodes, edges, 0)
    print(ns)
    print(es)




