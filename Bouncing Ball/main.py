import ctypes
from ctypes import *
import os
import matplotlib.pyplot as plt
import pandas as pd
import time

start_time = time.time()
dll_path = os.path.abspath("./bounce_win64.dll")
dll = ctypes.windll.LoadLibrary(dll_path)
initialize = dll.bounce_initialize
step = dll.bounce_step
terminate = dll.bounce_terminate

#Equivalent Class Declarations for Structures
class DW_bounce_T(Structure):
    _fields_ = [
        ("dxdt_DSTATE", c_double),
        ("StateNameX", c_double),
        ("dxdt_PrevResetState", c_int8),
        ("x_PrevResetState", c_int8),
        ("dxdt_IC_LOADING", c_uint8),
        ("x_IC_LOADING", c_uint8),
        ("InitialVelocity_FirstOutputTime", c_bool)
    ]
class TimingStruct(Structure):
    _fields_ = [
        ("clockTick0", c_uint32)
    ]
class RTM_bounce_T(Structure):
    _fields_ = [
        ("errorStatus", POINTER(c_char)),
        ("dwork", POINTER(DW_bounce_T)),
        ("Timing", TimingStruct)
    ]
bounce_DW =DW_bounce_T()
bounce_M_ = RTM_bounce_T()
bounce_M = pointer(bounce_M_)
bounce_M_.dwork = pointer(bounce_DW)

initialize(bounce_M) #Model Initialized
timer = 0
time_step = 0.1   #step time equaivalent to sample time in model, cannot be altered
simulation_time = 25

#importing the variables to be altered
coefficient_of_restitution=c_double.in_dll(dll,"coefficient_of_restitution")
gravitational_constant=c_double.in_dll(dll,"gravitational_constant")

gravitational_constant.value=-9.8
coefficient_of_restitution.value=-0.7

# Signals to be measured
velocity = c_double.in_dll(dll, "Velocity")
position = c_double.in_dll(dll, "Position")

output=list()
while timer <= simulation_time:
    pass
    # Step the model
    step(bounce_M)
    row_tmp = {
        "time": float(timer),
        "ball_position": float(position.value),
        "ball_velocity": float(velocity.value),
    }
    output.append(row_tmp)
    timer = timer + time_step
# Terminate the model
terminate(bounce_M)






#Plotting and Further Data Processing
df = pd.DataFrame(output)
df.plot(x="time", y=["ball_position", "ball_velocity"])
plt.title("Ball Trajectory")
plt.grid(True)
time_value = 10
closest_time_index = (df['time'] - time_value).abs().idxmin()
closest_time = df.loc[closest_time_index, 'time']
ball_position_value = df.loc[closest_time_index, 'ball_position']
plt.scatter(closest_time, ball_position_value, color='red')
plt.text(closest_time, ball_position_value, f'{ball_position_value:.2f}', fontsize=10, ha='right', va='bottom', color='red')
ball_velocity_value = df.loc[closest_time_index, 'ball_velocity']
plt.scatter(closest_time, ball_velocity_value, color='blue')
plt.text(closest_time, ball_velocity_value, f'{ball_velocity_value:.2f}', fontsize=10, ha='right', va='bottom', color='blue')
end_time = time.time()
execution_time = end_time - start_time
print("Total execution time: {:.2f} seconds".format(execution_time))
plt.show()

