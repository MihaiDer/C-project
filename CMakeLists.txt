cmake_minimum_required(VERSION 3.24)
project(play)

set(CMAKE_CXX_STANDARD 17)

add_executable(play main.cpp Domain/Cheltuiala.cpp Domain/Cheltuiala.h Tests/Tests.cpp Tests/Tests.h Repository/Repo.cpp Repository/Repo.h Service/Service.cpp Service/Service.h UI/UI.cpp UI/UI.h Repository/Undorepo.cpp Repository/Undorepo.h main.cpp)
