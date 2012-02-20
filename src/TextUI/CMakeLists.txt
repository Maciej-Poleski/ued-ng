set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.47.0 REQUIRED date_time )

include_directories(${Boost_INCLUDE_DIRS})

add_library(TextUI HandleManager.cxx ScheduleSourceManager.cxx Schedule.cxx SubjectSource.cxx ScheduleSource.cxx TeacherManager.cxx Teacher.cxx)

set_target_properties(TextUI PROPERTIES COMPILE_FLAGS "-std=c++0x")

target_link_libraries(TextUI ${Boost_LIBRARIES})
