import ctypes
import time
from ctypes import *
import os
import matplotlib.pyplot as plt

start_time = time.time() #measures start time of simulation
 #importing functions and variables from dll
dll_path = os.path.abspath("./vehicle_win64.dll")
dll = ctypes.windll.LoadLibrary(dll_path)
initialize = dll.vehicle_initialize
step = dll.vehicle_step
terminate = dll.vehicle_terminate
switch_batt=c_double.in_dll(dll, "switch_batt")
switch_batt.value=2 #switch closed initially
k = c_bool.in_dll(dll, "lampout")
curr=c_double.in_dll(dll, "current")

initialize() #initialises the model
simulation_times = []
output_values_lamp = []
output_values_current = []

timer = 0
time_step = 1e-5
simulation_time = 4
while timer <= simulation_time:
    pass
    step()
    simulation_times.append(timer)
    output_values_lamp.append(k.value)
    output_values_current.append(curr.value)
    timer = timer + time_step

#mimics simulation paused at t=4 and resumes after that
timer = timer
time_step = 1e-5
simulation_time = 5
switch_batt.value=0 #switch opens after t=4
while timer <= simulation_time:
    pass
    step()
    simulation_times.append(timer)
    output_values_lamp.append(k.value)
    output_values_current.append(curr.value)
    timer = timer + time_step

terminate() #terminates the model
end_time = time.time()
execution_time = end_time - start_time
print("Total execution time: {:.2f} seconds".format(execution_time))

#Plotting and data processing
#Lamp output plot
fig, (ax1, ax2) = plt.subplots(2, 1, figsize=(8, 12))

# Plot for Lamp Output
ax1.plot(simulation_times, output_values_lamp, label='Output Lamp')
ax1.set_xlabel('Simulation Time', fontsize=10)
ax1.set_ylabel('Lamp Current', fontsize=10)
ax1.set_title('Lamp Output', fontsize=12)
ax1.grid(True)
ax1.legend(loc='upper right', fontsize=11)
ax1.xaxis.set_major_formatter(plt.FuncFormatter(lambda x, _: f'{x:.2f}'))

# Plot for Current Sensor Output
ax2.plot(simulation_times, output_values_current, label='Output Current')
ax2.set_xlabel('Simulation Time', fontsize=10)
ax2.set_ylabel('Current', fontsize=10)
ax2.set_title('Current Sensor Output', fontsize=12)
ax2.legend(loc='upper right', fontsize=11)
ax2.grid(True)

plt.tight_layout()
plt.show()