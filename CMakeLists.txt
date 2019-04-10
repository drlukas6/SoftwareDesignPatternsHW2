cmake_minimum_required(VERSION 3.13)
project(2__Lab)

set(CMAKE_CXX_STANDARD 14)

add_executable(2__Lab main.cpp)
add_executable(0_Zadatak ProceduralStyle.cpp)
add_executable(1_Zadatak NoChangeUpgrade.c)
add_executable(2_Zadatak NoChangeUpgradeTemplates.cpp)
add_executable(4_Zadatak DistributionTester.cpp)
add_executable(5_Zadatak StreamObservers.cpp)

include_directories(Strategies Observables)