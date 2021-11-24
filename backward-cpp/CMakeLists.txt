project(backward-cpp)

set(BACKWARD_ENABLE ${CMAKE_SOURCE_DIR}/external/src/backward.cpp)

add_executable(${PROJECT_NAME} main.cpp ${BACKWARD_ENABLE})
target_link_libraries(${PROJECT_NAME} PRIVATE CONAN_PKG::backward-cpp)


# set(BACKWARD_ENABLE ${CMAKE_SOURCE_DIR}/external/src/backward.cpp)

# add_executable(${PROJECT_NAME} main.cpp ${BACKWARD_ENABLE})
# target_link_libraries(${PROJECT_NAME} PRIVATE unwind dw)

# backward.cpp: 
# // #define BACKWARD_HAS_DW 1
# =>
# #define BACKWARD_HAS_DW 1