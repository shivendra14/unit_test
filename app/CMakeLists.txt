add_executable(
    App 
    ../shared/doctest/doctest.h
    main.cpp
    )

target_include_directories(App PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../shared/doctest")
target_link_libraries(App PRIVATE DocTestLib)
target_link_libraries(App PRIVATE Plugin)