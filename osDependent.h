#ifndef OSDEPENDENT_H
#define OSDEPENDENT_H

#include "asyncTasks.h"
#include "nobject.h"
#include "exception.h"
#include <string>
#include <algorithm>
#include <filesystem>

#if defined(_WIN32)
    #define NOMINMAX
    #define WIN32_LEAN_AND_MEAN
    #define _CRT_SECURE_NO_WARNINGS
    #pragma comment(linker, "/STACK:134217728")
    #include <Windows.h>
    #include <eh.h>
    using libraryType = HMODULE;
    #ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
        #define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
    #endif
#elif defined(__linux__)
    #include <cstdio>
    #include <sys/types.h>
    #include <unistd.h>
    #include <linux/limits.h>
    #include <dlfcn.h>
    using libraryType = void*;
#else
    #pragma message ("OS not fully supported")
    using libraryType = bool;
#endif

std::filesystem::path getExecutablePath();


void initialize();
void initializeThread();

#endif // OSDEPENDENT_H
