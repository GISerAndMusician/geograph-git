import networkx as nx

def transform(nodes, edges):
    Narray = nodes.split(',')
    Earray = edges.split(',')

    N = [int(Narray[i]) for i in range(0, len(Narray), 1)]
    E = [(int(Earray[i]), int(Earray[i+1])) for i in range(0, len(Earray), 2)]
    
    G = nx.Graph()
    G.add_nodes_from(N)
    G.add_edges_from(E)

    return G

def run(nodes, edges, subNodes):
    G  =transform(nodes, edges)
    v = len(G.nodes)
    e = len(G.edges)
    d = dict(nx.degree(G))
    k = sum(d.values()) / len(G.nodes)

    nodesArray = subNodes.split(',')
    N = [int(nodesArray[i]) for i in range(0, len(nodesArray), 1)]
    subG = G.subgraph(N)

    vv = len(subG.nodes) #节点数
    ee = len(subG.edges) #连边数
    rr = 1 - (k*vv + ee)*1.0 / (k*v + e) #压缩比

    print(rr)
    return (rr, vv, ee)


import community

if __name__ == '__main__': 
    # nodes = '''111,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35'''
    # edges = '''6,7,111,6,111,7,111,8,1,10,111,11,1,13,111,15,111,17,111,18,111,20,111,21,111,32,1,35'''
    # subNodes = '''111,2,3,4,5,6,7,8,9,10'''
    # run(nodes, edges, subNodes)

    G = nx.les_miserables_graph()
    partition = community.best_partition(G)

    for node, community in partition.items():
        print(f"Node {node} is in community {community}")

