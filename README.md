# XRF
XRF is a small utility written for the Xbox One System OS. It's written to allow the retrieval of console information, experimentation and to take advantage of Win32 functionality.

### Prerequisites
- CMake (3.8 or greater)
- Visual Studio 2015/2017
- Windows 10 SDK (Preferably latest)
- Xbox One Devkit

### Compiling
It's important to note that debug builds will fail most of the time so it is best to always build with the release configuration as well as x64.

Generate a solution:
```
mkdir Build
cd Build
cmake ..\ -G "Visual Studio 15 2017 Win64"
```
Building:
```
cmake --build . --config Release
```
Example of generating and building:
```
mkdir Build
cd Build
cmake ..\ -G "Visual Studio 15 2017 Win64"
cmake --build . --config Release
```

### Deployment
There is a post-build command that will copy the executable to the console. You may need to update the hostname with your own consoles. Ensure that you already have established
a connection to the remote network share on the console beforehand.

### Usage
Printing basic console information
```
XRF cinfo
```
Printing current user of process
```
XRF whoami
```
Display contents of flash
```
XRF dispflash
```
Reading a specified filename from flash (Requires Administrator)
```
XRF readflash [filename] [destination]
```
Dumping flash raw (Requires Administrator)
```
XRF dumpflash [dumpname]
```

### Credit:
- emoose
- tuxuser
- gligli
