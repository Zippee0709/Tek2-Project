cmake_minimum_required(VERSION 3.0.0)
project(bomberman VERSION 0.1.0)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake) #Définit où trouver FindIrrlicht.cmake script
# A CMake module to find Irrlicht for the project B-YEP-400 IndieStudio
# ADD SRC for byuild project

# include(CTest)
# enable_testing()

message(${CMAKE_MODULE_PATH})

if (WIN32)
    message("The environment is WINDOWS")
    set(OS WINDOWS)
elseif(APPLE)
    message("The environment is APPLE")
    set(OS APPLE)
elseif(UNIX)
    message("The environment is LINUX")
    set(OS UNIX)
else()
    message("OS NOT SUPPORTED")
    set(OS NOT_SUPPORTED)
endif()

find_package(Irrlicht REQUIRED) # Utilise FindIrrlicht.cmake
find_package(SFML 2.5 COMPONENTS audio)
find_package(Boost REQUIRED)

if (Irrlicht_FOUND)
    include_directories(${Irrlicht_INCLUDE_DIRS})
endif()


set(pathProject ${CMAKE_CURRENT_SOURCE_DIR})

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/src/config.h.in ${CMAKE_CURRENT_SOURCE_DIR}/src/config.h)

ADD_EXECUTABLE(bomberman
    src/main.cpp
    src/core/Core.cpp
    src/menu/Menu.cpp
    src/core/Clock.cpp
    src/selectMenu/SelectMenu.cpp
    src/scene/Scene.cpp
    src/event/Event.cpp
    src/splashScreen/SplashScreen.cpp
    src/sound/Sound.cpp
    src/game/Game.cpp
    src/game/Bomb.cpp
    src/game/Map.cpp
    src/game/Item.cpp
    src/game/Player.cpp
    src/game/Entity.cpp
    src/save/Save.cpp
    src/inGameMenu/Pause.cpp
    src/option/Option.cpp
    src/endGame/GameOver.cpp
)

target_link_libraries (bomberman Irrlicht sfml-audio)
