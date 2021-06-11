cmake_minimum_required(VERSION 3.15)

project(game_of_life)

SET(IS_CLIPPED 0)

SET(DIST_NAME "${CMAKE_CURRENT_BINARY_DIR}/../${PROJECT_NAME}.tar.xz")
SET(HAVE_DOT "no")
SET(DOT_PATH "/usr/local/bin")

add_executable(${PROJECT_NAME} main.c)

add_subdirectory(gui)
add_subdirectory(game)

target_compile_definitions(${PROJECT_NAME} PRIVATE IS_CLIPPED=${IS_CLIPPED})

target_include_directories(${PROJECT_NAME} PUBLIC gui game)
target_link_directories(${PROJECT_NAME} PRIVATE gui game)
target_link_libraries(${PROJECT_NAME} gui game)
include_directories(gui game)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)

option(BUILD_DOC "Build documentation" ON)

find_package(SDL2 REQUIRED)
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})
include_directories(${SDL2_INCLUDE_DIRS})

find_package(Doxygen)
if (DOXYGEN_FOUND)
    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/./Doxyfile.conf)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
    message("Doxygen build started")

    add_custom_target( doc_doxygen ALL
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM )
else (DOXYGEN_FOUND)
  message("Doxygen need to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)

SET(DIST_FILES 
    "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}" 
    "${CMAKE_CURRENT_BINARY_DIR}/gui"
    "${CMAKE_CURRENT_BINARY_DIR}/game"
)

add_custom_target(dist ALL COMMAND
    ${CMAKE_COMMAND} -E tar "cfJ" ${DIST_NAME} ${DIST_FILES})
add_dependencies(dist ${PROJECT_NAME} gui game)
