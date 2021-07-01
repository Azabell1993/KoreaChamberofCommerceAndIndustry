# Install_Arduino_uno_Script-file
![arduino](https://user-images.githubusercontent.com/75885992/122888666-03058c00-d37d-11eb-9e87-c0507195653d.jpeg)


It is a script file for automating the installation of Arduino Uno, a learning board for Linux.  
  
Just follow the instructions below slowly.  
  
```c
./install.sh
```  
  
```C
$ ./install.sh 

Installing in /home/azabell/Desktop/Arduino_uno/bin
ARCH=64bit
OS=Linux
Using curl as download tool
TAG=0.18.3
CLI_DIST=arduino-cli_0.18.3_Linux_64bit.tar.gz
Downloading https://downloads.arduino.cc/arduino-cli/arduino-cli_0.18.3_Linux_64bit.tar.gz
An existing arduino-cli was found at /usr/bin/arduino-cli. Please prepend /home/azabell/Desktop/Arduino_uno/bin to your $PATH or remove the existing one.
arduino-cli alpha Version: 0.18.3 Commit: d710b642 Date: 2021-05-14T12:36:58Z installed successfully in /home/azabell/Desktop/Arduino_uno/bin
Arduino Command Line Interface (arduino-cli).

Usage:
  arduino-cli [command]

Examples:
  arduino-cli <command> [flags...]

Available Commands:
  board           Arduino board commands.
  burn-bootloader Upload the bootloader.
  cache           Arduino cache commands.
  compile         Compiles Arduino sketches.
  completion      Generates completion scripts
  config          Arduino configuration commands.
  core            Arduino core operations.
  daemon          Run as a daemon on port 50051
  debug           Debug Arduino sketches.
  help            Help about any command
  lib             Arduino commands about libraries.
  outdated        Lists cores and libraries that can be upgraded
  sketch          Arduino CLI sketch commands.
  update          Updates the index of cores and libraries
  upgrade         Upgrades installed cores and libraries.
  upload          Upload Arduino sketches.
  version         Shows version number of Arduino CLI.

Flags:
      --additional-urls strings   Comma-separated list of additional URLs for the Boards Manager.
      --config-file string        The custom config file (if not specified the default will be used).
      --format string             The output format, can be {text|json}. (default "text")
  -h, --help                      help for arduino-cli
      --log-file string           Path to the file where logs will be written.
      --log-format string         The output format for the logs, can be {text|json}.
      --log-level string          Messages with this level and above will be logged. Valid levels are: trace, debug, info, warn, error, fatal, panic
  -v, --verbose                   Print the logs on the standard output.

Use "arduino-cli [command] --help" for more information about a command.
--------------------------------------------------------------
-----------------------arduino-cli----------------------------
==============================================================
install the arduino-cli core install arduino:avr
Platform arduino:avr@1.8.3 already installed
==============================================================
install finish the these program. you can use the arduino uno program
--------------------------------------------------------------
you can see information about connect the arduino board : 
Port         Type              Board Name  FQBN            Core       
/dev/ttyACM0 Serial Port (USB) Arduino Uno arduino:avr:uno arduino:avr

  arduino-cli sketch new [skech name] 
just compile : arduino-cli compile -b [Board type] [project name]
just upload : arduino-cli upload -p [port] -b [Board type] [project name]
good luck!
```  

**If you finished, you can run next step.**  
**see you next step here.**  


**before execution**  
  
```c
$ ls
Arduino_uno.ino  install.sh  Makefile
```  

**after running**  
(added the bin folder. this is result about "curl -fsSL https://raw.githubusercontent.com/arduino/arduino-cli/master/install.sh | sh")  

```c
Arduino_uno.ino  bin  install.sh  Makefile 
```  

**Run the Makefile**  

```c
$ ./make
```  

you can modify at filename space, use the makefile.  

```c
FILENAME = Arduino_uno.ino
PORT = /dev/ttyACM0

upload:
	arduino-cli compile -b arduino:avr:uno arduino-cli_${FILENAME} -u -p ${PORT}
```  

  
    
**Basic blink source code**
```c
void setup()
{
  pinMode(13,OUTPUT);
}

void loop()
{
  digitalWrite(13, HIGH);
  delay(500);
  digitalWrite(13, LOW);
  delay(500);
}
```  
  

**Enjoy!**  

