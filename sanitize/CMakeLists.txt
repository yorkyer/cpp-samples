project(sanitize)

# May not use add_compile_options(-fsanitize=address)
# add_link_options(-fsanitize=address)
# add_executable(${PROJECT_NAME} main.cpp)
# target_link_libraries(${PROJECT_NAME})

# add_executable(${PROJECT_NAME} main.cpp)
# May not use target_compile_options(-fsanitize=address)
# Could use target_link_libraries(${PROJECT_NAME} PUBLIC -fsanitize=address)
# target_link_options(${PROJECT_NAME} PUBLIC -fsanitize=address)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fsanitize=leak")

add_executable(${PROJECT_NAME} main.cpp)