import ctypes
import os
import pefile

dll_path = "./vehicle_win64.dll"
# Load the DLL file
pe = pefile.PE(dll_path)
# Check if the DLL has an export directory
if hasattr(pe, 'DIRECTORY_ENTRY_EXPORT'):
    # Loop through the exported symbols/functions
    for exp in pe.DIRECTORY_ENTRY_EXPORT.symbols:
        if exp.name is not None:
            print(hex(pe.OPTIONAL_HEADER.ImageBase + exp.address), exp.name.decode('utf-8'))
        else:
            print(f"Ordinal {exp.ordinal} (no name)")
else:
    print("No export directory found, the DLL might not export functions directly.")
