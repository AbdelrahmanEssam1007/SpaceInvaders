cmake_minimum_required(VERSION 3.31)
project(SpaceInvaders)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 26)

set(RAYLIB_VERSION 5.5)
find_package(raylib ${RAYLIB_VERSION} QUIET) # QUIET or REQUIRED
if (NOT raylib_FOUND) # If there's none, fetch and build raylib
  include(FetchContent)
  FetchContent_Declare(
          raylib
          DOWNLOAD_EXTRACT_TIMESTAMP OFF
          URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
  )
  FetchContent_GetProperties(raylib)
  if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
    set(FETCHCONTENT_QUIET NO)
    FetchContent_MakeAvailable(raylib)
    set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
  endif ()
endif ()

# Set the output directory for the executable
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

add_executable(SpaceInvaders src/main.cpp 
        src/game/Game.cpp 
        src/game/entities/SpaceShip.cpp 
        src/game/entities/Laser.cpp
)

target_link_libraries(${PROJECT_NAME} raylib)

if (MSVC)
  # MSVC-specific settings
  set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /DEBUG:FALSE")
  set(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} /NODEBUG")
  message(STATUS "Compiling with MSVC")
else ()
  # Non-MSVC compilers (e.g., GCC, Clang)
  message(STATUS "Compiling with a non-MSVC compiler")
  # You can add specific flags for GCC/Clang here if needed
endif ()

