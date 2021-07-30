SET PATH=C:\Keil\ARM\ARMCC\bin\;C:\Program Files (x86)\Intel\iCLS Client\;C:\Program Files\Intel\iCLS Client\;C:\Windows\system32;C:\Windows;C:\Windows\System32\Wbem;C:\Windows\System32\WindowsPowerShell\v1.0\;C:\Program Files (x86)\Intel\Intel(R) Management Engine Components\DAL;C:\Program Files\Intel\Intel(R) Management Engine Components\DAL;C:\Program Files (x86)\Intel\Intel(R) Management Engine Components\IPT;C:\Program Files\Intel\Intel(R) Management Engine Components\IPT;C:\Program Files (x86)\NVIDIA Corporation\PhysX\Common;C:\Program Files\Intel\WiFi\bin\;C:\Program Files\Common Files\Intel\WirelessCommon\;C:\WINDOWS\system32;C:\WINDOWS;C:\WINDOWS\System32\Wbem;C:\WINDOWS\System32\WindowsPowerShell\v1.0\;C:\WINDOWS\System32\OpenSSH\;C:\Program Files\MATLAB\R2018a\runtime\win64;C:\Program Files\MATLAB\R2018a\bin;C:\Cadence\SPB_16.6\openaccess\bin\win32\opt;C:\Cadence\SPB_16.6\tools\capture;C:\Cadence\SPB_16.6\tools\pspice;C:\Cadence\SPB_16.6\tools\specctra\bin;C:\Cadence\SPB_16.6\tools\fet\bin;C:\Cadence\SPB_16.6\tools\libutil\bin;C:\Cadence\SPB_16.6\tools\bin;C:\Cadence\SPB_16.6\tools\pcb\bin;C:\Users\Chamod\AppData\Local\Microsoft\WindowsApps;C:\OrCAD\OrCAD_10.5\tools\pcb\bin;C:\OrCAD\OrCAD_10.5\tools\fet\bin;C:\OrCAD\OrCAD_10.5\tools\specctra\bin;C:\OrCAD\OrCAD_10.5\tools\bin;C:\OrCAD\OrCAD_10.5\tools\PSpice\Library;C:\OrCAD\OrCAD_10.5\tools\Capture
SET CPU_TYPE=TM4C123GH6PM
SET CPU_VENDOR=Texas Instruments
SET UV2_TARGET=Target 1
SET CPU_CLOCK=0x00F42400
"C:\Keil\ARM\ARMCC\bin\ArmCC" --Via ".\uart0updated.__i"
"C:\Keil\ARM\ARMCC\bin\ArmAsm" --Via ".\startup_tm4c123._ia"
"C:\Keil\ARM\ARMCC\bin\ArmLink" --Via ".\uart.lnp"
C:\Keil\ARM\ARMCC\bin\fromelf.exe ".\uart.axf" --i32combined --output ".\uart.hex"
