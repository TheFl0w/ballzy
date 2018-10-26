cmake_minimum_required(VERSION 3.11 FATAL_ERROR)
project(ballzy)
# --- visual studio workaround because it uses outdated cmake x.x
function(list)
    if (${CMAKE_VERSION} VERSION_LESS "3.12" 
            AND ${ARGV0} STREQUAL "TRANSFORM"
            AND ${ARGV2} STREQUAL "PREPEND")
        set(tmp "")
        foreach(item IN ITEMS ${${ARGV1}})
            list(APPEND tmp "${ARGV3}${item}")
        endforeach()
        set(${ARGV1} ${tmp} PARENT_SCOPE)
    else()
        _list(${ARGV})
        set(${ARGV1} ${${ARGV1}} PARENT_SCOPE)
    endif()
endfunction()
# --- library setup ---
set(ballzy_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include/ballzy)
set(ballzy_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/ballzy)
set(ballzy_HEADERS
    List.hpp
    Vector.hpp
)
set(ballzy_SOURCES
    List.cpp
    Vector.cpp
)
list(TRANSFORM ballzy_HEADERS PREPEND ${ballzy_INCLUDE_DIR}/)
list(TRANSFORM ballzy_SOURCES PREPEND ${ballzy_SOURCE_DIR}/)
add_library(ballzy ${ballzy_HEADERS} ${ballzy_SOURCES})
target_compile_features(ballzy PUBLIC cxx_std_17)
target_include_directories(ballzy PRIVATE ${ballzy_INCLUDE_DIR})
target_include_directories(ballzy INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)
# --- application setup ---
set(app_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(app_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(app_HEADERS
    main.hpp
)
set(app_SOURCES
    main.cpp
)
list(TRANSFORM app_HEADERS PREPEND ${app_INCLUDE_DIR}/)
list(TRANSFORM app_SOURCES PREPEND ${app_SOURCE_DIR}/)
add_executable(app ${app_HEADERS} ${app_SOURCES})
target_link_libraries(app ballzy)
target_compile_features(app PRIVATE cxx_std_17)
