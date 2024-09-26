from sklearn.cluster import KMeans
import matplotlib.pyplot as plt
import numpy as np
from sklearn.metrics import calinski_harabasz_score
from scipy import spatial
import random
import networkx as nx
import pandas as pd
import scienceplots

def euclDistance(vector1, vector2):
    '''
    计算两个元素之间的欧氏距离
    '''
    return np.sqrt(np.sum(np.power(vector2 - vector1, 2)))

def graphDistance(vector1, vector2, i , j, G, Pos, Nodes):

    dist = euclDistance(vector1, vector2)

    sourceid = Nodes[i]
    targetid = Nodes[j]
    graphDistance = dist
    if(sourceid != targetid):
        edge_data = G.get_edge_data(sourceid, targetid)
        if(edge_data == None):
            if(nx.has_path(G, sourceid, targetid)):
                path = nx.shortest_path(G, sourceid, targetid)
                for i in range(len(path)-2):
                    w = G.get_edge_data(path[i], path[i+1])['weight']
                    d = euclDistance(np.array(position[path[i]]), np.array(position[path[i+1]]))
                    d1 = G.degree(path[i])
                    d2 = G.degree(path[i+1])
                    graphDistance += d * 1.0 / (pow(w, 1.0/(i+1))*d1*d2)
            else:
                graphDistance = dist
        else:
            w = edge_data['weight']
            graphDistance = dist * 1.0 / w

    return graphDistance

def initCentroids(dataSet, k):
    '''
    随机生成K个初始质心
    '''
    numSamples, dim = dataSet.shape #得到dataSet的行和列
    index = random.sample(range(numSamples),k) #随机生成K个不重复的实数，返回一个列表。
    centroids = np.array([dataSet[i,:] for i in index]) #创建K个初始质心放在一个数组中
    return centroids

def doKmeansWithWeight(dataSet, k, G, Pos, Nodes):
    numSamples = dataSet.shape[0]
    clusterAssment = np.zeros((numSamples, 2)) #创建一个numSamples行2列的全零矩阵用于存储元素的所属簇和元素本身
    centroids = initCentroids(dataSet, k) #初始质心
    clusterChanged = True
    while clusterChanged:
        clusterChanged = False
        for i in range(numSamples):
            #遍历每一个元素
            minDistance = float("inf")  #设定元素与质心之间的初始距离为无穷大
            ownGroup = 0 #设定元素初始所属簇
            for j in range(k):
                #计算第i个元素分别与k个质心的距离
                # distance = euclDistance(centroids[j, :], dataSet[i, :])
                distance = graphDistance(centroids[j, :], dataSet[i, :], i, j, G, Pos, Nodes)
                if distance < minDistance:
                    #把元素归为与质心欧式距离最小的那个簇中
                    minDistance = distance
                    ownGroup = j
            if clusterAssment[i, 1] != ownGroup:
                #判断该元素所属组是否发生变化，若变化了就继续进行循环，直到每个元素所属组不在变化就结束循环
                clusterAssment[i, 1] = ownGroup
                clusterChanged = True
        for j in range(k):
            '''
            遍历完所有元素后更新K个质心
            clusterAssment[:, 1] == j #判断每个元素是否属于j组，是的话就返回True,否则返回False
            np.nonzero(clusterAssment[:, 1] == j)[0] #返回一个有两个元素的tuple,第一个元素是这个数组(元素是布尔值的形式)中元素是True的下标
            dataSet[np.nonzero(clusterAssment[:, 1] == j)[0]] #得到属于某个组的全部元素
            np.mean(pointsInCluster, axis=0) #计算每一个簇中所有元素的均值作为各自簇的新的质心
            '''
            pointsInCluster = dataSet[np.nonzero(clusterAssment[:, 1] == j)[0]]
            centroids[j, :] = np.mean(pointsInCluster, axis=0)
        
        labels = []
        for i in range(numSamples):
            labels.append(int(clusterAssment[i, 1]))

    return centroids,labels


if __name__ == '__main__':
    # data_pd = pd.read_csv("D:\\Workspace\\geograph-master\\test\\ShareBikes\\Bikeshare_Washington_nodes.txt")
    # header_label = list(data_pd.columns.values)
    
    # 加载节点和连边数据
    data_nodes = pd.read_csv("D:\\Workspace\\geograph-master\\test\\ShareBikes\\Bikeshare_NewYork_202302_nodes.txt")
    data_edges = pd.read_csv("D:\\Workspace\\geograph-master\\test\\ShareBikes\\Bikeshare_NewYork_202302_edges.txt")

    position = {}
    nodes = {}
    for item in data_nodes.itertuples():
        '''
        if(type(item[4]) == str or type(item[3]) == str ):
            print(item)
        if(item[4] < 5 and item[3] < 5):
            print(item)
        '''
        position[item[2]] = [float(item[4]), float(item[3])]
        nodes[item[0]] = item[2]

    X = np.array(list(position.values()))

    edges = [edge for edge in zip(data_edges['source'], data_edges['target'], data_edges['times'])]
    G = nx.DiGraph()
    G.add_weighted_edges_from(edges)
    G.remove_edges_from(nx.selfloop_edges(G)) # 删除自循环边

    centroids,labels = doKmeansWithWeight(X, 
                       14, 
                       G,
                       position,
                       nodes)
    
    # plt.title('San Francisco')
    # plt.text(-87, 42, 'k='+f'{k}', 
    #     bbox={'facecolor': 'white', #填充色
    #           'edgecolor':'gray',#外框色
    #           'alpha': 1.0, #框透明度   
    #           'pad': 2,#本文与框周围距离
    #          })
    plt.style.use(['science','grid'])
    plt.title('New York')
    plt.scatter(X[:,0], X[:,1], c=labels, marker='o', alpha=0.4)
    plt.show()

    # 归一化处理
    # max_times = max(data_graph['times'])
    # data_graph['times'] /= 1.0*max_times
    '''
    edges = [edge for edge in zip(data_edges['source'], data_edges['target'], data_edges['times'])]

    G = nx.DiGraph()
    G.add_weighted_edges_from(edges)
    G.remove_edges_from(nx.selfloop_edges(G)) # 删除自循环边
    # w = G.get_edge_data(31002, 31090)['weight']
    print(G)
    '''