cmake_minimum_required(VERSION 3.30)
project(2dgame)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_CXX_STANDARD 20)

if (CMAKE_C_COMPILER_ID MATCHES "GNU")
    add_compile_options(-Wall -Wextra -Werror)
    add_compile_options(
            $<$<COMPILE_LANGUAGE:C>:-w>
    )
endif ()

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.0.0
        GIT_SHALLOW ON
        EXCLUDE_FROM_ALL
        SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(main src/main.cpp
        src/core/game.cpp
        include/game.hpp
        src/core/Player.cpp
        include/Player.hpp)
target_link_libraries(main PRIVATE SFML::Graphics SFML::Audio)

if (WIN32)
    add_custom_command(TARGET main POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_RUNTIME_DLLS:main>
            $<TARGET_FILE_DIR:main>
            COMMAND_EXPAND_LISTS
    )
endif()

# Copy assets to binary directory
add_custom_command(TARGET main POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/assets
        ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/assets
)

target_include_directories(main PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)