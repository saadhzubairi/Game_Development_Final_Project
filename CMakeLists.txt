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
add_executable(Game main.cpp Game.cpp Game.h Utilities/TextureManager.cpp Utilities/TextureManager.h Utilities/Track.cpp Utilities/Track.h GameObjects/GameObject.cpp GameObjects/GameObject.h GameObjects/Player/Mario.cpp GameObjects/Player/Mario.h Utilities/Field.cpp Utilities/Field.h Utilities/StaticObjects.cpp Utilities/StaticObjects.h GameObjects/ImmovableObjects/WallPiece.cpp GameObjects/ImmovableObjects/WallPiece.h StaticLists.cpp StaticLists.h Map.cpp Map.h UIElementsForGame/UIButtons.h UIElementsForGame/UIButtons.cpp UIElementsForGame/UILabel.h UIElementsForGame/UILabel.cpp GameObjects/ImmovableObjects/Door.cpp GameObjects/ImmovableObjects/Door.h GameObjects/ImmovableObjects/Button.cpp GameObjects/ImmovableObjects/Button.h GameObjects/MoveableObjects/Box.cpp GameObjects/MoveableObjects/Box.h GameObjects/ImmovableObjects/DoorH.cpp GameObjects/ImmovableObjects/DoorH.h GameObjects/MoveableObjects/Animal.cpp GameObjects/MoveableObjects/Animal.h GameObjects/MoveableObjects/Yarn.cpp GameObjects/MoveableObjects/Yarn.h GameObjects/MoveableObjects/Disperse.cpp GameObjects/MoveableObjects/Disperse.h GameObjects/MoveableObjects/Damage.cpp GameObjects/MoveableObjects/Damage.h GameObjects/ImmovableObjects/EvilCat.cpp GameObjects/ImmovableObjects/EvilCat.h UIElementsForGame/Screen.cpp UIElementsForGame/Screen.h Utilities/MusicController.cpp Utilities/MusicController.h)

target_link_libraries(${PROJECT_NAME} SDL2main SDL2 SDL2_image SDL2_ttf SDL2_mixer)
