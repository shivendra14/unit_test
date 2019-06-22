add_executable(
    TestApp 
    ../shared/doctest/doctest.h
    main.cpp
    )

target_include_directories(TestApp PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../shared/doctest")
target_link_libraries(TestApp PRIVATE DocTestLib)
target_link_libraries(TestApp PRIVATE Plugin) 