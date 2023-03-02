cmake_minimum_required(VERSION 3.0)

project(hello_string)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(${PROJECT_NAME}
  main.cpp
)

target_link_libraries(${PROJECT_NAME}
  pspdebug
  pspdisplay
  pspge
)

create_pbp_file(
    TARGET ${PROJECT_NAME}
    ICON_PATH NULL
    BACKGROUND_PATH NULL
    PREVIEW_PATH NULL
    TITLE ${PROJECT_NAME}
)
