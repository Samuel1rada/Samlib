cmake_minimum_required(VERSION 3.0)
project(main C CXX)

# Set C++ standard to 11
set(CMAKE_CXX_STANDARD 11)

# Setting parameters for OpenGL
set(OpenGL_GL_PREFERENCE GLVND)

# Setting parameters for Raylib
set(BUILD_GAMES OFF CACHE BOOL "" FORCE)    # Disable building games

# Add Raylib as a subdirectory
add_subdirectory(libs/raylib)

####################################################################
# samlib Library                                                   #
####################################################################
add_library(samlib
    samlib/scene.cpp
    samlib/scene.h
    samlib/core.cpp
    samlib/core.h
    samlib/entity.cpp
    samlib/entity.h
    samlib/util.cpp
    samlib/util.h
)
target_link_libraries(samlib PRIVATE raylib)

####################################################################
# Include Directories                                              
####################################################################
# Add include directory for Raylib
include_directories(libs/raylib/src)

# Add include directory for samlib
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/samlib) 

####################################################################
# Main Executable                                                  
####################################################################
option(MAKE_START "Build start executable" ON)
if(MAKE_START)
    add_executable(start
        start/main.cpp
    )
    target_link_libraries(start PRIVATE samlib raylib) # Link with Raylib and samlib

    # Copy assets to the build directory
    file(
        COPY start/assets
        DESTINATION ${CMAKE_BINARY_DIR}
    )
endif()

####################################################################
# rts Executable                                                  
####################################################################
option(MAKE_RTS "Build rts executable" ON)
if(MAKE_RTS)
    add_executable(rts
        rts/main.cpp
        rts/myscene.cpp
        rts/myscene.h
        rts/mainbase.cpp
        rts/mainbase.h
        rts/node.cpp
        rts/node.h
        rts/unit.cpp 
        rts/unit.h
    )
    target_link_libraries(rts PRIVATE samlib raylib ) # Link with Raylib and samlib

    # Copy assets to the build directory
    file(
        COPY rts/assets
        DESTINATION ${CMAKE_BINARY_DIR}
    )
    file(
        COPY rts/map
        DESTINATION ${CMAKE_BINARY_DIR}
    )
endif()
# target_compile_definitions(${PROJECT_NAME} PUBLIC ASSETS_PATH="${CMAKE_CURRENT_SOURCE_DIR}/assets/") # Set the asset path macro to the absolute path on the dev machine
#target_compile_definitions(${PROJECT_NAME} PUBLIC ASSETS_PATH="relative-path-to-assets-in-the-game-package") # Set the asset path macro in release more
