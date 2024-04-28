import ctypes
import time
from ctypes import *
import os
import matplotlib.pyplot as plt
start_time = time.time()
#importing functions and variables from the dll.
dll_path = os.path.abspath("./flow_win64.dll")
dll = ctypes.windll.LoadLibrary(dll_path)
initialize = dll.flow_initialize
step = dll.flow_step
terminate=dll.flow_terminate
k = c_double.in_dll(dll, "sensormeasure")
valve=c_double.in_dll(dll, "valve")

initialize() #initialises the model
simulation_times = []
output_values = []
valve.value=1 #sets initial value for Valve signal
timer = 0
time_step = 1
simulation_time = 150
while timer <= simulation_time:
    pass
    if timer==70:
        valve.value = -2
    if timer == 120:
        valve.value = 2
    step()
    simulation_times.append(timer)
    output_values.append(k.value)
    timer = timer + time_step

terminate() #terminates the model

end_time = time.time()
execution_time = end_time - start_time
print("Total execution time: {:.2f} seconds".format(execution_time))

#Plotting
plt.figure()
plt.plot(simulation_times, output_values, label='Output')
plt.xlabel('Simulation Time')
plt.ylabel('Mass Flow Rate')
plt.title('Mass Flow Rate Over Time')
plt.legend()
plt.grid(True)
plt.show()