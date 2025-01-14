import numpy as np
import ipdb

def cal_pl_dt(quat, omega, Mass, F, g, Inertia, M ):  
  qW = quat[0]
  qX = quat[1]
  qY = quat[2]
  qZ = quat[3]
  p = omega[0]
  q = omega[1]
  r = omega[2]

  K_quat = 2
  quaterror = 1 - (qW ** 2 + qX ** 2 + qY ** 2 + qZ ** 2)
  #qLdot = - 1 / 2 * np.array([[0,- p,- q,- r],[p,0,- r,q],[q,r,0,- p],[r,- q,p,0]]) * quat + K_quat * quaterror * quat
  omega_mat = np.array([[0,- p,- q,- r],[p,0,r,-q],[q,-r,0,p],[r,q,-p,0]])
  #   print(omega_mat)
  ipdb.set_trace()
  qLdot = 1 / 2 * np.matmul(omega_mat, quat) + K_quat * quaterror * quat

  print(qLdot)
  #accel
  
  invML = np.linalg.inv(Mass)  
  accL = np.matmul(invML, (F - Mass[2] * np.array([0,0,g])))
  print(accL)

  invIL = np.linalg.inv(Inertia)
  omgLdot = np.matmul(invIL,(M - np.cross(omega, np.matmul(Inertia, omega))))
  print(omgLdot)
  return qLdot


if __name__ == "__main__":
    q_in = np.array([1.0, 0.1,0.2,0.3])
    omg = np.array([1,2,3])
    Mass = np.diag([0.250,0.250,0.250])
    F = [1,1,1]
    g = 9.81
    Inertia = np.diag([0.000601, 0.000589, 0.01076])
    M = [1,1,1]
    pldot = cal_pl_dt(q_in,omg, Mass, F,g, Inertia, M)