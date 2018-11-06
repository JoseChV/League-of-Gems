cmake_minimum_required(VERSION 3.12)
project(LeagueOfGems)

set(CMAKE_CXX_STANDARD 14)

add_executable(LeagueOfGems main.cpp)

target_link_libraries(LeagueOfGems -lmingw32 -lallegro-5.0.10-monolith-md-debug)