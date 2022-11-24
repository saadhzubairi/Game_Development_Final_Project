cmake_minimum_required(VERSION 3.23)
project(Game)

set(CMAKE_CXX_STANDARD 14)
set(SDL2_INCLUDE_DIR C:\\src\\SDL\\include)
set(SDL2_INCLUDE_DIR2 C:\\src\\SDL2_image-2.6.2\\include)
set(SDL2_INCLUDE_DIR3 C:\\src\\SDL2_ttf-2.20.1\\include)
set(SDL2_INCLUDE_DIR4 C:\\src\\SDL2_mixer-2.6.2\\include)

set(SDL2_LIB_DIR C:\\src\\SDL\\lib\\x86)
set(SDL2_LIB_DIR2 C:\\src\\SDL2_image-2.6.2\\lib\\x86)
set(SDL2_LIB_DIR3 C:\\src\\SDL2_ttf-2.20.1\\lib\\x86)
set(SDL2_LIB_DIR4 C:\\src\\SDL2_mixer-2.6.2\\lib\\x86)

include_directories(${SDL2_INCLUDE_DIR})
include_directories(${SDL2_INCLUDE_DIR2})
include_directories(${SDL2_INCLUDE_DIR3})
include_directories(${SDL2_INCLUDE_DIR4})

link_directories(${SDL2_LIB_DIR})
link_directories(${SDL2_LIB_DIR2})
link_directories(${SDL2_LIB_DIR3})
link_directories(${SDL2_LIB_DIR4})
add_executable(Game main.cpp Game.cpp Game.h Utilities/TextureManager.cpp Utilities/TextureManager.h Utilities/StaticObjects.cpp Utilities/StaticObjects.h Utilities/Track.cpp Utilities/Track.h GameObjects/GameObject.cpp GameObjects/GameObject.h GameObjects/Player/Mario.cpp GameObjects/Player/Mario.h)

target_link_libraries(${PROJECT_NAME} SDL2main SDL2 SDL2_image SDL2_ttf SDL2_mixer)
