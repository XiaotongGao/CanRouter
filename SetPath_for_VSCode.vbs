'
' Simple Script to create the needed path entries for the VS Code Environment (see Projekt Directories - Sub Dir .Vscode)
' 
' (c) 2020 by PEAK-System Technik GmbH - GERMANY 
' for any questions, feel free to contact    support@peak-system.com
' 
' Version 1.04 
' Date: 02.07.2020
' Autor: UW/PS
' 
' This Software is provided as it is. PEAK does not guarantee that Software embodies all necessary legal provisions and all standards related to the Software.
'
' PEAK, ITS AFFILIATES AND/OR ITS SUPPLIERS SHALL NOT BE LIABLE FOR ANY DAMAGES WHATSOEVER (INCLUDING WITHOUT LIMITATION, DIRECT OR INDIRECT DAMAGES FOR PERSONAL INJURY,
' LOSS OF BUSINESS PROFITS, BUSINESS INTERRUPTION, LOSS OF BUSINESS INFORMATION DAMAGES FOR LOSS OF DATA, OR SOFTWARE RESTORATION, OR ANY OTHER PECUNIARY LOSS) ARISING OUT 
' OF THE USE OF OR INABILITY TO USE THE SOFTWARE, EVEN IF PEAK HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
' IN ANY CASE, THE ENTIRE LIABILITY OF PEAK, ITS AFFILIATES AND ITS SUPPLIERS', UNDER ANY PROVISION OF THIS AGREEMENT, SHALL BE LIMITED TO THE AMOUNT OF THE PAYMENTS 
' MADE BY CLIENT TO PEAK FOR THIS SOFTWARE. 
' 
' for more information, please red the "PEAK-System_EULA_for free of charge software_files.txt" which is available on our WEB Page -  www.peak-system.com 
'
' The BuildTools and Compiler itself own a seperate License Information 
'
' Historie:
' V1.0 First Beta 
' V1.02 First final customer releas - Only using 32Bit BuildTools
' V1.04 Final customer releas with 32 and 64 Bit BuildTools and single File ARM V7 option


' Some CONST from Microsoft...
Const ForReading = 1, ForWriting = 2, ForAppending = 8
Const TristateUseDefault = -2, TristateTrue = -1, TristateFalse = 0

' and for the Tool itself...
Const StartFile1 = 1, StopFile1 = 2, Idle = 0

' global VARs
Dim CurrentPathValueOriginal	' our root 
Dim CurrentPathValue			' our "root in Linux Format"
Dim FSO 						' File System Object
Dim objFile_CPP_Prop 			' FileObj_CPP
Dim objFile_Task				' FileObj_Task
Dim objFileMySelf				' This Files 
Dim OSType						' 32 or 64 Bit 
Dim BuildToolsBinPath 			' Bin Path - depending on OS Version

' The 2 files we need to adapt so that it will fit to your environment
Const File_CPP_Prop = "c_cpp_properties.json"
Const File_Task = "tasks.json"

' Directory where the files need to be copied to
Const VSFolderName = ".vscode"
Const MakefileFolderName = "Makefile"



' ****************************************************************************************
' ****************************************************************************************
'      This strings must be replaced when a new Compiler Verson will be used
' ****************************************************************************************
' ****************************************************************************************
'
' Const Strings for the 7-2017 Compiler set
' Remark CPP_Prop - three different Paths have to be setup
Const IncludePath = "/Compiler/7 2017-q4-major/arm-none-eabi/include/"
Const IncludeLibPath = "/Compiler/7 2017-q4-major/lib/gcc/arm-none-eabi/7.2.1/include/"
Const IncludeLibFixedPath = "/Compiler/7 2017-q4-major/lib/gcc/arm-none-eabi/7.2.1/include-fixed/"
'
' Also here...
' Remark Task - three different Paths have to be setup
Const FlashPath = "/PEAK-Flash/"
Const BuildToolsBinPath32 = "/Build Tools Win32/2.12-20190422-1053/bin/"
Const BuildToolsBinPath64 = "/Build Tools Win64/2.12-20190422-1053/bin/"

Const CompilerBinPath = "/Compiler/7 2017-q4-major/bin/"


' ****************************************************************************************
' ****************************************************************************************

'
' Here, only for information, the default values and the internal Replace Numbers/Strings (V7)
'
' Remark CPP_Prop
'	"d:/Entwicklung/ARM_based_HW/7 2017-q4-major/arm-none-eabi/include/",						REPLACE1
'	"d:/Entwicklung/ARM_based_HW/7 2017-q4-major/lib/gcc/arm-none-eabi/7.2.1/include/",			REPLACE2
'	"d:/Entwicklung/ARM_based_HW/7 2017-q4-major/lib/gcc/arm-none-eabi/7.2.1/include-fixed/"	REPLACE3

'	"d:/Entwicklung/ARM_based_HW/7 2017-q4-major/arm-none-eabi/include/",						REPLACE1
'	"d:/Entwicklung/ARM_based_HW/7 2017-q4-major/lib/gcc/arm-none-eabi/7.2.1/include/",			REPLACE2
'	"d:/Entwicklung/ARM_based_HW/7 2017-q4-major/lib/gcc/arm-none-eabi/7.2.1/include-fixed/"	REPLACE3


' Remark Task
'	"path": "d:/Entwicklung/ARM_based_HW/PEAK-Flash/" 																				REPLACE4
'	"path": "d:/Entwicklung/ARM_based_HW/Build Tools/2.10-20180103-1919/bin/;d:/Entwicklung/ARM_based_HW/7 2017-q4-major/bin/"		REPLACE5
'	"path": "d:/Entwicklung/ARM_based_HW/Build Tools/2.10-20180103-1919/bin/;d:/Entwicklung/ARM_based_HW/7 2017-q4-major/bin/" 		REPLACE5
'	"path": "d:/Entwicklung/ARM_based_HW/Build Tools/2.10-20180103-1919/bin/;d:/Entwicklung/ARM_based_HW/7 2017-q4-major/bin/"	 	REPLACE5
	 

'get the used Platform (X86 for 32Bit or AMD64 for 64Bit and set the BuildToolsBinPath
OSType ="unknown"
ChekOSType()

If OSType ="32Bit" Then 
	BuildToolsBinPath = BuildToolsBinPath32
End If
	
If OSType ="64Bit" Then
	BuildToolsBinPath = BuildToolsBinPath64
End If

If OSType = "unknown" Then
	WScript.Echo "Error detecting OS Version (32/64Bit)"
	WScript.Quit (1)
End If
	
	
' Get the current path 
Set FSO = CreateObject("Scripting.FileSystemObject")
CurrentPathValueOriginal = FSO.GetAbsolutePathName(".")
' need to replace \ with / in the path
CurrentPathValue = Replace(CurrentPathValueOriginal, "\", "/")

' Generate the new Strings 
NEWIncludePath = CurrentPathValue + IncludePath
NEWIncludeLibPath = CurrentPathValue + IncludeLibPath
NEWIncludeLibFixedPath = CurrentPathValue + IncludeLibFixedPath
NEWFlashPath = "path"": """ + CurrentPathValue + FlashPath
NEWBuildToolsBinPath = CurrentPathValue + BuildToolsBinPath
NEWCompilerBinPath = CurrentPathValue + CompilerBinPath
NewBuildToolsBinCompilerBinPath = "path"": """ + NEWBuildToolsBinPath + ";" + NEWCompilerBinPath


' Open MessageBox and inform the user that we now start...
  WScript.Echo "PEAK-System ARM based Toolchain VSCode Setup for " + OSType + " - press OK"

' Create the two empty Textfiles in the current Directory
Set objFile_CPP_Prop = FSO.CreateTextFile(File_CPP_Prop)
Set objFile_Task = FSO.CreateTextFile(File_Task)

' 1st File
' Load the File Template from this , yes this, file - see EOF
Set myfile = FSO.GetFile(WScript.ScriptName) 'get handle of this script file 
Set mytextstream = myfile.OpenAsTextStream(ForReading, TristateUseDefault) ' open this file as stream
State = Idle ' state machin Idle
Do While Not mytextstream.AtEndOfStream ' as long as strings in the line...
   TextStreamLine = mytextstream.ReadLine ' read a single line
   If State = StartFile1 Then ' we are inside the lines wee need !
		If TextStreamLine <> "' **End of c_cpp_properties.json**" Then 
			' Is there somethink to replace ?
			If (InStr(1,TextStreamLine,"REPLACE1", vbTextCompare) > 0) Then ' found 	
				StreamLine = "			""" + NEWIncludePath + ""","
			Else 
				If (InStr(1,TextStreamLine,"REPLACE2", vbTextCompare) > 0) Then ' found 	
					StreamLine = "			""" + NEWIncludeLibPath + ""","
				Else
					If (InStr(1,TextStreamLine,"REPLACE3", vbTextCompare) > 0) Then ' found 	
						StreamLine = "			""" + NEWIncludeLibFixedPath + """"
					Else 
						StreamLine = Right(TextStreamLine, Len(TextStreamLine)-1) ' REM, so remove the 1st char
					End If	
				End If 	
			End If			
    		objFile_CPP_Prop.WriteLine(StreamLine) ' write the line
    	End If 	
    End If 
    If TextStreamLine = "' **Start of c_cpp_properties.json**" Then State = StartFile1 End If 
    If TextStreamLine = "' **End of c_cpp_properties.json**" Then State = StopFile1 End If 	
 Loop   
mytextstream.Close
objFile_CPP_Prop.Close


' 2nd File 
' Load the File Template from this , yes this, file - see EOF
Set myfile = FSO.GetFile(WScript.ScriptName) 'get handle of this script file 
Set mytextstream = myfile.OpenAsTextStream(ForReading, TristateUseDefault) ' open this file as stream
State = Idle ' state machin Idle
Do While Not mytextstream.AtEndOfStream ' as long as strings in the line...
   TextStreamLine = mytextstream.ReadLine ' read a single line
   If State = StartFile1 Then ' we are inside the lines wee need !
		If TextStreamLine <> "' *End of tasks.json**" Then 
			' Is there somethink to replace ?
			If (InStr(1,TextStreamLine,"REPLACE4", vbTextCompare) > 0) Then ' found 	
				StreamLine = "			""" + NEWFlashPath  + """"
			Else 
				If (InStr(1,TextStreamLine,"REPLACE5", vbTextCompare) > 0) Then ' found 	
					StreamLine = "			""" + NewBuildToolsBinCompilerBinPath + """"
				Else
					StreamLine = Right(TextStreamLine, Len(TextStreamLine)-1) ' REM, so remove the 1st char
				End If 	
			End If			
    		objFile_Task.WriteLine(StreamLine) ' write the line
    	End If 	
    End If 
    If TextStreamLine = "' **Start of tasks.json**" Then State = StartFile1 End If 
    If TextStreamLine = "' *End of tasks.json**" Then State = StopFile1 End If 	
 Loop   
mytextstream.Close
objFile_Task.Close



' Enumerate Subfolders Using Recursion, find the .Vscode Sub Dir and copy the 2 files into this directory
ScanSubFolders FSO.GetFolder(CurrentPathValue) 
'
' Recursive calling this ...
'
Sub ScanSubFolders(Folder)
	For Each Subfolder in Folder.SubFolders ' goto all folders in the folder....
		' search for a "Makefile" in the current folder
		If FSO.FileExists(Subfolder.Path + "\" + MakefileFolderName) Then  'in this folder we need to create the ".VScode" SubDir because Makefile. exist
			If Not (FSO.FolderExists(Subfolder.Path + "\" + VSFolderName)) Then ' if the .VScode folder does NOT exist
				FSO.CreateFolder(Subfolder.Path + "\" + VSFolderName) ' create the folder
			End If 	
		Else
			If LCase(Right(CStr(Subfolder.Path),Len(VSFolderName)) = VSFolderName) Then  ' we found the Directory
			 	TargetFolder = Subfolder.Path ' Thats the Target Folder
		 		' copy both files to the folder - override if exist 
				FSO.CopyFile CurrentPathValueOriginal +"\" + File_CPP_Prop, TargetFolder + "\"
				FSO.CopyFile CurrentPathValueOriginal +"\" + File_Task, TargetFolder + "\"
			End If	
		End If	
	ScanSubFolders Subfolder ' call next folder level...
	Next
End Sub

Function ChekOSType()
	Set WshShell = WScript.CreateObject("WScript.Shell")
	Set WshSysEnv = WshShell.Environment("PROCESS")

	If WshSysEnv("ProgramFiles(x86)") = "" Then
  		OSType = "32Bit"
	Else
  		OSType = "64Bit"
	End If
	
End Function 

' Clean up and delet the createt source file in our local "root"
FSO.DeleteFile(File_Task)
FSO.DeleteFile(File_CPP_Prop)

' say Good Bye to the user !
WScript.Echo "PEAK-System ARM based Toolchain! - Finished - Thank you!"


' ***************************************************************************************************

'        Here are the Templates for the 2 json files "c_cpp_properties.json"  and  "tasks.json"
'              ! DO NOT Change any of this text if you not sure what you are doing !
' 
' ***************************************************************************************************
' **Start of c_cpp_properties.json**
'{
'    "configurations": [
'        { 
'            "name": "pcan-hw",
'            "includePath": [
'                "${workspaceRoot}/inc",
'				 "REPLACE1",
'				 "REPLACE2",
'				 "REPLACE3"
'            ],
'            "defines": [
'            ],
'            "intelliSenseMode": "clang-x64",
'            "browse": {
'                "path": [
'                    "${workspaceRoot}/inc",
'				 "REPLACE1",
'				 "REPLACE2",
'				 "REPLACE3"
'                ]
'                
'            }
'        }
'    ],
'    "version": 4
'}
' **End of c_cpp_properties.json**


' **Start of tasks.json**
'{
'    // See https://go.microsoft.com/fwlink/?LinkId=733558
'    // for the documentation about the tasks.json format
'    "version": "2.0.0",
'    "tasks": [
'        {
'            "label": "Flash Device",
'            "type": "shell",
'            "command": "PEAK-Flash.exe",
'            "options": {
'                "env": {
'                    "REPLACE4"
'                }
'            },
'            "presentation": {
'                "echo": true,
'                "reveal": "always",
'                "focus": false,
'                "panel": "shared"
'            },
'            "problemMatcher": []
'        },
'        {
'            "label": "Make Clean",
'            "type": "shell",
'            "command": "make clean",
'            "options": {
'                "env": {
'                    "REPLACE5"
'                }
'            },
'            "presentation": {
'                "echo": true,
'                "reveal": "always",
'                "focus": false,
'                "panel": "shared"
'            },
'            "group": "build",
'            "problemMatcher": "$gcc"
'        },
'        {
'            "label": "Make All",
'            "type": "shell",
'            "command": "make all",
'            "options": {
'                "env": {
'                    "REPLACE5"
'                }
'            },
'            "presentation": {
'                "echo": true,
'                "reveal": "always",
'                "focus": false,
'                "panel": "shared"
'            },
'            "group": {
'                "kind": "build",
'                "isDefault": true
'            },
'            "problemMatcher": "$gcc"
'        },
'        {
'            "label": "Compile File",
'            "type": "shell",
'            "command": "make singlefile SINGLE_FILE=${relativeFile}",
'            "options": {
'                "env": {
'                    "REPLACE5"
'                }
'            },
'            "presentation": {
'                "echo": true,
'                "reveal": "always",
'                "focus": false,
'                "panel": "shared"
'            },
'            "group": {
'                "kind": "build",
'                "isDefault": true
'            },
'            "problemMatcher": "$gcc"
'        },
'        {
'            "label": "Compile File ARM (ARM7 based hardware only)",
'            "type": "shell",
'            "command": "make singlefileARM SINGLE_FILE=${relativeFile}",
'            "options": {
'                "env": {
'                    "REPLACE5"
'                }
'            },
'            "presentation": {
'                "echo": true,
'                "reveal": "always",
'                "focus": false,
'                "panel": "shared"
'            },
'            "group": {
'                "kind": "build",
'                "isDefault": true
'            },
'            "problemMatcher": "$gcc"
'        }
'    ]
'}
' *End of tasks.json**

