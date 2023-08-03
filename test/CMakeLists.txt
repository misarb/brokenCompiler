# The tests are based on the GTEST framework
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.12.1
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Include fmt/fmtlib as a dependency
include(FetchContent)
FetchContent_Declare(
  fmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt.git
  GIT_TAG        9.1.0
)
FetchContent_MakeAvailable(fmt)

file(GLOB TEST_SOURCES "testCompiler/*.cpp" "testCompiler/*/*.cpp")

# List all source files here
file(GLOB SOURCES
    code_generation/*.cpp
    lexer/*.cpp
    lexer/lexer.cpp  # Add this line
    main.cpp
    parser/*.cpp
    semantic_analysis/*.cpp
)

# add_executable(
#   ${PROJECT_NAME}_test
#   ${TEST_SOURCES}
# )
add_executable(${PROJECT_NAME}_test
    ${TEST_SOURCES}
    ../src/lexer/lexer.cpp  
)

if (ENABLE_COVERAGE)
  list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/../cmake-modules)
  include(CodeCoverage)
  append_coverage_compiler_flags_to_target(${PROJECT_NAME}_test)

  setup_target_for_coverage_lcov(
    NAME ctest_coverage
    EXECUTABLE ctest -j ${PROCESSOR_COUNT}
    DEPENDENCIES ${PROJECT_NAME}_test
    NO_DEMANGLE
  )
endif()

# Include src such that we can #include <src/*> in the sources
target_include_directories(${PROJECT_NAME}_test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)

target_link_libraries(
  ${PROJECT_NAME}_test
  PRIVATE
  gtest_main
  fmt::fmt
)

# Enable CMAKE's test runner to discover tests
include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}_test)