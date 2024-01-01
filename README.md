# cutpproh

_The cutpproh header is a headerfile, which implements the functionality from the linux cut command for cpp._

## Table of contents

1. [Introduction](#introduction)
2. [Getting started](#getting-started)
    1. [Prerequisites](#prerequisites)
    2. [Installation](#installation)
3. [How to use](#how-to-use)
    1. [Compile the programm](#compile-the-programm)
    1. [How to import](#how-to-import)
    2. [Using the header](#using-the-header)
4. [License](/LICENSE)

## Introduction

I've written this headerfile to learn cpp and some cpp basics, like vectors, pointers, references and how headerfiles work. 

This header is inspired by the linux bash command.

The overall project contains 3 files:
- The headerfile [cutpproh.hpp](/src/cutpproh.hpp)
- The implementation file for the header [cutpproh.cpp](/src/cutpproh.cpp)
- The main file which can be compiled to run the programm.

## Getting started

### Prerequisites

- A compiler like gcc or g++
- IDE like VSCode and the right extensions (cpp,..) if you want to make adjustments

### Installation

If you want to use the headerfile inside your project type the following inside your terminal (requires git):

1. Using Powershell and git

```PS
# Powershell
# Creates a directory in your current directory
md cutpproh
# Change location to the created directory
cd cutpproh
# Pull necessary files
git pull https://github.com/IT-Administrators/cutpproh.git
```
2. Using Powershell without git

```PS
# Download zip archive using powershell
Invoke-WebRequest -Uri "https://github.com/IT-Administrators/cutpproh/archive/refs/heads/main.zip"
# Than expand archive
Expand-Archive -Path .\ArchiveName
```

After that you will find all project related files in the created directory. 

Than you can copy the headerfile and the implementation file to your project folder to use them. You don't need the main.cpp file.

Before using i would recommend compiling and testing the programm. You can find an instruction here: [Compile the programm](#compile-the-programm).

## How to use

### Compile the programm

I would recommend to compile the programm right after download, to see how it works. 
Depending on your chosen compiler the following snippet might look different.

You need to be in the src folder of the project to run the command otherwise you need to specify the full path name:
```
g++ .\main.cpp .\cutpproh.cpp -o cutpproh
```
After that you will find an .exe file there, called cutpproh.exe which you can run. 

### How to import

Using the headerfile in your project is quite easy. You can include it just like any other file. Depending on your projectstructure the include statement might look different.

In this example the headerfile is in the same directory as the main file.

```cpp 
// User defined header file.
#include "cutpproh.hpp"
```

### Using the header

To make the headerfile [cutpproh.hpp](/src/cutpproh.hpp) more flexible, i've created a namespace ```CutPpRoH``` which contains the class ```CutPp```. 

With this namespace, naming conflicts from other headerfiles are presumably rarer or will never occur.

Using the class inside your project works the following way. 

After importing the headerfile([How to import](#how-to-import)) you can use the class in two different ways:

1. Using directive
```cpp
// Using directive
// Imports the complete namespace
using namespace CutPpRoH;
int main() {
// Creating the teststring
std::string demostring = "This is a demonstration string."
// Creating an object of that class
CutPp strobj;
/* Calling method GetCharOnPos() 
The method returns the char on the specified position. For demonstration purposes the result is shown on stdout */
std::cout << strobj.GetCharOnPos(demostring,0) << endl;
}
```
Result:
```cpp
T
```
2. Without using directive
```cpp
int main() {
// Creating the teststring
std::string demostring = "This is a demonstration string."
// Creating an object of that class
CutPpRoH::CutPp strobj;
/* Calling method GetCharOnPos() 
The method returns the char on the specified position. For demonstration purposes the result is shown on stdout */
std::cout << strobj.GetCharOnPos(demostring,0) << endl;
}
```
Result:
```cpp
T
```
## License

[MIT](/LICENSE)