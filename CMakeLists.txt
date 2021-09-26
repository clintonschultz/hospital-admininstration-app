cmake_minimum_required(VERSION 3.17)
project(HospitalAdminConsoleApp)

set(CMAKE_CXX_STANDARD 14)

add_executable(HospitalAdminConsoleApp main.cpp HospitalMethods.cpp Patient.cpp Patient.h CompareByPriority.cpp Logger.cpp Logger.h)