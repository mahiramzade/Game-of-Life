cmake_minimum_required(VERSION 3.15)

project(game_of_life)

add_executable(${PROJECT_NAME} main.c)

add_subdirectory(console)
add_subdirectory(game)

target_include_directories(${PROJECT_NAME} PUBLIC console game)
target_link_directories(${PROJECT_NAME} PRIVATE console game)
target_link_libraries(${PROJECT_NAME} console game)
include_directories(console game)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)