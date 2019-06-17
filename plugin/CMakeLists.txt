# use STATIC in place of SHARED to work with static libs
add_library(
    Plugin SHARED
    public/include/Config.hpp
    public/include/ImportExportMacros.hpp
    public/include/plugin.hpp
    source/plugin.cpp
    ../shared/doctest/doctest.h
)

target_include_directories(Plugin PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/public/include")
target_include_directories(Plugin PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/source")
target_include_directories(Plugin PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../shared/doctest")

target_compile_definitions(Plugin PRIVATE __LIB_COMPONENT__=1)

target_link_libraries(Plugin PRIVATE DocTestLib)