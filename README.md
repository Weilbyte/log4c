# log4c
C parody of the log4j RCE exploit (CVE-2021-44228)

Logs stuff to console, also happens to run ${expressions} for convenience :)

### Build instructions (with MinGW Makefiles generator)
Replace the generator with whatever you use
```
mkdir build
cd build
cmake .. -G "MinGW Makefiles"
cmake --build .
```




