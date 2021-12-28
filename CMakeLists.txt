cmake_minimum_required(VERSION 3.20)
project(TowerDefence)

set(CMAKE_CXX_STANDARD 23)

find_package(SFML 2.5 COMPONENTS graphics audio)

add_subdirectory(googletest-master)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(TowerDefence main.cpp
                            src/Point/Point.h src/Point/Point.cpp
                            src/ObjectWithLocation/ObjectWithLocation.h src/ObjectWithLocation/ObjectWithLocation.cpp
                            src/ObjectWithHealth/ObjectWithHealth.h src/ObjectWithHealth/ObjectWithHealth.cpp
                            src/Table/CastleData/CastleData.h src/Table/CastleData/CastleData.cpp
                            src/Table/EnemyData/EnemyData.h src/Table/EnemyData/EnemyData.cpp
                            src/Table/TowerData/TowerData.h src/Table/TowerData/TowerData.cpp
                            src/Table/LairData/LairData.h src/Table/LairData/LairData.cpp
                            src/Table/Table.h
                            src/Enemy/Enemy.h src/Enemy/Enemy.cpp
                            src/Enemy/LightEnemy/LightEnemy.h src/Enemy/LightEnemy/LightEnemy.cpp
                            src/Castle/Castle.h src/Castle/Castle.cpp
                            src/Tower/Tower.h src/Tower/Tower.cpp
                            src/Loader/Loader.h src/Loader/Loader.cpp
                            src/Landscape/Landscape.h src/Landscape/Landscape.cpp

                            src/GameManager/GameManager.h src/GameManager/GameManager.cpp
                            src/Menu/Menu.h src/Menu/Menu.cpp src/CorrectInput/CorrectInput.h
                            src/Wall/Wall.h src/Wall/Wall.cpp
                            src/Enemy/HeavyEnemy/HeavyEnemy.h src/Enemy/HeavyEnemy/HeavyEnemy.cpp
                            src/Enemy/AirEnemy/AirEnemy.h src/Enemy/AirEnemy/AirEnemy.cpp test/test.cpp)

target_link_libraries(TowerDefence gtest gtest_main)
target_link_libraries(TowerDefence sfml-graphics sfml-audio)