# -*- coding: utf-8 -*-
import networkx as nx
import matplotlib.pyplot as plt
import numpy as np

import networkx.algorithms as algos
import scienceplots

# reference: https://github.com/dange-academic/Modeling_complex_networks
'''
nodes = [1,2,3,4,5,6,7,8,9,10]
edges = [(1,2),(1,3),(1,5),(1,6),(3,7)]

G = nx.Graph()
G.add_nodes_from(nodes)
G.add_edges_from(edges)
nx.draw(G, with_labels = False)
plt.show()
'''

#n = 10000
#p = 0.01
#ER = nx.erdos_renyi_graph(n, p)

'''
import igraph as ig
import matplotlib.pyplot as plt

er_graph = ig.Graph.Erdos_Renyi(n=10000, m=20000)
pic = ig.plot(er_graph,'20240323-plot.png')
'''

def centrality(G_list, labelNames, pointSybols, lineSymbols, colors, opacities):
    dc_list = []
    bc_list = []
    cc_list = []
    ec_list = []
    dc_sorted_list = []
    bc_sorted_list = []
    cc_sorted_list = []
    ec_sorted_list = []
    dc_cdf_list = []
    bc_cdf_list = []
    cc_cdf_list = []
    ec_cdf_list = []
    for i in range(len(G_list)):
        G = G_list[i]

        dc = nx.degree_centrality(G)
        bc = nx.betweenness_centrality(G)
        cc = nx.closeness_centrality(G)
        ec = nx.eigenvector_centrality(G)

        dc_sorted = sorted(dc.values())
        dc_cdf = np.arange(len(dc_sorted)) / (len(dc_sorted) - 1)

        print('平均度中心性：')
        print(sum(dc.values()) / len(dc))

        bc_sorted = sorted(bc.values())
        bc_cdf = np.arange(len(bc_sorted)) / (len(bc_sorted) - 1)

        print('平均中介中心性：')
        print(sum(bc.values()) / len(bc))

        cc_sorted = sorted(cc.values())
        cc_cdf = np.arange(len(cc_sorted)) / (len(cc_sorted) - 1)

        print('平均接近中心性：')
        print(sum(cc.values()) / len(cc))

        ec_sorted = sorted(ec.values())
        ec_cdf = np.arange(len(ec_sorted)) / (len(ec_sorted) - 1)

        print('平均特征向量中心性：')
        print(sum(ec.values()) / len(ec))

        dc_list.append(dc)
        bc_list.append(bc)
        cc_list.append(cc)
        ec_list.append(ec)

        dc_sorted_list.append(dc_sorted)
        bc_sorted_list.append(bc_sorted)
        cc_sorted_list.append(cc_sorted)
        ec_sorted_list.append(ec_sorted)

        dc_cdf_list.append(dc_cdf)
        bc_cdf_list.append(bc_cdf)
        cc_cdf_list.append(cc_cdf)
        ec_cdf_list.append(ec_cdf)

    plt.figure()
    plt.subplot(221)
    for i in range(len(G_list)):
        plt.plot(dc_sorted_list[i], 
                 dc_cdf_list[i], 
                 pointSybols[i]+lineSymbols[i], 
                 alpha = float(opacities[i])/100.0, 
                 label=labelNames[i], 
                 color=colors[i])
    plt.legend(loc = 0)
    plt.xlabel('Value of Degree Centrality')
    plt.ylabel('$P_k$')
    plt.title('CDF of Degree Centrality')

    plt.subplot(222)
    for i in range(len(G_list)):
        plt.plot(bc_sorted_list[i], 
                 bc_cdf_list[i], 
                 pointSybols[i]+lineSymbols[i], 
                 alpha = float(opacities[i])/100.0, 
                 label=labelNames[i], 
                 color=colors[i])
    plt.legend(loc = 0)
    plt.xlabel('Value of Betweeness Centrality')
    plt.ylabel('$P_k$')
    plt.title('CDF of Betweenness Centrality')

    plt.subplot(223)
    for i in range(len(G_list)):
        plt.plot(cc_sorted_list[i], 
                 cc_cdf_list[i], 
                 pointSybols[i]+lineSymbols[i], 
                 alpha = float(opacities[i])/100.0, 
                 label=labelNames[i], 
                 color=colors[i])
    plt.legend(loc = 0)
    plt.xlabel('Value of Closeness Centrality')
    plt.ylabel('$P_k$')
    plt.title('CDF of Closeness Centrality')

    plt.subplot(224)
    for i in range(len(G_list)):
        plt.plot(ec_sorted_list[i], 
                 ec_cdf_list[i], 
                 pointSybols[i]+lineSymbols[i], 
                 alpha = float(opacities[i])/100.0, 
                 label=labelNames[i], 
                 color=colors[i])
    plt.legend(loc = 0)
    plt.xlabel('Value of Eigenvector Centrality')
    plt.ylabel('$P_k$')
    plt.title('CDF of Eigenvector Centrality')

    plt.subplots_adjust(left=0.1, right=0.9, bottom=0.1, top=0.9, wspace=0.3, hspace=0.3)
    # plt.tight_layout()
    plt.show()

    return (dc_list, bc_list, cc_list, ec_list)

def degreeDistribution(G = nx.Graph()):

    # 计算平均度
    d = dict(nx.degree(G))
    print("平均度为：", sum(d.values()) / len(G.nodes))

    x = list(range(max(d.values()) + 1))
    # y = [i/G.number_of_nodes() for i in nx.degree_histogram(G)]
    
    y = []
    cdf = 0
    for i in nx.degree_histogram(G):
        cdf += i/G.number_of_nodes()
        y.append(cdf)

    plt.plot(x, y, 'ro-')
    plt.xlabel('$k$')
    plt.ylabel('$P_k$')

    plt.tight_layout()
    plt.show()

# 定义求最近邻平均度的函数
def average_nearest_neighbor_degree(G):
    k = set([G.degree(i) for i in G.nodes()])
    sorted_k = sorted(k)
    knni = nx.average_neighbor_degree(G)

    k_nn_k = []
    for ki in sorted_k:
        if ki == 0:
            k_nn_k.append(0.0)
        else:
            c = 0
            s = 0
            for i in G.nodes():
                if G.degree(i) == ki:
                    s += knni[i]
                    c += 1
            k_nn_k.append(s / c)
    return sorted_k, k_nn_k

# 基于Pearson相关系数的度-度相关性
def pearson_correlation_coefficient(G = nx.Graph()):
    x, y = average_nearest_neighbor_degree(G)
    r = nx.degree_pearson_correlation_coefficient(G)

    plt.plot(x, y, 'ro', label='r = '+'%.4f'%r)
    plt.legend(loc=0)
    plt.xlabel("$k$")
    plt.ylabel("$k_{nn}(k)$")
    plt.xscale("log")
    plt.yscale("log")
    plt.title('citation')
    plt.ylim([1,200])
    plt.tight_layout()

    plt.show()

# 富人俱乐部系数
def rich_club_coef(G):
    rcc = nx.rich_club_coefficient(G, normalized=True)
    data_sorted = sorted(rcc.values())
    cdf = np.arange(len(data_sorted)) / (len(data_sorted) - 1)

    plt.plot(data_sorted, cdf, 'ro')
    plt.title('CDF of rich club coefficient')
    plt.xlabel('value')
    plt.ylabel('CDF')
    plt.show()

    '''
    plt.figure()
    plt.plot(rcc.keys(), rcc.values(), 'ro-')
    plt.legend(loc = 0)
    plt.xlabel('node label')
    plt.ylabel('dc')
    plt.title('rich club coefficient')
    plt.show()
    '''

def has_chinese(text):
    for char in text:
        if '\u4e00' <= char <= '\u9fff':
            return True
    return False

def run(graphs_nodes, graphs_edges, labelNames, pointSybols, lineSymbols, colors, opacities):
    G_Narray = graphs_nodes.split('\n')
    G_Earray = graphs_edges.split('\n')

    G_list = []
    
    for i in range(len(G_Narray)):
        nodes = G_Narray[i]
        edges = G_Earray[i]
        Narray = nodes.split(',')
        Earray = edges.split(',')

        N = [int(Narray[i]) for i in range(0, len(Narray), 1)]
        E = [(int(Earray[i]), int(Earray[i+1])) for i in range(0, len(Earray), 2)]
    
        G = nx.Graph()
        G.add_nodes_from(N)
        G.add_edges_from(E)
        G_list.append(G)

    labelNames_list = labelNames.split(',')
    pointSybols_list = pointSybols.split(',')
    lineSymbols_list = lineSymbols.split(',')
    colors_list = colors.split(',')
    opacities_list = opacities.split(',')

    # 判断是否含有中文，如果有则不启用SciencePlot
    bContainsChinese = False
    for i in range(len(labelNames_list)):
        if has_chinese(labelNames_list[i]):
            bContainsChinese = True
    if not bContainsChinese:
        plt.style.use(['science','grid'])
    else:
        plt.style.use(['science','grid','no-latex'])
        plt.rcParams['font.family'] = 'SimSun'

    C = centrality(G_list, labelNames_list, pointSybols_list, lineSymbols_list, colors_list, opacities_list)
    # pearson_correlation_coefficient(G)
    # rich_club_coef(G)

    return C


if __name__ == '__main__':    
    graphs_nodes = '''1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35\n1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35'''
    graphs_edges = '''6,7,1,6,1,7,1,8,1,10,1,11,1,13,1,42,1,45,1,53,1,57,1,71,1,88,1,163\n6,7,1,6,1,7,1,8,1,10,1,11,1,13,1,42'''
    labelNames = '''图100%graph,50%graph'''
    pointSybols = '''o,o'''
    lineSymbols = '''-,-'''
    colors = '''#6A5ACD,#008B45'''
    opacities = '''30,30'''
    run(graphs_nodes, graphs_edges, labelNames, pointSybols, lineSymbols, colors, opacities)

    # nodes = '''1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35'''
    # edges = '''6,7,1,6,1,7,1,8,1,10,1,11,1,13,1,42,1,45,1,53,1,57,1,71,1,88,1,163'''

