
import numpy as np
import os
from pathlib import Path
from scipy.interpolate import interp1d
from matplotlib import pyplot as plt

def plot_graph(x, y, z=None, xlabel="X-axis", ylabel="Y-axis", zlabel="Z-axis", title="Graph"):
    plt.figure()
    
    if z is None:
        # 2D plot
        plt.plot(x, y, marker="o", label="y vs x")
        plt.xlabel(xlabel)
        plt.ylabel(ylabel)
    else:
        # 3D plot
        from mpl_toolkits.mplot3d import Axes3D
        fig = plt.figure(figsize=(10, 8))
        ax = fig.add_subplot(111, projection='3d')
        ax.plot(x, y, z, marker="o", label="z vs x, y")
        ax.set_xlabel(xlabel)
        ax.set_ylabel(ylabel)
        ax.set_zlabel(zlabel)
    
    plt.title(title)
    plt.legend()
    plt.show()


def getTrack(filename):
    track_file = os.path.join(str(Path(__file__).parent), filename)
    array=np.loadtxt(track_file)
    sref=array[:,0]
    xref=array[:,1]
    yref=array[:,2]
    psiref=array[:,3]
    kapparef=array[:,4]
    return sref,xref,yref,psiref,kapparef



def read_interpl(filename):
    data = np.loadtxt(filename)
    #Split the data into separate variables
    time_points = data[:, 0]  # Time column
    x = data[:, 1]            # x position
    y = data[:, 2]            # y position
    z = data[:, 3]            # z position
    vx = data[:, 4]           # vx velocity
    vy = data[:, 5]           # vy velocity
    vz = data[:, 6]           # vz velocity
    ax = data[:,7]
    ay = data[:,8]
    az = data[:, 9]
    yaw = data[:,10 ]          # yaw
    yaw_rate = data[:, 11]     # yaw rate

    # Create cubic splines for each variable (x, y, z, vx, vy, vz, yaw, yaw_rate)
    spl_x = interp1d(time_points, x, kind='cubic', fill_value="extrapolate")
    spl_y = interp1d(time_points, y, kind='cubic', fill_value="extrapolate")
    spl_z = interp1d(time_points, z, kind='cubic', fill_value="extrapolate")
    spl_vx = interp1d(time_points, vx, kind='cubic', fill_value="extrapolate")
    spl_vy = interp1d(time_points, vy, kind='cubic', fill_value="extrapolate")
    spl_vz = interp1d(time_points, vz, kind='cubic', fill_value="extrapolate")
    spl_ax = interp1d(time_points, ax, kind='cubic', fill_value="extrapolate")
    spl_ay = interp1d(time_points, ay, kind='cubic', fill_value="extrapolate")
    spl_az = interp1d(time_points, az, kind='cubic', fill_value="extrapolate")    
    spl_yaw = interp1d(time_points, yaw, kind='cubic', fill_value="extrapolate")
    spl_yaw_rate = interp1d(time_points, yaw_rate, kind='cubic', fill_value="extrapolate")

    pos = np.array([spl_x,spl_y,spl_z])
    vel = np.array([spl_vx, spl_vy,spl_vz] )  
    acc = np.array([spl_ax, spl_ay, spl_az]) 
    start_pose = np.array([x[0], y[0], z[0]])
    last_pose = np.array([x[-1], y[-1], z[-1]]) 

    return time_points, pos, vel, acc, spl_yaw, spl_yaw_rate, start_pose, last_pose




def visualize_traj(filename):
    [time_points, pos, vel, acc, spl_yaw, spl_yaw_rate, start_pose, last_pose ] = read_interpl(filename)
    dense_time_pt = np.linspace(time_points[0], time_points[-1], 1000)
    dense_time_pt2 = dense_time_pt[0:709]
    pos_x = pos[0]
    pos_y = pos[1]
    pos_z = pos[2]
    vel_x = vel[0]
    vel_y = vel[1]
    vel_z = vel[2]
    # plt.figure()
    # plt.plot(pos_x(dense_time_pt),pos_y(dense_time_pt), pos_z(dense_time_pt))
    # plt.show()
    print(vel_x(dense_time_pt2))
    plot_graph(pos_x(dense_time_pt),pos_y(dense_time_pt), pos_z(dense_time_pt))
  
if __name__ =="__main__":
    print("Hello")
    visualize_traj('trajectory.txt')