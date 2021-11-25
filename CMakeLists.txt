cmake_minimum_required(VERSION 3.20)
project(TowerDefence)

set(CMAKE_CXX_STANDARD 23)

add_executable(TowerDefence main.cpp src/ObjectWithHealth/ObjectWithHealth.h src/ObjectWithHealth/ObjectWithHealth.cpp
        src/ObjectWithLocation/ObjectWithLocation.cpp src/ObjectWithLocation/ObjectWithLocation.h src/Enemy/Enemy.cpp
        src/Enemy/Enemy.h src/Table/Table.cpp src/Table/Table.h src/Tower/Tower.cpp src/Tower/Tower.h
        src/Castle/Castle.cpp src/Castle/Castle.h src/Wall/Wall.cpp src/Wall/Wall.h src/Lair/Lair.cpp src/Lair/Lair.h
        src/Route/Route.cpp src/Route/Route.h src/Enemy/LightEnemy/LightEnemy.cpp src/Enemy/LightEnemy/LightEnemy.h
        src/Enemy/AirEnemy/AirEnemy.cpp src/Enemy/AirEnemy/AirEnemy.h src/Enemy/HeavyEnemy/HeavyEnemy.cpp
        src/Enemy/HeavyEnemy/HeavyEnemy.h src/Enemy/Aura/Aura.h src/Enemy/Hero/Hero.h src/Enemy/Hero/AirHero/AirHero.h
        src/Enemy/Hero/HeavyHero/HeavyHero.h src/Enemy/Hero/LightHero/LightHero.h src/Landscape/Landscape.h)
