#include <iostream>
#include "docTestLib.hpp"
#include "plugin.hpp"

#define DOCTEST_CONFIG_IMPLEMENTATION_IN_DLL
#include "doctest.h"

int ConfigDoctest(int argc, char const *argv[])
{
    //https://github.com/onqtam/doctest/blob/master/doc/markdown/configuration.md
    doctest::Context context;

    // !!! THIS IS JUST AN EXAMPLE SHOWING HOW DEFAULTS/OVERRIDES ARE SET !!!
    // defaults
    context.setOption("abort-after", 5);              // stop test execution after 5 failed assertions
    context.setOption("order-by", "name");            // sort the test cases by their name

    context.applyCommandLine(argc, argv);

    // overrides
    context.setOption("no-breaks", true);             // don't break in the debugger when assertions fail
    int res = context.run(); // run
    if(context.shouldExit()) // important - query flags (and --exit) rely on the user doing this
        return res;          // propagate the result of the tests

    return res;
}

int main(int argc, char const *argv[])
{
    int testResult = ConfigDoctest(argc, argv);
    DocTestLib::SayHello();
    std::cout << "Hello from app!" <<std::endl;
    Plugin::SayHello();
    return 0 + testResult;
}

int factorial(int number) { return number <= 1 ? number : factorial(number - 1) * number; }

TEST_CASE("testing the factorial function") 
{
    printf("I am a test from the app!\n");
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
