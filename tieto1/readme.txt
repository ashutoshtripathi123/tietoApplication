
Setup Information:
For development, Visual Studio Community 2017 has been used. During running, following error messages appeared. Please make following changes
to the project setting based upon the error message manifested. 
Error Code C1010 - Goto Project Properties -> C++ -> Precompiled Headers. set Precompiled Header to "Not Using Precompiled Header".
Error Code C1041 - in the C/C++->General settings page for project, set the Multi_processor compilation option to "No"
Error Code C4996 - Project properties -> Configuration Properties -> C/C++ -> General -> SDL checks -> No
> Set Project -> Properties -> General -> Character Set option to Use Multi-Byte Character Set

Using the Software:
After successful build, please edit the Command Argument field in Project Properties->Debugging->Command Argument and add in the following format:
<Path to the Project Directory><Space><Platform Name>
eg: C:\\Users\\212429464\\Documents\\my_docs\\tieto\\projects Windows

The software shall parse the provided directory structure, and print the common shared files between projects as per the requirement
The result is also available in file with name "Result.txt" present at the location passed in Command Line Argument.

Extensions For Supporting Different Platforms:
The idea behind passing the platform information in command line, is to support different implementations specific to platform. 
The presented solution, uses Windows specific API's, hence will not run in a Linux environment. The Algorithm responsible for storing the result,
processing it, and presenting the result is independent of the platform architecture, and has been decoupled from the logic responsible for 
parsing the filesystem. All that needs to be done is call the Result API after the filesystem has been parsed for the specified files,
the result module will handle the rest.

Multithreading of software:
Present implementation is designed to run linearly, however we can split the application in two threads, 
where one thread does the job of parsing filesystem right upto the end, and pass the result to the thread which can do the job 
of saving the result in internal maps and other data structures. For message passing message queues would be a suitable IPC mechanism.

Short Comings, and possible solution:
Present implementation supports identification of only files with extension *.c, *.h, *.cpp, *.rc
This can be extended through two techniques. One is to modify the code, i.e. listDir API of Windows class, and add the extensions we
wish to support further.The other approach will be config based, i.e. prepare a config file, stored at a predefined location, and let
the listDir API parse the file to check which all file extensions need to be supported further. This is a more recommended technique, as it does
not involve modifying the code everytime.