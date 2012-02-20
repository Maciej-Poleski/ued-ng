include_directories(../../src/Core)

add_executable(core_test ConceptTest.cxx main.cxx TeacherTest.cxx)

set_target_properties(core_test PROPERTIES COMPILE_FLAGS "-std=c++0x")
target_link_libraries(core_test ${Boost_LIBRARIES} Core)
