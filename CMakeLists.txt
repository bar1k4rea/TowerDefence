cmake_minimum_required(VERSION 3.20)
project(TowerDefence)

set(CMAKE_CXX_STANDARD 23)

find_package(SFML 2.5 COMPONENTS graphics audio)

include_directories(src/Table src/Table/CastleData src/Table/TowerData src/Table/EnemyData)

add_executable(TowerDefence main.cpp src/ObjectWithHealth/ObjectWithHealth.h src/ObjectWithHealth/ObjectWithHealth.cpp
        src/ObjectWithLocation/ObjectWithLocation.cpp src/ObjectWithLocation/ObjectWithLocation.h src/Enemy/Enemy.cpp
        src/Enemy/Enemy.h src/Table/Table.h src/Tower/Tower.cpp src/Tower/Tower.h
        src/Castle/Castle.cpp src/Castle/Castle.h src/Wall/Wall.cpp src/Wall/Wall.h src/Lair/Lair.cpp src/Lair/Lair.h
        src/Route/Route.cpp src/Route/Route.h src/Enemy/LightEnemy/LightEnemy.cpp src/Enemy/LightEnemy/LightEnemy.h
        src/Enemy/AirEnemy/AirEnemy.cpp src/Enemy/AirEnemy/AirEnemy.h src/Enemy/HeavyEnemy/HeavyEnemy.cpp
        src/Enemy/HeavyEnemy/HeavyEnemy.h src/Enemy/Aura/Aura.h src/Enemy/Hero/Hero.h src/Enemy/Hero/AirHero/AirHero.h
        src/Enemy/Hero/HeavyHero/HeavyHero.h src/Enemy/Hero/LightHero/LightHero.h src/Landscape/Landscape.h
        src/Table/CastleData/CastleData.h src/Table/EnemyData/EnemyData.h src/Table/TowerData/TowerData.h
        src/Table/CastleData/CastleData.cpp src/Table/TowerData/TowerData.cpp src/Table/EnemyData/EnemyData.cpp
        src/Enemy/EnemyType/EnemyType.h src/Enemy/Hero/Hero.cpp src/Enemy/Hero/AirHero/AirHero.cpp
        src/Enemy/Hero/HeavyHero/HeavyHero.cpp src/Enemy/Hero/LightHero/LightHero.cpp src/Loader/Loader.cpp
        src/Loader/Loader.h src/Cell/Cell.cpp src/Cell/Cell.h src/Menu/Menu.cpp src/Menu/Menu.h src/GameManager/GameManager.cpp src/GameManager/GameManager.h src/Landscape/Landscape.cpp)

#add_executable(TowerDefence main.cpp src/Table/Table.h src/Table/CastleData/CastleData.h
#        src/Table/CastleData/CastleData.cpp src/Table/TowerData/TowerData.h src/Table/TowerData/TowerData.cpp
#        src/Table/EnemyData/EnemyData.h src/Table/EnemyData/EnemyData.cpp src/Loader/Loader.cpp src/Loader/Loader.h
#        src/Cell/Cell.cpp src/Cell/Cell.h)

target_link_libraries(TowerDefence sfml-graphics sfml-audio)