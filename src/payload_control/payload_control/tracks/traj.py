import numpy as np

def generate_length_parameterized_trajectory(start_pos, end_pos, duration, dt, filename="trajectory.txt"):
    """
    Generate a length-parameterized trajectory and save it to a text file with columns:
    length, x, y, z, vx, vy, vz, ax, ay, az, yaw, yaw_rate.

    Parameters:
    start_pos : list or np.array [x, y, z, yaw] - Starting position and yaw angle
    end_pos   : list or np.array [x, y, z, yaw] - Ending position and yaw angle
    duration  : float - Total time to reach the end position (seconds)
    dt        : float - Time step for trajectory generation (seconds)
    filename  : str - Output file to save the trajectory (default is length_trajectory.txt)
    """
    
    # Time array
    t = np.arange(0, duration + dt, dt)  
    n = len(t)

    # Start and end positions for x, y, z, and yaw
    start_x, start_y, start_z, start_yaw = start_pos
    end_x, end_y, end_z, end_yaw = end_pos

    # Polynomial coefficients for smooth position trajectory (cubic)
    a0 = np.array([start_x, start_y, start_z, start_yaw])
    a1 = np.zeros(4)
    a2 = 3 * (np.array([end_x, end_y, end_z, end_yaw]) - np.array([start_x, start_y, start_z, start_yaw])) / (duration**2)
    a3 = -2 * (np.array([end_x, end_y, end_z, end_yaw]) - np.array([start_x, start_y, start_z, start_yaw])) / (duration**3)

    # Trajectory arrays
    positions = np.zeros((n, 4))
    velocities = np.zeros((n, 4))
    accelerations = np.zeros((n, 4))

    for i in range(n):
        # Time instant
        ti = t[i]

        # Position (cubic polynomial)
        positions[i, :] = a0 + a1 * ti + a2 * ti**2 + a3 * ti**3

        # Velocity (derivative of position)
        velocities[i, :] = a1 + 2 * a2 * ti + 3 * a3 * ti**2

        # Acceleration (derivative of velocity)
        accelerations[i, :] = 2 * a2 + 6 * a3 * ti

    # Extract yaw and yaw rate
    yaw = positions[:, 3]
    yaw_rate = velocities[:, 3]

    # Calculate cumulative length along the trajectory (distance between consecutive points)
    distances = np.sqrt(np.diff(positions[:, 0])**2 + np.diff(positions[:, 1])**2 + np.diff(positions[:, 2])**2)
    cumulative_length = np.zeros(n)
    cumulative_length[1:] = np.cumsum(distances)

    # Now, we have a length-parameterized trajectory
    trajectory_data = np.column_stack((
        cumulative_length,              # Length
        positions[:, :3],               # x, y, z
        velocities[:, :3],              # vx, vy, vz
        accelerations[:, :3],           # ax, ay, az
        yaw,                            # Yaw angle
        yaw_rate                        # Yaw rate
    ))

    # Save to a text file with space-separated values
    np.savetxt(filename, trajectory_data, fmt='%.6f', delimiter=' ')

# Example Usage
start_pos = [0, 0, 0, 0]  # [x, y, z, yaw]
end_pos = [3, 3, 4, np.pi/4]  # [x, y, z, yaw]
duration = 10  # seconds
dt = 0.1  # time step

# Generate and save the length-parameterized trajectory to length_trajectory.txt
generate_length_parameterized_trajectory(start_pos, end_pos, duration, dt)
