#include <iostream>
#include "plugin.hpp"

#define DOCTEST_CONFIG_IMPLEMENTATION_IN_DLL
#include "doctest.h"

void Plugin::SayHello()
{
    std::cout << "Hello from Plugin" << std::endl;
}

TEST_CASE("plugin") 
{
    CHECK(1 == 1);
    printf("I am a test from the plugin!\n");
}