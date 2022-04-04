# ninja-clean-failure
CMake project that illustrates the build | clean failure with Ninja on Windows

Includes a dependency to libwebsockets which causes a nested directory within the libwebsockets-build directory that ninja is unable to remove on clean.

Note* libwebsockets typically requires OpenSSL (or some SSL library) so you may need to install through chocolatey

Steps to reproduce:
1. Open project in CLion
2. Select Build | Build Project
3. Select Build | Clean

Expected:
- clean is successful

Actual:
Error in Build output window similar to,

```
====================[ Clean | Debug ]===========================================
"C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe" --build C:\Users\Scott\src\GITROOT\botscholar-scott\ninja-clean-failure\cmake-build-debug --target clean
[1/1] Cleaning all built files...
FAILED: clean 
C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\ninja\win\ninja.exe  -t clean 
Cleaning... ninja: error: remove(_deps/libwebsockets-build/include/libwebsockets): Permission denied
ninja: error: remove(C:/Users/Scott/src/GITROOT/botscholar-scott/ninja-clean-failure/cmake-build-debug/_deps/libwebsockets-build/include/libwebsockets): Permission denied
79 files.
ninja: build stopped: subcommand failed.
```



