# use STATIC in place of SHARED to work with static libs
add_library(
    DocTestLib SHARED
    public/include/Config.hpp
    public/include/ImportExportMacros.hpp
    public/include/docTestLib.hpp
    source/docTestLib.cpp
    ../shared/doctest/doctest.h
)

target_include_directories(DocTestLib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/public/include")
target_include_directories(DocTestLib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/source")
target_include_directories(DocTestLib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../shared/doctest")

target_compile_definitions(DocTestLib PRIVATE __LIB_COMPONENT__=1)