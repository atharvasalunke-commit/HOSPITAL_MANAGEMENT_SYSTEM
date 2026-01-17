cmake_minimum_required(VERSION 3.15)
project(HospitalSystem)

set(CMAKE_CXX_STANDARD 17)


add_executable(hospital_app 
    main.cpp 
    sqlite3.c 
    auth.cpp 
    doctor.cpp 
    Patient.cpp 
    report.cpp 
    STAFF.cpp
)

# 2. THE INCLUDE PATH
# This tells VS to look in the current folder for .h files
target_include_directories(hospital_app PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
