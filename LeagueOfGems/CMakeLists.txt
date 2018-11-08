cmake_minimum_required(VERSION 3.12)
project(LeagueOfGems)

set(CMAKE_CXX_STANDARD 14)

add_executable(LeagueOfGems main.cpp Ally.cpp Ally.h Enemy.cpp Enemy.h GeneGenerator.cpp GeneGenerator.h SoldierList.cpp SoldierList.h SoldierNode.cpp SoldierNode.h Player.cpp Player.h Soldier.cpp Soldier.h SoldierManager.cpp SoldierManager.h)

target_link_libraries(LeagueOfGems -lmingw32 -lallegro-5.0.10-monolith-md-debug)