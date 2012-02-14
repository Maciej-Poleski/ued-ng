set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.47.0 COMPONENTS unit_test_framework)

if(${Boost_FOUND})
    include_directories(${Boost_INCLUDE_DIRS})
    add_definitions(-DBOOST_TEST_DYN_LINK)

    add_subdirectory(core)

endif(${Boost_FOUND})
