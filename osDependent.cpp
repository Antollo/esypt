#include "osDependent.h"

std::filesystem::path getExecutablePath()
{
    static std::string ret;
    if (!ret.empty()) return ret;
    #if defined(_WIN32)
        char result[MAX_PATH];
        ret = std::string(result, GetModuleFileName(NULL, result, MAX_PATH ));
    #elif defined(__linux__)
        char result[PATH_MAX];
        ssize_t length = readlink( "/proc/self/exe", result, PATH_MAX );
        ret = std::string( result, (length > 0) ? length : 0 );
    #else
        return "";
    #endif
    return ret;
}


#if defined(_WIN32)
void translateSEH(unsigned int u, EXCEPTION_POINTERS* exceptionPtr)
{
    std::string name = [&u](){
        switch(u) {
            case EXCEPTION_ACCESS_VIOLATION:            return "EXCEPTION_ACCESS_VIOLATION"         ;
            case EXCEPTION_ARRAY_BOUNDS_EXCEEDED:       return "EXCEPTION_ARRAY_BOUNDS_EXCEEDED"    ;
            case EXCEPTION_BREAKPOINT:                  return "EXCEPTION_BREAKPOINT"               ;
            case EXCEPTION_DATATYPE_MISALIGNMENT:       return "EXCEPTION_DATATYPE_MISALIGNMENT"    ;
            case EXCEPTION_FLT_DENORMAL_OPERAND:        return "EXCEPTION_FLT_DENORMAL_OPERAND"     ;
            case EXCEPTION_FLT_DIVIDE_BY_ZERO:          return "EXCEPTION_FLT_DIVIDE_BY_ZERO"       ;
            case EXCEPTION_FLT_INEXACT_RESULT:          return "EXCEPTION_FLT_INEXACT_RESULT"       ;
            case EXCEPTION_FLT_INVALID_OPERATION:       return "EXCEPTION_FLT_INVALID_OPERATION"    ;
            case EXCEPTION_FLT_OVERFLOW:                return "EXCEPTION_FLT_OVERFLOW"             ;
            case EXCEPTION_FLT_STACK_CHECK:             return "EXCEPTION_FLT_STACK_CHECK"          ;
            case EXCEPTION_FLT_UNDERFLOW:               return "EXCEPTION_FLT_UNDERFLOW"            ;
            case EXCEPTION_ILLEGAL_INSTRUCTION:         return "EXCEPTION_ILLEGAL_INSTRUCTION"      ;
            case EXCEPTION_IN_PAGE_ERROR:               return "EXCEPTION_IN_PAGE_ERROR"            ;
            case EXCEPTION_INT_DIVIDE_BY_ZERO:          return "EXCEPTION_INT_DIVIDE_BY_ZERO"       ;
            case EXCEPTION_INT_OVERFLOW:                return "EXCEPTION_INT_OVERFLOW"             ;
            case EXCEPTION_INVALID_DISPOSITION:         return "EXCEPTION_INVALID_DISPOSITION"      ;
            case EXCEPTION_NONCONTINUABLE_EXCEPTION:    return "EXCEPTION_NONCONTINUABLE_EXCEPTION" ;
            case EXCEPTION_PRIV_INSTRUCTION:            return "EXCEPTION_PRIV_INSTRUCTION"         ;
            case EXCEPTION_SINGLE_STEP:                 return "EXCEPTION_SINGLE_STEP"              ;
            case EXCEPTION_STACK_OVERFLOW:              _resetstkoflw();
                                                        return "EXCEPTION_STACK_OVERFLOW"           ;
            default: return "UNKNOWN EXCEPTION" ;
       }
    }();
    throw Unknown("Win32 exception " + name);
}
#endif

void initialize()
{
    //std::ios_base::sync_with_stdio(false);
    std::cout << std::boolalpha;
    asyncTasks::registerThisThread();
    initializeThread();
    #if defined(_WIN32)
    
    //Colors in console
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE)
    {
        return;
    }
    DWORD dwMode = 0;
    if (!GetConsoleMode(hOut, &dwMode))
    {
        return;
    }
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    if (!SetConsoleMode(hOut, dwMode))
    {
        return;
    }
    #endif
}

void initializeThread()
{
    #if defined(_WIN32)

    //Handle structured exceptions
    _set_se_translator(translateSEH);

    //Prevent stack overflow
    ULONG_PTR lowLimit;
    ULONG_PTR highLimit;
    GetCurrentThreadStackLimits(&lowLimit, &highLimit);
    static ULONG size = (highLimit - lowLimit)/32*29;
    SetThreadStackGuarantee(&size);
    #endif
}
