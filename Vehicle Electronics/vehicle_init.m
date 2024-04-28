%setting signals to measure
lampout=Simulink.Signal;
lampout.CoderInfo.StorageClass='ExportedGlobal';
current=Simulink.Signal;
current.CoderInfo.StorageClass='ExportedGlobal';

%setting parameters to change
switch_batt=Simulink.Parameter;
switch_batt.Value =2;
switch_batt.CoderInfo.StorageClass='ExportedGlobal';