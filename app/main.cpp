#include <iostream>
#include "docTestLib.hpp"
#include "plugin.hpp"

#define DOCTEST_CONFIG_IMPLEMENTATION_IN_DLL
#include "doctest.h"

int main(int argc, char const *argv[])
{
    DocTestLib::SayHello();
    std::cout << "Hello from app!" <<std::endl;
    Plugin::SayHello();
    return 0;
}

TEST_CASE("App") 
{
    CHECK(1 == 1);
    printf("I am a test from the App!\n");
}