from sklearn.cluster import KMeans
import matplotlib.pyplot as plt
import numpy as np
from sklearn.metrics import calinski_harabasz_score
from scipy import spatial
import scienceplots

def adaptive_kmeans(X, max_k=10, tol=0.005):
    k = 2  # 初始k值设为2
    best_k = k  # 最佳k值初始化
    best_model = None  # 最佳模型初始化
    calinski_harabaz_scores = []  # Calinski-Harabaz分数列表
 
    while k <= max_k:
        # 使用K均值算法进行聚类
        model = KMeans(n_clusters=k)
        model.fit(X)

        # 计算Calinski-Harabaz分数
        ch_score = calinski_harabasz_score(X, model.labels_)
        calinski_harabaz_scores.append(ch_score)
 
        # 如果发现更好的分数，更新最佳模型和最佳k值
        if best_model is None or ch_score > calinski_harabaz_scores[best_k - 1]:
            best_k = k
            best_model = model
 
        # 如果分数没有显著提升，则停止迭代
        if len(calinski_harabaz_scores) > 1 and \
               abs(calinski_harabaz_scores[-1] - calinski_harabaz_scores[-2]) / calinski_harabaz_scores[-2] < tol:
            break
 
        k += 1  # 迭代k值
    
    print(calinski_harabaz_scores)

    return best_model, best_k

def distance_euclidean_scipy(vec1, vec2, distance="euclidean"):
    return spatial.distance.cdist(vec1, vec2, distance)

def doKmeansWithWeight(ds, w, k, showImage = True):
    """k-means聚类算法
    k       - 指定分簇数量
    ds      - ndarray(m, n)，m个样本的数据集，每个样本n个属性值
    """
    m, n = ds.shape  # m：样本数量，n：每个样本的属性值个数
    result = np.empty(m, dtype=np.int16)  # m个样本的聚类结果
    cores = ds[np.random.choice(np.arange(m), k, replace=False)]  # 从m个数据样本中不重复地随机选择k个样本作为质心
 
    while True:  # 迭代计算
        # d = np.square(np.repeat(ds, k, axis=0).reshape(m, k, n) - cores)
        # print("d.first.shape -> ", d.shape)
        # distance = np.sqrt(np.sum(d, axis=2))  # ndarray(m, k)，每个样本距离k个质心的距离，共有m行
 
        distance = distance_euclidean_scipy(ds, cores)
        index_min = np.argmin(distance, axis=1)  # 每个样本距离最近的质心索引序号
 
        if (index_min == result).all():  # 如果样本聚类没有改变
            return result, cores  # 则返回聚类结果和质心数据
 
        result[:] = index_min  # 重新分类
        for i in range(k):  # 遍历质心集
            items = ds[result == i]  # 找出对应当前质心的子样本集
            cores[i] = np.mean(items, axis=0)  # 以子样本集的均值作为当前质心的位置

def doKmeans(data, c , showImage = True):
    a = data.split(',')
    X = np.array([[float(a[i]), float(a[i+1])] for i in range(1, len(a)-1, 3)])

    # A. 使用自自适应Kmeans方法
    # kmModel, k = adaptive_kmeans(X, max_k=c)
    # print(f"最佳K值: {k}")
    # B. 使用指定参数Kmeans方法
    kmModel = KMeans(c).fit(X)
    
    if(showImage):
        plt.style.use(['science','grid'])
        # plt.title('San Francisco')
        # plt.text(-87, 42, 'k='+f'{k}', 
        #     bbox={'facecolor': 'white', #填充色
        #           'edgecolor':'gray',#外框色
        #           'alpha': 1.0, #框透明度   
        #           'pad': 2,#本文与框周围距离
        #          })
        plt.scatter(X[:,0], X[:,1], c=kmModel.labels_, marker='o', alpha=0.4)
        plt.show()

    return kmModel.labels_.tolist()

if __name__ == '__main__':

    plt.style.use(['science','grid'])

    data = """1,0.697,0.46,2,0.774,0.376,3,0.634,0.264,4,0.608,0.318,5,0.556,0.215,
		6, 0.403, 0.237, 7, 0.481, 0.149, 8, 0.437, 0.211, 9, 0.666, 0.091, 10, 0.243, 0.267,
		11, 0.245, 0.057, 12, 0.343, 0.099, 13, 0.639, 0.161, 14, 0.657, 0.198, 15, 0.36, 0.37,
		16, 0.593, 0.042, 17, 0.719, 0.103, 18, 0.359, 0.188, 19, 0.339, 0.241, 20, 0.282, 0.257,
		21, 0.748, 0.232, 22, 0.714, 0.346, 23, 0.483, 0.312, 24, 0.478, 0.437, 25, 0.525, 0.369,
		26, 0.751, 0.489, 27, 0.532, 0.472, 28, 0.473, 0.376, 29, 0.725, 0.445, 30, 0.446, 0.459"""
    
    # doKmeans(data, 5)

    w = [[1, 2, 0.00],[]]

    a = data.split(',')
    X = np.array([[float(a[i]), float(a[i+1])] for i in range(1, len(a)-1, 3)])
    print(X)
    result = doKmeansWithWeight(X, 1, 5)
    plt.style.use(['science','grid'])
    # plt.title('San Francisco')
    # plt.text(-87, 42, 'k='+f'{k}', 
    #     bbox={'facecolor': 'white', #填充色
    #           'edgecolor':'gray',#外框色
    #           'alpha': 1.0, #框透明度   
    #           'pad': 2,#本文与框周围距离
    #          })
    plt.scatter(X[:,0], X[:,1], c=result[0], marker='o', alpha=0.4)
    plt.show()
    