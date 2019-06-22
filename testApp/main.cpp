#include <iostream>
#include "docTestLib.hpp"

#define DOCTEST_CONFIG_IMPLEMENTATION_IN_DLL
#include "doctest.h"

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
DOCTEST_MAKE_STD_HEADERS_CLEAN_FROM_WARNINGS_ON_WALL_BEGIN
#include <windows.h>
DOCTEST_MAKE_STD_HEADERS_CLEAN_FROM_WARNINGS_ON_WALL_END
#ifdef _MSC_VER
#define LoadDynamicLib(lib) LoadLibrary(lib ".dll")
#else // _MSC_VER
#define LoadDynamicLib(lib) LoadLibrary("lib" lib ".dll")
#endif // _MSC_VER
#else // _WIN32
#include <dlfcn.h>
#ifdef __APPLE__
#define LoadDynamicLib(lib) dlopen("lib" lib ".dylib", RTLD_NOW)
#else // __APPLE__
#define LoadDynamicLib(lib) dlopen("lib" lib ".so", RTLD_NOW)
#endif // __APPLE__
#endif // _WIN32

//DOCTEST_SYMBOL_IMPORT void from_dll();

void ConfigDoctest(doctest::Context& context, int argc = 0, char const *argv[] = nullptr)
{
    //https://github.com/onqtam/doctest/blob/master/doc/markdown/configuration.md
    // !!! THIS IS JUST AN EXAMPLE SHOWING HOW DEFAULTS/OVERRIDES ARE SET !!!
    // defaults
    context.setOption("abort-after", 5);              // stop test execution after 5 failed assertions
    context.setOption("order-by", "name");            // sort the test cases by their name
    context.setOption("out", "DocTestAppOutput");
    context.setOption("duration", true);
    
    context.applyCommandLine(argc, argv);

    // overrides
    context.setOption("no-breaks", true);             // don't break in the debugger when assertions fail
}

int RunDocTest(doctest::Context& context)
{
    int res = context.run(); // run
    if(context.shouldExit()) // important - query flags (and --exit) rely on the user doing this
        return res;          // propagate the result of the tests
    return res;
}

int main(int argc, char const *argv[])
{
    LoadDynamicLib("Plugin"); // load the plugin so tests from it get registered

    doctest::Context context;
    ConfigDoctest(context, argc, argv);
    int testResult = RunDocTest(context);
    return 0 + testResult;
}

int factorial(int number) { return number <= 1 ? number : factorial(number - 1) * number; }

TEST_CASE("testing the factorial function") 
{
    printf("I am a test from the test app!\n");
    //std::cout << std::endl << "can setup here" << std::endl;
    SUBCASE("test cases here") 
    {
        //std::cout << "write test case as subcase" << std::endl;
        //CHECK(factorial(0) == 1);
        CHECK(factorial(1) == 1);
        CHECK(factorial(10) == 3628800);
    }
    //std::cout << std::endl << "can teardown here" << std::endl;
}
