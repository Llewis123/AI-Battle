cmake_minimum_required(VERSION 3.22)
project(M2OEP)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-deprecated -Wall")

# Must set the path to the main.cpp, for example: src/main.cpp if it is inside a folder
add_executable(${PROJECT_NAME} src/main.cpp src/build/MapDisplay.cpp src/build/MapDisplay.h
        src/framework/GamePlay.h src/framework/GamePlay.cpp
        src/build/Weapon.cpp src/build/Weapon.h
        src/build/Inventory.h src/build/Inventory.cpp
        src/framework/GameEngine.h src/framework/GameEngine.cpp)

find_package(Git REQUIRED)

set(BUILD_SHARED_LIBS OFF)

# --- SDL2 SETUP ---
if (NOT EXISTS lib/freetype/CMakeLists.txt)
    execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive -- ${dir}
            WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
            COMMAND_ERROR_IS_FATAL ANY)
endif ()

add_subdirectory(lib/freetype)
set(FREETYPE_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/lib/freetype/include)
set(FREETYPE_LIBRARY freetype)
include_directories(${FREETYPE_INCLUDE_DIRS})

add_subdirectory(lib/SDL)
add_subdirectory(lib/SDL_ttf)
add_subdirectory(lib/SDL_image)


include_directories(lib/SDL/include
        lib/SDL_image/include
        lib/SDL_ttf/include)


target_link_libraries(M2OEP
        ${SDL_LIBRARIES}
        ${SDL_IMAGE_LIBRARIES}
        ${SDL_TTF_LIBRARIES})


#add_subdirectory(lib/freetype)
#set(FREETYPE_INCLUDE_DIRS lib/freetype/include)
#set(FREETYPE_LIBRARIES freetype2)
#
#add_subdirectory(lib/SDL)
#set(SDL2_INCLUDE_DIRS lib/SDL2/include)
#set(SDL2_LIBRARIES SDL2-static)
#
#add_subdirectory(lib/SDL_image)
#set(SDL2_IMAGE_INCLUDE_DIRS lib/SDL2_image)
#set(SDL2_IMAGE_LIBRARIES SDL2_image)
#
#add_subdirectory(lib/SDL_ttf)
#set(SDL2_TTF_INCLUDE_DIRS lib/SDL2_ttf)
#set(SDL2_TTF_LIBRARIES SDL2_ttf)