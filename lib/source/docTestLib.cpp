#include <iostream>
#include "docTestLib.hpp"

#define DOCTEST_CONFIG_IMPLEMENTATION_IN_DLL
#define DOCTEST_CONFIG_IMPLEMENT
//#define DOCTEST_CONFIG_DISABLE //Disable all traces of unit-test
#include "doctest.h"

void DocTestLib::SayHello()
{
    std::cout << "Hello from DocTestLib" << std::endl;
}

TEST_CASE("DocTestLib") 
{
    CHECK(1 == 1);
    printf("I am a test from the DocTestLib!\n");
}