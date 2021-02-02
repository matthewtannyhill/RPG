 
Pass Off Automator

This directory contains a setup that will help you to easilly check your code against the exact tests that we will run on it. You can still simply run the main and compare your output files, but we have found that there are often differences between out files created from Windows and Linux environments. The purpose of this directory is to help Windows users to easilly test their codes on a Linux environment and to help Linux and Mac users to quickly do likewise. If you pass these tests in a Linux environment, your code should pass off for the TA's. You do NOT need to use this if you do not want to. It is meant purely as an additional tool should you want to use it.
_________________________________________________________________________________________

Instructions:

1. Copy the "LabxPassoff" folder into a directory on the local Linux computer where x is the lab number. If you try to run the program from your flashdrive, it may not give you access. For simplicity we will assume you copy this folder into the Desktop directory.

2. Copy your student-made files (not the interface files and main) into the "src" folder.

3. Right-click on the "run.sh" executable and select "Properties." Once there, click on the "Permissions" tab and click on the box that says "Is executable." Click "OK."

4. Navigate a terminal to the "LabxPassoff" folder. You can either right-click in the folder in a file browser and select "Actions" -> "Open terminal here" or navigate to it manually. Some computers don't have the capability to do the first method so we will work through the second one. Open a terminal. On most Linux environments you can do this by either pressing CTRL-ALT-T or F12. Navigate to the pass off directory by typing in "cd Desktop/LabxPassoff" and pressing enter.

5. Run the script. To do this type "./run.sh" into the terminal and press enter.

6. The program will tell you in the terminal if you pass the tests and valgrind.
_________________________________________________________________________________________

Important Notes:

1. Valgrind will not be graded on all the labs so be sure to check the specs to see if you need to pass it. To pass valgrind the leak summary should show 0 bytes for all 5 types, except "still reachable," which should be 72,704" and error summary should show 0 errors.

2. The Railroad lab does not have test cases. It is up to you to come up with your own.

3. The Pathfinder lab does not have a key file 5. You must open the out_file5.txt to check that each maze is randomly generated and matches the requirements in the specs.

4. Please save a copy of your code elsewhere to avoid loss of data.

5. Feel free to change the test files for debugging purposes, but remember to change them back.

6. Don't forget to submit your UML!

7. You do NOT need to include this folder when you submit your lab. Only include the files that you created.