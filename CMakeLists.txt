cmake_minimum_required(VERSION 3.30)
project(aptgutils C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED True)

add_library(${PROJECT_NAME} STATIC src/list.c src/dict.c src/linked_list.c)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/include)

install(TARGETS ${PROJECT_NAME} DESTINATION /usr/local/lib)
install(FILES src/include/blah.h DESTINATION /usr/local/include/aptgutils)

add_executable(${PROJECT_NAME}_example ${CMAKE_CURRENT_SOURCE_DIR}/examples/main.c)

target_link_libraries(${PROJECT_NAME}_example PRIVATE ${PROJECT_NAME})