import math
import copy
import numpy as np
from sklearn.cluster import DBSCAN
import sklearn.metrics.pairwise as pairwise
import pylab as pl
import random

class Adapter_DBSCAN():
 
    # 默认统计聚类个数在2-25之间的聚类情况, 参数符合python左闭右开
    def __init__(self,num_cluster_range=(2,26)):
        self.num_cluster_range = num_cluster_range
    
 
    def returnEpsCandidate(self,dataSet):
        """
        :param dataSet: 数据集
        :return: eps候选集合
        """
        #self.DistMatrix = self.CalculateDistMatrix(dataSet)
        self.DistMatrix = pairwise.euclidean_distances(dataSet)
        tmp_matrix = copy.deepcopy(self.DistMatrix)
        for i in range(len(tmp_matrix)):
            tmp_matrix[i].sort()
        EpsCandidate = []
        for k in range(1,len(dataSet)):
            #Dk = self.returnDk(tmp_matrix,k)
            Dk = tmp_matrix[:,k]
            # DkAverage = self.returnDkAverage(Dk)
            # 快160+倍
            DkAverage = np.mean(Dk)
            EpsCandidate.append(DkAverage)
        return EpsCandidate
    
 
    def returnMinptsCandidate(self,DistMatrix,EpsCandidate,X):
        """
        :param DistMatrix: 距离矩阵
        :param EpsCandidate: Eps候选列表
        :return: Minpts候选列表
        """
        MinptsCandidate = []
        for k in range(len(EpsCandidate)):
            tmp_eps = EpsCandidate[k]
            tmp_count = 0
            # for i in range(len(DistMatrix)):
            #     for j in range(len(DistMatrix[i])):
            #         if DistMatrix[i][j] <= tmp_eps:
            #             tmp_count = tmp_count + 1
            # 快250+倍
            tmp_count = np.sum(DistMatrix <= tmp_eps)
            MinptsCandidate.append(tmp_count/len(X))
        return MinptsCandidate
    
 
    def fit(self,X):
        self.EpsCandidate = self.returnEpsCandidate(X)
        self.MinptsCandidate = self.returnMinptsCandidate(self.DistMatrix,self.EpsCandidate,X)
        self.do_multi_dbscan(X)
        self.set_num_clusters_range(self.num_cluster_range)
 
 
    def do_multi_dbscan(self,X):
        self.all_predict_dict = {}
        self.all_param_dict = {}
 
        for i in range(len(self.EpsCandidate)):
            eps = self.EpsCandidate[i]
            minpts = self.MinptsCandidate[i]
            db = DBSCAN(eps=eps,min_samples=round(minpts)).fit(X)
            num_clusters = max(db.labels_) + 1
            # 统计符合范围的聚类情况
 
            if num_clusters not in self.all_predict_dict.keys():
                self.all_predict_dict[num_clusters] = []
                self.all_param_dict[num_clusters] = []
 
            self.all_predict_dict[num_clusters].append(db.labels_)
            self.all_param_dict[num_clusters].append({"eps":eps,"minpts":minpts})
 
 
    # 筛选聚类个数，比如Multi-DBSCAN共产生了3聚类、15聚类、136聚类三种情况
    # 我想只看10～20的聚类情况，就可以设置set_num_clusters_range(10~21)后调用get_predict_dict()
    def set_num_clusters_range(self,num_cluster_range:tuple):
        self.predict_dict = {}
        self.param_dict = {}
        # 统计符合范围的聚类情况
 
        for num_cluster, labels, params in zip(self.all_predict_dict.keys(),\
            self.all_predict_dict.values(), self.all_param_dict.values()):
            if num_cluster >= num_cluster_range[0] and \
                num_cluster < num_cluster_range[1]:
                self.predict_dict[num_cluster] = labels
                self.param_dict[num_cluster] = params
 
 
    # 获取当前Multi-DBSCAN的聚类预测信息,格式为{聚类个数:[[预测可能1],[预测可能2],...]}
    # 比如聚类个数为3的情况可能有多种，所以有预测可能1、预测可能2...
    def get_predict_dict(self):
        if self.predict_dict is None:
            raise RuntimeError("get_predict_dict before fit")
        return self.predict_dict
 
 
    # 获取当前Multi-DBSCAN的聚类参数信息,格式为{聚类个数:[{"eps":x1,"minpts":y1},{"eps":x2,"minpts":y2},...]}
    def get_info_dict(self):
        if self.param_dict is None:
            raise RuntimeError("get_info_dict before fit")
        return self.param_dict


def randomcolor():
    colorArr = ['1','2','3','4','5','6','7','8','9','A','B','C','D','E','F']
    color = ""
    for i in range(6):
        color += colorArr[random.randint(0,14)]
    return "#"+color

# 画图
def draw(X, C):
    color = {}
    values = np.unique(C)
    
    for value in values:
        color[value] = randomcolor()
    
    for i in range(len(X)):
        coord_x = X[i][0]
        coord_y = X[i][1]
        c = C[i]
        tmpColor = color[C[i]]
        pl.scatter(coord_x, coord_y, color=color[C[i]])
        
    pl.legend(loc='upper right')
    pl.show()

def run(data):
    a = data.split(',')
    X = np.array([[float(a[i]), float(a[i+1])] for i in range(1, len(a)-1, 3)])

    DB = Adapter_DBSCAN()
    DB.fit(X)
    
    # 输出指定聚类的情况
    DB.set_num_clusters_range((0,124))
    # label预测信息
    predict_dict = DB.get_predict_dict()
    # 参数信息
    info_dict = DB.get_info_dict()

    for key in predict_dict:
        draw(X, predict_dict[key][0])

    # draw(X, predict_dict[4][0])

if __name__ == '__main__':

    X = [[0.697,0.46],[0.774,0.376],[0.634,0.264],[0.608,0.318],[0.556,0.215],
		[0.403, 0.237],[0.481, 0.149],[0.437, 0.211],[0.666, 0.091],[0.243, 0.267],
		[0.245, 0.057],[0.343, 0.099],[0.639, 0.161],[0.657, 0.198],[0.36, 0.37], 
		[0.593, 0.042],[0.719, 0.103],[0.359, 0.188],[0.339, 0.241],[0.282, 0.257],
		[0.748, 0.232],[0.714, 0.346],[0.483, 0.312],[0.478, 0.437],[0.525, 0.369],
		[0.751, 0.489],[0.532, 0.472],[0.473, 0.376],[0.725, 0.445],[0.446, 0.459]]
    
    DB = Adapter_DBSCAN()
    DB.fit(X)
    
    # 输出15聚类的情况
    DB.set_num_clusters_range((4,9))
    # label预测信息
    predict_dict = DB.get_predict_dict()
    # 参数信息
    info_dict = DB.get_info_dict()

    draw(X, predict_dict[4][0])
 
    # print(predict_dict)
    # print("================================")
    # print(info_dict)
    