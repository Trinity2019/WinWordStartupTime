# WinWordStartupTime
A simple tool to measure Windows application (such as WinWord) startup time.

This sample code is associated with my blog post [Practical CPU time performance tuning for security software: Part 2](https://www.elastic.co/blog/practical-cpu-time-performance-tuning-for-security-software-part-2). 
It demonstrates how to measure an application's startup time on Windows. You can find the definition of application startup time in the [blog](https://www.elastic.co/blog/practical-cpu-time-performance-tuning-for-security-software-part-2).


## To clone this repo:
```
git clone git@github.com:Trinity2019/WinWordStartupTime.git
```

## Build:
Open `AppStartupTime.sln` solution and build with `Microsoft Visual Studio`.

## Run the program in command prompt:
 * Measure WinWord startup time:
```AppStartupTime.exe "C:\Program Files\Microsoft Office\root\Office16\winword.exe"```
 * Measure other application's startup time:
```AppStartupTime.exe [path/to/the/application/exe]```

## Example output of the program:
```Startup Time for C:\Program Files\Microsoft Office\root\Office16\winword.exe is: 156(ms)
```

 * Test environment:
A physical desktop machine with following specs:
CPU: Intel(R) Core(TM) i7-3770 CPU, 8 logical processors
OS: Windows 10 Pro 21H1
WinWord: Version 2106, Download and installed as part of Microsoft 365