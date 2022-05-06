**************************************************************************************
*                                                                                     
*  Using the Visual Studio Code editor with the ARM based PEAK-System GCC environment  
*  © 2020 PEAK-System Technik GmbH Darmstadt, Germany
*                                                                                     
**************************************************************************************

Contents
********
  * Introduction
  * System Requirements
  * Package Contents
  * Firmware Development
  * Contacting PEAK-System


Introduction
************
This package enables you to develop your own application-specific firmware for 
programmable hardware products from PEAK-System. For each supported product, examples
are included.


System Requirements
*******************
- A development PC with Windows® 10 (32-/64-bit) 
- A CAN interface of the PCAN series to upload the firmware to your hardware via CAN


Package Contents
****************
Build Tools Win32\
	Tools for automating the build process for Windows® 32-bit

Build Tools Win64\
	Tools for automating the build process for Windows® 64-bit
	
Compiler\
    Compilers for the supported programmable products

Hardware\
    Contains sub directories of the supported hardware which include several firmware 
	examples. Use the examples for starting your own firmware development.
	
PEAK-Flash\
    Windows tool for uploading the firmware to your hardware via CAN. Copy the 
	directory to your PC and start the software without further installation.

LiesMich.txt
    This text file in German

ReadMe.txt
    This text file in English

SetPath_for_VSCode.vbs
	VBScript to modify the example directories for the Visual Studio Code IDE.


Firmware Development
********************
1. Create a folder on your local PC. We recommend to use a local drive.

2. Copy the complete unzipped "PEAK-DevPack" directories into your folder, incl. 
   all subs. No installation is required at all.

3. Run the script "SetPath_for_VSCode.vbs". This script will modify the example 
   directories for the Visual Studio Code IDE. https://code.visualstudio.com/
   
   After that every example directory has a folder called ".vscode" containing 
   the needed files with your local path information. 

4. Now you can start Visual Studio Code which is available for free from Microsoft. 

5. Select the folder of your project and open it. 
   For example: "d:\PEAK-DevPack\Hardware\PCAN-Router Pro FD\Examples\01_ROUTING"

6. You can edit the C code and call make clean, make all, or compile single file via 
   the menu Terminal > Run Task. 

7. Create your firmware with Make All. The firmware is the *.bin in the sub directory
   "out" of your project folder.

8. Setup your hardware for firmware upload like described in the hardware manual.

9. Use the PEAK-Flash tool to upload your firmware to the device via CAN (a PEAK CAN 
   interface is required). Open the tool via Terminal > Run Task > Flash Device or 
   from the sub directory of the development package.


Contacting PEAK-System
**********************
Do you have questions about your hardware or do you need information about further 
products from PEAK-System? Please contact:

PEAK-System Technik GmbH
Otto-Roehm-Strasse 69
64293 Darmstadt
Germany

Phone: +49 (0)6151 8173-20
Fax:   +49 (0)6151 8173-29

support@peak-system.com
www.peak-system.com
