import numpy as np
import pylab as pl

class SOM(object):
    def __init__(self, X, output, interation, bactch_size):
        # param X: 形状是N*D，输入样本有N个，每个D维
        # param output: (n,m)一个元组，为输出层的形状，是一个n*m的二维矩阵
        # param interation: 迭代次数
        # param batch_size: 每次迭代时的样本数量 
        self.X = X
        self.output = output
        self.interation = interation
        self.batch_size = bactch_size
        self.W = np.random.rand(X.shape[1], output[0]*output[1])
        print(self.W.shape)

    def getN(self, t):
        # param t: 时间t，这里用迭代次数来表示时间
        # return: 返回一个整数，表示拓扑距离，时间越大，拓扑邻域越小
        a = min(self.output)
        return int(a - float(a)*t / self.interation)
    
    def getEta(self, t, n):
        # param t: 时间t，这里用迭代次数来表示时间
        # param n: 拓扑距离
        # return: 返回学习率
        return np.power(np.e, -n) / (t + 2)
    
    def updateW(self, X, t, winner):
        N = self.getN(t)
        for x, i in enumerate(winner):
            to_update = self.getNeighbor(i[0], N)
            for j in range(N + 1):
                e = self.getEta(t, j)
                for w in to_update[j]:
                    self.W[:, w] = np.add(self.W[:, w], e*(X[x, :] - self.W[:, w]))
    
    def getNeighbor(self, index, N):
        # param index: 获胜神经元的下标
        # param N: 邻域半径
        # return ans: 返回一个集合列表，分别是不同邻域半径内需要更新的神经元坐标
        a, b = self.output
        length = a*b
        def distance(index1, index2):
            i1_a, i1_b = index1 // a, index1 % b
            i2_a, i2_b = index2 // a, index2 % b
            return np.abs(i1_a - i2_a), np.abs(i1_b - i2_b)
        
        ans = [set() for i in range(N + 1)]
        for i in range(length):
            dist_a, dist_b = distance(i, index)
            if dist_a <= N and dist_b <= N : ans[max(dist_a, dist_b)].add(i)
        return ans
    
    def train(self):
        # train_Y: 训练样本与形状为batch_size*(n*m)
        # winner: 一个一维向量，batch_size个获胜神经元的下标
        # return: 返回值是调整后的W
        count = 0
        while self.interation > count:
            train_X = self.X[np.random.choice(self.X.shape[0], self.batch_size)]
            normal_W(self.W)
            normal_X(train_X)
            train_Y = train_X.dot(self.W)
            winner = np.argmax(train_Y, axis=1).tolist()
            self.updateW(train_X, count, winner)
            count += 1
        return self.W
    
    def train_result(self):
        normal_X(self.X)
        train_Y = self.X.dot(self.W)
        winner = np.argmax(train_Y, axis=1).tolist()
        print(winner)
        return winner
    
def normal_X(X):
    N, D = X.shape
    for i in range(N):
        temp = np.sum(np.multiply(X[i], X[i]))
        X[i] /= np.sqrt(temp)
    return X

def normal_W(W):
    for i in range(W.shape[1]):
        temp = np.sum(np.multiply(W[:, i], W[:, i]))
        W[:, i] /= np.sqrt(temp)
    return W

# 画图
def draw(C):
    colValue = ['r', 'y', 'g', 'b', 'c', 'k', 'm']
    for i in range(len(C)):
        coo_X = []    # x坐标列表
        coo_Y = []    # y坐标列表
        for j in range(len(C[i])):
            coo_X.append(C[i][j][0])
            coo_Y.append(C[i][j][1])
        pl.scatter(coo_X, coo_Y, marker='x', color=colValue[i%len(colValue)], label=i)

    pl.legend(loc='upper right')
    pl.show()

def run(data):
    #数据集：每三个是一组分别是西瓜的编号，密度，含糖量

    a = data.split(',')
    dataset = np.mat([[float(a[i]), float(a[i+1])] for i in range(1, len(a)-1, 3)])
    dataset_old = dataset.copy()

    som = SOM(dataset, (5, 5), 10, 20)
    som.train()
    res = som.train_result()
    classify = {}
    for i, win in enumerate(res):
        if not classify.get(win[0]):
            classify.setdefault(win[0], [i])
        else:
            classify[win[0]].append(i)
    C = []#未归一化的数据分类结果
    D = []#归一化的数据分类结果
    for i in classify.values():
        C.append(dataset_old[i].tolist())
        D.append(dataset[i].tolist())
    draw(C)
    draw(D)