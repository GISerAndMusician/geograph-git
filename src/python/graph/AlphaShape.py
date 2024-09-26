import os
import sys
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from descartes import PolygonPatch
sys.path.insert(0, os.path.dirname(os.getcwd()))
import alphashape


def run(data, alpha):
    Sarray = data.split(',')
    Coords = [(float(Sarray[i]), float(Sarray[i+1])) for i in range(0, len(Sarray), 2)]
    alpha_shape = alphashape.alphashape(Coords, alpha)
    
    ret = []
    if(alpha_shape.geom_type == 'MultiPolygon'):
        for poly in alpha_shape.geoms:
            ret.append(poly.exterior.coords[:])
    else:
        ret.append(alpha_shape.exterior.coords[:])
    return ret

if __name__ == "__main__":
    data = '''0,0,0,1,1,0,0.5,0.25,0.5,0.75,0.25,0.5,0.75,0.5'''
    run(data, 2)