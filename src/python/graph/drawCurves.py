import matplotlib.pyplot as plt
import numpy as np
from mpl_toolkits.mplot3d import Axes3D
import scienceplots

plt.style.use(['science','grid'])

xspan = 0.3
yspan = 0.02

def drawNewYork():
    xspan = 0.8
    plt.subplot(221)
    X1 = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82]
    Y1 = [0.16691,0.167306,0.167705,0.168103,0.168499,0.168894,0.16929,0.169683,0.170081,0.170477,0.170881,0.171279,0.17168,0.172076,0.172474,0.172875,0.173282,0.173683,0.174084,0.174488,0.174889,0.175282,0.175686,0.17609,0.176491,0.176894,0.177298,0.177705,0.178103,0.178507,0.178914,0.17932,0.179719,0.180131,0.18054,0.180944,0.18135,0.181762,0.182169,0.182578,0.182993,0.183392,0.183806,0.184218,0.184633,0.18504,0.185455,0.185861,0.186273,0.186674,0.187084,0.187496,0.187908,0.188303,0.188715,0.18913,0.189534,0.189943,0.190358,0.190765,0.191179,0.191597,0.192015,0.192429,0.192844,0.193262,0.193655,0.194078,0.1945,0.194918,0.195333,0.195753,0.196171,0.196588,0.196992,0.197409,0.19783,0.198245,0.198665,0.199093,0.199516,0.199936]

    X2 = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78]
    Y2 = [0.366812,0.367235,0.367658,0.368076,0.368488,0.368905,0.369323,0.36974,0.370144,0.370562,0.370976,0.371397,0.371825,0.372248,0.372679,0.373099,0.373525,0.373956,0.374379,0.374805,0.375223,0.375626,0.376052,0.376451,0.376852,0.377272,0.377692,0.378118,0.378546,0.378983,0.379417,0.379829,0.380249,0.380683,0.38112,0.381551,0.38198,0.382411,0.382839,0.383273,0.383702,0.384141,0.384578,0.385014,0.385448,0.385882,0.386319,0.386756,0.387195,0.387629,0.388071,0.38851,0.388953,0.389397,0.38979,0.390186,0.390639,0.391081,0.391526,0.391974,0.392419,0.392866,0.393314,0.393764,0.394212,0.394632,0.395074,0.395524,0.395934,0.396381,0.396832,0.397233,0.397689,0.398142,0.398603,0.399064,0.39946,0.399921]

    X3 = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19]
    Y3 = [0.592107,0.592544,0.592994,0.593403,0.59384,0.594285,0.594686,0.595136,0.595589,0.596045,0.596498,0.596894,0.597352,0.597806,0.59822,0.598673,0.599135,0.59953,0.599983]

    X4 = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26]
    Y4 = [0.817884,0.817171,0.816477,0.815775,0.815076,0.81432,0.81359,0.812864,0.812121,0.811375,0.810648,0.809938,0.809173,0.808411,0.807693,0.806958,0.806256,0.80548,0.804753,0.803942,0.803139,0.802385,0.801617,0.800882,0.800139,0.799374]

    plt.plot(X1, Y1, marker = "o", markersize=6, markerfacecolor='#C2D1EB', markeredgewidth=0.5, linewidth=0.5, linestyle='-', color='k', label="20 percentage")
    plt.axvspan(xmin=X1[len(X1) - 1]-xspan, xmax=X1[len(X1) - 1]+xspan, facecolor="r",alpha=0.2)
    plt.axhspan(ymin=min(Y1) - yspan, ymax=max(Y1) + yspan, facecolor="b", alpha=0.1)

    plt.plot(X2, Y2, marker = "o", markersize=6, markerfacecolor='#96B0DD', markeredgewidth=0.5, linewidth=0.5, linestyle='-', color='k', label="40 percentage")
    plt.axvspan(xmin=X2[len(X2) - 1]-xspan, xmax=X2[len(X2) - 1]+xspan, facecolor="r",alpha=0.2)
    plt.axhspan(ymin=min(Y2) - yspan, ymax=max(Y2) + yspan, facecolor="b", alpha=0.1)

    plt.plot(X3, Y3, marker = "o", markersize=6, markerfacecolor='#6B90D0', markeredgewidth=0.5, linewidth=0.5, linestyle='-', color='k', label="60 percentage")
    plt.axvspan(xmin=X3[len(X3) - 1]-xspan, xmax=X3[len(X3) - 1]+xspan, facecolor="r",alpha=0.2)
    plt.axhspan(ymin=min(Y3) - yspan, ymax=max(Y3) + yspan, facecolor="b", alpha=0.1)

    plt.plot(X4, Y4, marker = "o", markersize=6, markerfacecolor='#4472C4', markeredgewidth=0.5, linewidth=0.5, linestyle='-', color='k', label="80 percentage")
    plt.axvspan(xmin=X4[len(X4) - 1]-xspan, xmax=X4[len(X4) - 1]+xspan, facecolor="r",alpha=0.2)
    plt.axhspan(ymin=min(Y4) - yspan, ymax=max(Y4) + yspan, facecolor="b", alpha=0.1)

    plt.title("New York")
    plt.legend(loc="upper right")
    plt.xlabel('epoch')
    plt.ylabel('compression ratio')

def drawWashington():
    plt.subplot(223)
    X1 = [1,2,3,4,5,6,7]
    Y1 = [0.211576,0.209393,0.20719,0.204937,0.202696,0.20048,0.198281]

    X2 = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16]
    Y2 = [0.429696,0.427735,0.425725,0.423731,0.421742,0.419744,0.417738,0.415695,0.413656,0.411654,0.409636,0.407663,0.405607,0.403523,0.40146,0.399425]

    X3 = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24]
    Y3 = [0.639376,0.637666,0.635936,0.634157,0.632426,0.630696,0.628937,0.627215,0.625435,0.623697,0.621959,0.620208,0.618461,0.61669,0.614951,0.613176,0.611404,0.60965,0.607874,0.606115,0.604348,0.602597,0.600793,0.599001]

    X4 = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29]
    Y4 = [0.838738,0.837391,0.836051,0.834675,0.833303,0.831923,0.830542,0.829174,0.82779,0.826418,0.825017,0.823608,0.822227,0.820831,0.81945,0.818037,0.81662,0.815202,0.813773,0.812363,0.810975,0.809541,0.808103,0.806682,0.805235,0.803806,0.802372,0.800913,0.799451]

    plt.plot(X1, Y1, marker = "o", markersize=6, markerfacecolor='#C2D1EB', markeredgewidth=0.5, linewidth=0.5, linestyle='-', color='k', label="20 percentage")
    plt.axvspan(xmin=X1[len(X1) - 1]-xspan, xmax=X1[len(X1) - 1]+xspan, facecolor="r",alpha=0.2)
    plt.axhspan(ymin=min(Y1) - yspan, ymax=max(Y1) + yspan, facecolor="b", alpha=0.1)

    plt.plot(X2, Y2, marker = "o", markersize=6, markerfacecolor='#96B0DD', markeredgewidth=0.5, linewidth=0.5, linestyle='-', color='k', label="40 percentage")
    plt.axvspan(xmin=X2[len(X2) - 1]-xspan, xmax=X2[len(X2) - 1]+xspan, facecolor="r",alpha=0.2)
    plt.axhspan(ymin=min(Y2) - yspan, ymax=max(Y2) + yspan, facecolor="b", alpha=0.1)

    plt.plot(X3, Y3, marker = "o", markersize=6, markerfacecolor='#6B90D0', markeredgewidth=0.5, linewidth=0.5, linestyle='-', color='k', label="60 percentage")
    plt.axvspan(xmin=X3[len(X3) - 1]-xspan, xmax=X3[len(X3) - 1]+xspan, facecolor="r",alpha=0.2)
    plt.axhspan(ymin=min(Y3) - yspan, ymax=max(Y3) + yspan, facecolor="b", alpha=0.1)

    plt.plot(X4, Y4, marker = "o", markersize=6, markerfacecolor='#4472C4', markeredgewidth=0.5, linewidth=0.5, linestyle='-', color='k', label="80 percentage")
    plt.axvspan(xmin=X4[len(X4) - 1]-xspan, xmax=X4[len(X4) - 1]+xspan, facecolor="r",alpha=0.2)
    plt.axhspan(ymin=min(Y4) - yspan, ymax=max(Y4) + yspan, facecolor="b", alpha=0.1)


    plt.title("Washington")
    plt.legend(loc="lower right")
    plt.xlabel('epoch')
    plt.ylabel('compression ratio')

def drawSanFrancisco():
    plt.subplot(224)
    X1 = [1,2,3,4]
    Y1 = [0.207022,0.204348,0.201681,0.198979]

    X2 = [1,2,3,4,5,6,7,8,9,10,11,12,13,14]
    Y2 = [0.431923,0.429397,0.426914,0.424409,0.421939,0.419448,0.416929,0.41434,0.411856,0.409394,0.406868,0.404313,0.40178,0.399212]

    X3 = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25]
    Y3 = [0.651258,0.649092,0.646918,0.644745,0.642578,0.640398,0.638196,0.636001,0.63382,0.631598,0.629417,0.627187,0.624943,0.622748,0.62061,0.618422,0.616213,0.613962,0.611725,0.609481,0.607258,0.605036,0.602799,0.600547,0.59831]

    X4 = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28]
    Y4 = [0.846496,0.844837,0.843171,0.841498,0.839818,0.838131,0.836437,0.834736,0.833027,0.831312,0.829589,0.82786,0.826131,0.824387,0.822636,0.820879,0.819114,0.817342,0.815585,0.813799,0.812006,0.810206,0.808399,0.806592,0.804771,0.80295,0.801115,0.799308]

    plt.plot(X1, Y1, marker = "o", markersize=6, markerfacecolor='#C2D1EB', markeredgewidth=0.5, linewidth=0.5, linestyle='-', color='k', label="20 percentage")
    plt.axvspan(xmin=X1[len(X1) - 1]-xspan, xmax=X1[len(X1) - 1]+xspan, facecolor="r",alpha=0.2)
    plt.axhspan(ymin=min(Y1) - yspan, ymax=max(Y1) + yspan, facecolor="b", alpha=0.1)
    

    plt.plot(X2, Y2, marker = "o", markersize=6, markerfacecolor='#96B0DD', markeredgewidth=0.5, linewidth=0.5, linestyle='-', color='k', label="40 percentage")
    plt.axvspan(xmin=X2[len(X2) - 1]-xspan, xmax=X2[len(X2) - 1]+xspan, facecolor="r",alpha=0.2)
    plt.axhspan(ymin=min(Y2) - yspan, ymax=max(Y2) + yspan, facecolor="b", alpha=0.1)

    plt.plot(X3, Y3, marker = "o", markersize=6, markerfacecolor='#6B90D0', markeredgewidth=0.5, linewidth=0.5, linestyle='-', color='k', label="60 percentage")
    plt.axvspan(xmin=X3[len(X3) - 1]-xspan, xmax=X3[len(X3) - 1]+xspan, facecolor="r",alpha=0.2)
    plt.axhspan(ymin=min(Y3) - yspan, ymax=max(Y3) + yspan, facecolor="b", alpha=0.1)

    plt.plot(X4, Y4, marker = "o", markersize=6, markerfacecolor='#4472C4', markeredgewidth=0.5, linewidth=0.5, linestyle='-', color='k', label="80 percentage")
    plt.axvspan(xmin=X4[len(X4) - 1]-xspan, xmax=X4[len(X4) - 1]+xspan, facecolor="r",alpha=0.2)
    plt.axhspan(ymin=min(Y4) - yspan, ymax=max(Y4) + yspan, facecolor="b", alpha=0.1)


    plt.title("San Francisco")
    plt.legend(loc="lower right")
    plt.xlabel('epoch')
    plt.ylabel('compression ratio')

def drawWashington3D():
    fig = plt.figure()
    ax = fig.add_subplot(111, projection = '3d')
    X1 = [154,155,156,157,158,159,160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175,176,177,178,179,180,181,182,183]
    Y1 = [6484,6606,6723,6839,6955,7075,7195,7320,7446,7570,7695,7821,7947,8079,8210,8337,8465,8595,8728,8864,8999,9129,9264,9401,9541,9676,9814,9956,10093,10234]
    Z1 = [0.839977,0.838609,0.837262,0.835918,0.834575,0.833215,0.831855,0.830475,0.829091,0.827715,0.826334,0.82495,0.823565,0.822156,0.820751,0.819363,0.81797,0.816569,0.815156,0.81373,0.812309,0.810908,0.809486,0.808056,0.806614,0.805193,0.803759,0.802309,0.800879,0.799433]
    ax.plot(X1, Y1, Z1)
    ax.scatter(X1, Y1, Z1, s=48, marker = "o", alpha=0.6, label = '20 percentage')

    X2 = [616,615]
    Y2 = [64915,64910]
    Z2 = [0.199461,0.200347]
    ax.plot(X2, Y2, Z2)
    ax.scatter(X2, Y2, Z2, s=48, marker = "o", alpha=0.6, label = '20 percentage')
    ax.legend()

def drawChicago():
    plt.subplot(222)
    X1 = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16]
    Y1 = [0.193552,0.194,0.194447,0.194894,0.195342,0.195789,0.196237,0.196681,0.197128,0.197576,0.198023,0.198467,0.198914,0.199365,0.199816,0.200263]

    X2 = [1,2,3,4,5,6]
    Y2 = [0.406589,0.405277,0.403903,0.40253,0.401156,0.39977]

    X3 = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17]
    Y3 = [0.619046,0.61786,0.616668,0.615469,0.614306,0.613117,0.611932,0.61074,0.609577,0.608365,0.607144,0.605942,0.604737,0.603525,0.602268,0.601073,0.599774]

    X4 = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28]
    Y4 = [0.825251,0.824324,0.823372,0.822429,0.821519,0.820595,0.819672,0.818729,0.817796,0.816879,0.81592,0.814981,0.814044,0.813079,0.812149,0.811174,0.810205,0.809256,0.808294,0.807328,0.80636,0.805407,0.804445,0.803476,0.802507,0.801516,0.800512,0.799527]

    plt.plot(X1, Y1, marker = "o", markersize=6, markerfacecolor='#C2D1EB', markeredgewidth=0.5, linewidth=0.5, linestyle='-', color='k', label="20 percentage")
    plt.axvspan(xmin=X1[len(X1) - 1]-xspan, xmax=X1[len(X1) - 1]+xspan, facecolor="r",alpha=0.2)
    plt.axhspan(ymin=min(Y1) - yspan, ymax=max(Y1) + yspan, facecolor="b", alpha=0.1)
    
    plt.plot(X2, Y2, marker = "o", markersize=6, markerfacecolor='#96B0DD', markeredgewidth=0.5, linewidth=0.5, linestyle='-', color='k', label="40 percentage")
    plt.axvspan(xmin=X2[len(X2) - 1]-xspan, xmax=X2[len(X2) - 1]+xspan, facecolor="r",alpha=0.2)
    plt.axhspan(ymin=min(Y2) - yspan, ymax=max(Y2) + yspan, facecolor="b", alpha=0.1)
    
    plt.plot(X3, Y3, marker = "o", markersize=6, markerfacecolor='#6B90D0', markeredgewidth=0.5, linewidth=0.5, linestyle='-', color='k', label="60 percentage")
    plt.axvspan(xmin=X3[len(X3) - 1]-xspan, xmax=X3[len(X3) - 1]+xspan, facecolor="r",alpha=0.2)
    plt.axhspan(ymin=min(Y3) - yspan, ymax=max(Y3) + yspan, facecolor="b", alpha=0.1)

    plt.plot(X4, Y4, marker = "o", markersize=6, markerfacecolor='#4472C4', markeredgewidth=0.5, linewidth=0.5, linestyle='-', color='k', label="80 percentage")
    plt.axvspan(xmin=X4[len(X4) - 1]-xspan, xmax=X4[len(X4) - 1]+xspan, facecolor="r",alpha=0.2)
    plt.axhspan(ymin=min(Y4) - yspan, ymax=max(Y4) + yspan, facecolor="b", alpha=0.1)

    plt.title("Chicago")
    plt.legend(loc="lower right")
    plt.xlabel('epoch')
    plt.ylabel('compression ratio')

if __name__ == '__main__':
    plt.figure()
    drawNewYork()
    drawChicago()
    drawWashington()
    drawSanFrancisco()
    plt.show()