# ApplicationStartupTime
A simple tool to measure Windows application (such as WinWord) startup time.

This sample code is associated with my blog post [Practical CPU time performance tuning for security software: Part 2](https://www.elastic.co/blog/practical-cpu-time-performance-tuning-for-security-software-part-2). 
It demonstrates how to measure an application's startup time on Windows. Assuming the application has an UI, the sample code measures the time between an application is invoked and when the application UI is fully ready for user interaction.


## To clone this repo:
```
git clone git@github.com:Trinity2019/WinWordStartupTime.git
```

## Build:
Open `AppStartupTime.sln` solution and build with `Microsoft Visual Studio`.

## Run the program in command prompt:
 * Measure WinWord startup time:
```
AppStartupTime.exe "C:\Program Files\Microsoft Office\root\Office16\WINWORD.EXE"
```
Note that in above command line, `"C:\Program Files\Microsoft Office\root\Office16\WINWORD.EXE"` is the path where WinWord executable is located in my environment. It may be different depending on installation locations. For the program to measure WinWord startup time correctly, you need to specify the path of `WINWORD.EXE` in your environment.
 * Measure other application's startup time:
```
AppStartupTime.exe [path/to/the/application/exe]
```
You can meaure other application's startup time using `AppStartupTime.exe` by specifying in command line the path of the application of your choice.

## Example output of the program:
```
Startup Time for C:\Program Files\Microsoft Office\root\Office16\WINWORD.EXE is: 265(ms)
```

Test environment:
A physical desktop machine with following specs:

CPU: Intel(R) Core(TM) i7-3770 CPU, 8 logical processors

OS: Windows 10 Pro 21H1

WinWord: Version 2106, downloaded and installed as part of Microsoft 365
