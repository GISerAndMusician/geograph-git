import networkx as nx
import numpy as np

# 读取CSV文件并创建网络
def read_csv_file(file_path):
    G = nx.Graph()

    # 从CSV文件中读取数据并添加节点和连边
    with open(file_path, 'r') as file:
        for line in file:
            nodes = line.strip().split(',')
            node1 = nodes[0]
            node2 = nodes[1]
            G.add_node(node1)
            G.add_node(node2)
            G.add_edge(node1, node2)
    
    return G

# 计算两个网络的相似度矩阵
def calculate_similarity_matrix(G1, G2):
    A1 = np.array(nx.adjacency_matrix(G1).todense())
    A2 = np.array(nx.adjacency_matrix(G2).todense())
    n = A1.shape[0]
    S = np.zeros((n, n))
    
    for i in range(n):
        for j in range(n):
            S[i, j] = 1 - np.sum(A1[i, :] != A2[j, :]) / n
    
    return S

if __name__ == '__main__':   
    file_path1 = 'D:\\文档\\02_论文\\发表论文\\《一种顾及空间分布特征的大规模空间交互网络骨架提取方法》\\resource\\backbone\\Washington\\entropy\\Washington_20%_edge.csv'
    file_path2 = 'D:\\Workspace\\geograph-master\\test\\ShareBikes\\Bikeshare_Washington_202301_202312_edges.txt'
    graph1 = read_csv_file(file_path1)
    graph2 = read_csv_file(file_path2)

    G1 = nx.Graph([(1, 2), (2, 3), (1, 3)])
    G2 = nx.Graph([(1, 2), (2, 3), (1, 3)])
    # dist = nx.graph_edit_distance(graph1, graph2)
    print(calculate_similarity_matrix(graph1, graph2))


