add_executable(test-human
    human_test.cpp
)

target_link_libraries(test-human PRIVATE HUMAN_LIB)

target_include_directories(test-human
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../source
)