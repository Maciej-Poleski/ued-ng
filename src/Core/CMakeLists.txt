set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.47.0 REQUIRED date_time serialization)

include_directories(${Boost_INCLUDE_DIRS})

add_library(Core ScheduleSourceManager.cxx GroupManager.cxx Report.cxx MarkPart.cxx Points.cxx Calendar.cxx ReportManager.cxx ScheduleSource.cxx Schedule.cxx SubjectSource.cxx TeacherManager.cxx Subject.cxx Group.cxx Category.cxx MarkCategory.cxx Teacher.cxx HoursOfTheDay.cxx DayOfTheWeek.cxx)

set_target_properties(Core PROPERTIES COMPILE_FLAGS "-std=c++0x")

target_link_libraries(Core ${Boost_LIBRARIES})
