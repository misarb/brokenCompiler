cmake_minimum_required(VERSION 3.5)
project(brokenCompiler)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()



add_executable(bC src/main.cpp include/lexer/lexer.h src/lexer/lexer.cpp)

enable_testing()
add_subdirectory(test)


target_include_directories(bC PRIVATE include/
src/
)
install(TARGETS bC
  DESTINATION lib/${PROJECT_NAME})




