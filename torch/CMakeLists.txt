project(torch_example)

find_package(Torch REQUIRED PATHS ../external/libtorch)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE 
        "${TORCH_LIBRARIES}")
