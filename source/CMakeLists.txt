add_subdirectory(executable)

add_library(HUMAN_LIB STATIC
    human.cpp
    human.h
)
target_include_directories(HUMAN_LIB PUBLIC .)