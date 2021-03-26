Welcome to the User Manual,

This shell was created by Imrich Toth for module CA216 Operating Systems.

Commands:
	'cd' - changes the directory.
	'clr' - clears the terminal.
	'dir' - lists contents of current directory.
	'environ' - lists all the environment strings.
	'echo' - displays whatever is typed after echo on a new line.
	'pause' - pauses operation of the shell until 'Enter' is pressed.
	'quit' - quits the shell

Batchfile:
* 	 Files can be run if a filename is provided in the command line argument:
* 		
* 	 An example use of this would be as follows: ./myshell <filename>
* 	
* 	 This will run any commands contained in the given file.


Environment Concepts:
* 	 My shell contains a commands that has the ability to list all my current environment variables, it is named 	  
 	 'environ' under the commands section above.
* 	 This variable is accesible by any user under any operatiny system that is logged in to my shell
* 	 This command stores specific system values that can help the system install other programs.


I/O redirection:
*    My understanding of I/O redirection is that it is a feature where the standard input and output are changed.
* 	 An example of this would be "ls > my_files"
* 	 Whats happening here is that a list will be redirected to my_files.


Description of the process concept, and the differences between background and foreground execution:
*    A background process is not visible to the user, it is independent to itself and is contained within the shell
* 	 Foreground exectuion consists of a command that you execute and wait for it to be completed
* 	 The difference is that a user can not do anything else while completing a foreground execution.


References:
* 	 Bryant, R. and O'Hallaron, D., 2003. Computer systems. Upper Saddle River, NJ: Prentice Hall, p.Processes.
* 	 Citatiion could not be complete for the following example article http://www.cs.rpi.edu/academics/courses/fall04/os/c4/index.html 
* 	 This article helped me understand how to use fork() and pid
* 	 The following web page helped me understand how to parse in C : https://c-for-dummies.com/blog/?p=1758
* 	 Brennan, S., 2015. Tutorial - Write a Shell in C. [online] Brennan.io. Available at: <https://brennan.io/2015/01/16/write-a-shell-in-c/>.
* 	 This final reference gave me a general understanding of how to write a shell in C, but specifically helped with running batchfiles.

	
Name: Imrich Toth
Student Number: 19307456
I consent to the DCU integrity policy, all the code and text written in this project was only done by me.
