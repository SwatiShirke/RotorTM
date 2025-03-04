import numpy as np

class Obs:
    def __init__(self,origin_x,origin_y,origin_z,length,breadth,height):
        self.origin_x = origin_x
        self.origin_y = origin_y
        self.origin_z = origin_z
        self.length = length
        self.breadth = breadth
        self.height = height

    def get_convex_rep(self):
        A = np.array([[0,0,1], [0,0,-1], [1,0, 0], [-1,0, 0],[0,1,0],[0,-1,0]])
        B = np.array([[self.origin_z+self.height/2],[-self.origin_z+self.height/2], [self.origin_x+self.length/2], [-self.origin_x+self.length/2],[self.origin_y+self.breadth/2],[-self.origin_y+self.breadth/2]])
        return A, B


class TriangleObs:
    def get_convex_rep(self):
        A = np.array([[0,0,1],[0,0,-1],[1.73,3,0],[-3.47,0,0],[1.73,-3,0]])
        B = np.array([[0.05],[0.05],[1],[1],[1]])
        return A,B  

